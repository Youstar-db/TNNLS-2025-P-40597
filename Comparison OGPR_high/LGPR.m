classdef LGPR
    properties
        M % 模型数量（局部模型个数）
        N_max % 每个模型最大样本数
        clusters % cell{1,M}, 每个元素包含结构体：X, Y, center, L, beta
        lambda % 核函数的尺度参数向量
        sigma_f % 核函数输出方差
        sigma_n % 噪声标准差
        output_dim
        input_dim
        similarity_threshold
    end

    methods
        function obj = LGPR(input_dim, output_dim, N_max, lambda, sigma_f, sigma_n)
            obj.M = 0;
            obj.N_max = N_max;
            %obj.lambda = lambda;
            obj.lambda = lambda;
            obj.sigma_f = sigma_f;
            obj.sigma_n = sigma_n;
            obj.input_dim = input_dim;
            obj.output_dim = output_dim;
            obj.clusters = {};
            obj.similarity_threshold = 0.25;
        end

        function [y_pred, var_pred] = predict(obj, x)
            w = zeros(1, obj.M);
            y_all = zeros(obj.output_dim, obj.M);
            var_all = zeros(obj.output_dim, obj.M);

            for j = 1:obj.M
                c = obj.clusters{j}.center;
                w(j) = obj.kernel(x, c);
                [y_tmp, v_tmp] = obj.gpr_predict(obj.clusters{j}, x);
                y_all(:, j) = y_tmp;
                var_all(:, j) = v_tmp;
            end

            if sum(w) == 0
                y_pred = zeros(obj.output_dim, 1);
                var_pred = ones(obj.output_dim, 1) * 1e5;
            else
                w = w / sum(w);
                y_pred = y_all * w';
                var_pred = var_all * w';
            end
        end

        function obj = update(obj, x, y)
            % 查找最相似的模型
            max_sim = -inf; max_idx = -1;
            for j = 1:obj.M
                sim = obj.kernel(x, obj.clusters{j}.center);
                if sim > max_sim
                    max_sim = sim;
                    max_idx = j;
                end
            end

            % 若相似度低于阈值，创建新模型
            if max_sim < obj.similarity_threshold
                obj.M = obj.M + 1;
                j = obj.M;
                cluster.X = x;
                cluster.Y = y;
                cluster.center = x;
                [cluster.L, cluster.beta] = obj.gpr_init(x, y);
                obj.clusters{j} = cluster;
                return;
            end

            % 否则更新已有模型
            cluster = obj.clusters{max_idx};

            if size(cluster.X, 1) >= obj.N_max
                % 超过容量，回滚为重新初始化
                cluster.X(1,:) = [];
                cluster.Y(1,:) = [];
                cluster.X = [cluster.X; x];
                cluster.Y = [cluster.Y; y];
                cluster.center = mean(cluster.X, 1);
                [cluster.L, cluster.beta] = obj.gpr_init(cluster.X, cluster.Y);
            else
                % 增量更新
                cluster.X = [cluster.X; x];
                cluster.Y = [cluster.Y; y];
                cluster.center = mean(cluster.X, 1);
                [cluster.L, cluster.beta] = obj.gpr_update(cluster, x, y);
            end

            obj.clusters{max_idx} = cluster;
        end

        function [L, beta] = gpr_init(obj, X, Y)
            N = size(X,1);
            K = obj.kernel_matrix(X, X);
            L = chol(K + obj.sigma_n^2 * eye(N), 'lower');
            beta = L' \ (L \ Y);
        end

        function [L_new, beta_new] = gpr_update(obj, cluster, x_new, y_new)
            X_old = cluster.X(1:end-1, :);  % 不含新样本
            Y_old = cluster.Y(1:end-1, :);
            L_old = cluster.L;
            beta_old = cluster.beta;

            % 新数据相关核计算
            k = obj.kernel_matrix(X_old, x_new);   % (N-1) × 1
            k_ss = obj.kernel(x_new, x_new) + obj.sigma_n^2;

            % 增量更新 Cholesky
            v = L_old \ k;
            r = sqrt(k_ss - v' * v);

            L_new = [L_old, zeros(size(L_old,1),1); v', r];

            % 更新 beta
            Y_new = [Y_old; y_new];
            beta_new = L_new' \ (L_new \ Y_new);
        end

        function [y_pred, var_pred] = gpr_predict(obj, cluster, x_star)
            X = cluster.X;
            Y = cluster.Y;
            L = cluster.L;
            beta = cluster.beta;

            k_star = obj.kernel_matrix(X, x_star);
            k_ss = obj.kernel(x_star, x_star);

            y_pred = k_star' * beta;
            v = L \ k_star;
            var_pred = diag(k_ss - v' * v);
        end

        function K = kernel_matrix(obj, X1, X2)
            dist2 = pdist2(X1, X2, 'squaredeuclidean');
            K = obj.sigma_f^2 * exp(-0.5 * dist2 / obj.lambda^2);
        end

        function k = kernel(obj, x1, x2)
            d = (x1 - x2).^2;
            k = obj.sigma_f^2 * exp(-0.5 * sum(d) / obj.lambda^2);
        end
    end
end
