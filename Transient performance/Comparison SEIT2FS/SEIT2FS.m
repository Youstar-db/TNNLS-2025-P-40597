classdef SEIT2FS
    % description: self-evolving interval type-2 fuzzy system
    % Author: suqy
    % version: MATLAB R2020a
    % Modified date: 2024/4/2 (version:X-X-X)
    properties(Constant)
        P_INIT = 1000000 % controlled parameter standard for covariance matrix initialisation used by the LWRLS algorithms
        LAMADA = 0.85 % forgetting factor for cumulative error
        SIGMA_INIT = 0.1
        UNCERTAINTY_INIT = 0.01
        ETA = 0.01;
        M = 6 % output numbers
        % test
        GENERATE = 0.00005;
        MERG = 0.95;
        PRUNE = 0.001;
        TEST = 1;  %2--fixed
        XXX = 1;
        % test
    end
    properties
        Center % Gaussian MFs center
        Sigma %  Gaussian MFs width
        Num_Rule %
        Num_Clusters %
        Age %
        Utility %
        W % consequent parameters
        P % covariance matrix
        Error % online training absolute error
        Cumulative_Error % cumulative online training absolute error
        q_error
        generate
        merg
        prune

    end
    methods
        function obj = SEIT2FS(xn, yn) %xn = 1 * n; yn = 1 * n
            % description: Rule initialization phase
            % Input:
            %        xn:
            %        yn:
            % Returns:
            %    obj: Rule-base(struct)
            obj.Center(:, :, 1) = xn - SEIT2FS.UNCERTAINTY_INIT * SEIT2FS.SIGMA_INIT; % center_left initialization
            obj.Center(:, :, 2) = xn + SEIT2FS.UNCERTAINTY_INIT * SEIT2FS.SIGMA_INIT; % center_right initialization
            obj.Sigma =  SEIT2FS.SIGMA_INIT * ones(size(xn)); % sigma initialization
            obj.Num_Rule = 1;
            obj.Num_Clusters = 0;
            obj.Age = 0;
            obj.Utility = 0;
            xe = [1 xn];
            obj.W = zeros(SEIT2FS.M, length(xe), 1); % consequent parameters initialization m*n
            obj.P = zeros([size(xe' * xe), 1]); % n+1*n+1*rule_num
            obj.P(:, :, 1) = SEIT2FS.P_INIT * eye(length(xe' * xe)); % weight matrix initialization
            [obj.W, obj.P] = LWRLS(obj, xn, yn); % Local Weight recursive least square method(LWRLS)
            y_pre = output_calculation(obj, xn);
            obj.Error = norm(yn - y_pre);
            obj.q_error = 0;
            obj = antecedent_parameters_learning(obj, xn, obj.Error);
            obj.Cumulative_Error = 0; % accumulated_error
        end

        function [obj, y_pre] = rule_evolve(obj, xn, yn, error)
            % description: Rule evolution process
            % Input:
            %        obj: Rule-base(struct)
            %        xn:
            %        yn:
            % Returns:
            %    obj: Rule-base(struct)
            %    y_pre: Prediction output
            y_pre = output_calculation(obj, xn);
            obj.Error = norm(yn - y_pre);
            obj.Cumulative_Error = SEIT2FS.LAMADA * obj.Cumulative_Error + obj.Error/1000; %/10.5
            obj.q_error = norm(error);
            % threshold update
            obj = threshold_update(obj);
            [~, firing_mean] = firing_strength_calculation(obj, xn);
            i_max = find(firing_mean == max(firing_mean));
            i_max = i_max(1);
            objold=obj;
            error_old = obj.Error;
            if(firing_mean(i_max(1)) < obj.generate && obj.Num_Rule <= 50)
                % rule generation
                obj = rule_generate(obj, xn, yn);
            else
                % rule update
                obj = rule_update(obj, xn);
                % rule merg
                [~, firing_mean] = firing_strength_calculation(obj, xn);
                firing_mean(i_max) = 0;
                j_max = find(firing_mean == max(firing_mean)); % Find the second highest firing strength value
                j_max = j_max(1);
                if(i_max ~= j_max)
                    similarity = similarity_measure(obj, i_max(1), j_max);
                    firing_1 = firing_mean(j_max);
                    [~, firing_mean] = firing_strength_calculation(obj, mean(obj.Center(j_max, :, :), 3));
                    firing_2 = firing_mean(i_max);
                    if(similarity > obj.merg && obj.Num_Rule > 1)
                    %if(similarity > obj.merg && firing_1 >exp(-9/2)&& firing_2 >exp(-9/2) && obj.Num_Rule>2)
                        obj = rule_merg(obj, i_max, j_max, 1);
                        obj.Num_Rule = obj.Num_Rule - 1;
                    end
                end
                % rule prune
                [~, firing_mean] = firing_strength_calculation(obj, xn);
                obj.Utility = (obj.Utility .* obj.Age + firing_mean)./ (obj.Age + 1);
                i_min = find(obj.Utility == min(obj.Utility));
                i_min = i_min(1);
                if(obj.Utility(i_min) < obj.prune && obj.Num_Rule > 2)
%                     [~, firing_mean] = firing_strength_calculation(obj, mean(obj.Center(i_min, :, :), 3));
%                     firing_mean(i_min) = 0;
%                     j_prune = find(firing_mean == max(firing_mean));
%                     j_prune = j_prune(1);
%                         obj.Center(i_min, :, :)=[];
%                         obj.Sigma(i_min, :)=[];
%                         obj.Num_Clusters(i_min)=[];
%                         obj.W(:, :, i_min)=[];
%                         obj.P(:, :, i_min)=[];
%                         obj.Utility(i_min)=[];
%                         obj.Age(i_min)=[];
%                         obj.Num_Rule = obj.Num_Rule - 1;
% %                     end
                end
                [obj.W, obj.P] = LWRLS(obj, xn, yn);
                y_pre = output_calculation(obj, xn);
                obj.Error = norm(yn - y_pre);
                obj = antecedent_parameters_learning(obj, xn, obj.Error);
                y_pre_new = output_calculation(obj, xn);
                error_new = norm(yn - y_pre_new);
            end
            obj.Age = obj.Age + 1;
        end
        function obj = rule_generate(obj, xn, yn)
            % description: rule generation phase
            % Input:
            %        obj: Rule-base(struct)
            %        xn:
            %        yn:
            %        threshold: Rule generation threshold
            % Returns:
            %    obj: Rule-base(struct)
            obj.Error = 0;
            obj.Cumulative_Error = 0;
            obj.q_error = 0;
            obj.Num_Rule = obj.Num_Rule + 1;
            obj.Utility = [obj.Utility; 1];
            obj.Age = [obj.Age; 1];
            xe = [1 xn];
            [~, firing_mean] = firing_strength_calculation(obj, xn);
            i_max = find(firing_mean == max(firing_mean));
            i_max = i_max(1);
            %sigma_temp = zeros(1,length(xn));
            %sigma_temp = max( [SEIT2FS.SIGMA_INIT*ones(size(xn)); norm(xn - mean(obj.Center(i_max, :, :), 3))/ sqrt(-2 * log(obj.generate))*ones(size(xn))]);
            sigma_temp = max( [SEIT2FS.SIGMA_INIT*ones(size(xn)); 0.5 * abs(xn - mean(obj.Center(i_max, :, :), 3))]);
            xn_range = SEIT2FS.UNCERTAINTY_INIT * sigma_temp;
            %xn_range = 0.5;
            Center_temp = cat(3, xn - xn_range, xn + xn_range);
            obj.Center = [obj.Center; Center_temp];
            obj.Sigma = [obj.Sigma; sigma_temp];
            obj.Num_Clusters = [obj.Num_Clusters; 1];
            obj.P(:, :, size(obj.Center, 1)) = SEIT2FS.P_INIT * eye(length(xe' * xe));
            obj.W(:, :, size(obj.Center, 1)) = mean(obj.W(:, :,:), 3); %the new rule's consequent parameters is the average value of all existing rule consequents
            [obj.W, obj.P] = LWRLS(obj, xn, yn);
            y_pre = output_calculation(obj, xn);
            obj.Error = norm(yn - y_pre);
            obj = antecedent_parameters_learning(obj, xn, obj.Error);
        end
        function obj = rule_update(obj, xn)
            % description: rule update phase
            % Input:
            %        obj: Rule-base(struct)
            %        xn:
            % Returns:
            %    obj: Rule-base(struct)
            [~, firing_mean] = firing_strength_calculation(obj, xn);
            i_max = find(firing_mean == max(firing_mean));
            i_max = i_max(1);
            Center_mean_old = mean(obj.Center(i_max, :, :), 3); % Rule mean center
            Delta_Center = 0.5 * (obj.Center(i_max, :, 2) - obj.Center(i_max, :, 1));
            Sigma_old = obj.Sigma(i_max, :);
            Num_clusters_old = obj.Num_Clusters(i_max);
            Center_mean_new = Center_mean_old + (1/ (Num_clusters_old + 1)) * (xn - Center_mean_old);
            Sigma_new = sqrt(Sigma_old.^2 + (((xn - Center_mean_new).^2 - (Sigma_old).^2)./ (Num_clusters_old + 1)) + ...
                ((Num_clusters_old .* (Center_mean_new - Center_mean_old).^2)./ (Num_clusters_old + 1)));
            obj.Sigma(i_max, :) = Sigma_new;
            obj.Num_Clusters(i_max) = Num_clusters_old + 1;
            obj.Center(i_max, :, 1) = Center_mean_new - Delta_Center;
            obj.Center(i_max, :, 2) = Center_mean_new + Delta_Center;
        end
        function obj = rule_merg(obj, i_max, j_max, flag)
            % description: rule merg phase
            % Input:
            %        obj: Rule-base(struct)
            %        i_max:
            %        j_max:
            %        flag: Not use now
            % Returns:
            %    obj: Rule-base(struct)
            if flag == 1
                if obj.Num_Clusters(i_max) < obj.Num_Clusters(j_max)
                    k = i_max;
                    i_max = j_max;
                    j_max = k;
                end
            end
            % Merge j_max with i_max
            Center_i = mean(obj.Center(i_max, :, :), 3);
            Center_j = mean(obj.Center(j_max, :, :), 3);
            Delta_Center_i = 0.5 * (obj.Center(i_max, :, 2) - obj.Center(i_max, :, 1));
            Delta_Center_j = 0.5 * (obj.Center(j_max, :, 2) - obj.Center(j_max, :, 1));
            Num_new = obj.Num_Clusters(i_max) + obj.Num_Clusters(j_max);
            Center_new = (obj.Num_Clusters(i_max) * Center_i + obj.Num_Clusters(j_max) * Center_j)/ Num_new;
            Delta_Center = (obj.Num_Clusters(i_max) * Delta_Center_i + obj.Num_Clusters(j_max) * Delta_Center_j)/ Num_new;
            Sigma_new = ((obj.Num_Clusters(i_max) * obj.Sigma(i_max, :).^2 + obj.Num_Clusters(j_max) * obj.Sigma(j_max, :).^2 + obj.Num_Clusters(i_max) * (Center_i - Center_new).^2 ...
                + obj.Num_Clusters(j_max) * (Center_j - Center_new).^2)/ Num_new).^0.5;
            W_new = (obj.Num_Clusters(i_max) * obj.W(:, :, i_max) + obj.Num_Clusters(j_max) * obj.W(:, :, j_max))/ Num_new;
            P_new = (obj.Num_Clusters(i_max) * obj.P(:, :, i_max) + obj.Num_Clusters(j_max) * obj.P(:, :, j_max))/ Num_new;
            obj.Center(i_max, :, 1) = Center_new - Delta_Center;  %TODO
            obj.Center(i_max, :, 2) = Center_new + Delta_Center;  %TODO
            obj.Sigma(i_max, :) = Sigma_new;
            obj.W(:, :,i_max) = W_new;
            obj.Num_Clusters(i_max) = Num_new;
            obj.P(:, :, i_max) = P_new;
            obj.Utility(i_max) = max(obj.Utility(i_max), obj.Utility(j_max));
            obj.Age(i_max) = max(obj.Age(i_max), obj.Age(j_max));
            obj.Center(j_max, :, :) = [];
            obj.Sigma(j_max, :) = [];
            obj.Num_Clusters(j_max) = [];
            obj.W(:, :, j_max) = [];
            obj.P(:, :, j_max) = [];
            obj.Utility(j_max) = [];
            obj.Age(j_max) = [];
        end
        function [firing_strength, firing_mean] = firing_strength_calculation(obj, xn)
            % description: Rule firing strength calculation
            % Input:
            %        obj: Rule-base(struct)
            %        xn:
            % Returns:
            %    firing_strength: Rule firing strength, firing_strength(:,1):lower; firing_strength(:,2):upper
            %    firing_mean: Average firing strength
            mu_lower = ones(size(obj.Center, 1), size(obj.Center, 2));
            mu_upper = ones(size(obj.Center, 1), size(obj.Center, 2));
            for i = 1 : size(obj.Center, 1) %hang 规则数
                for j = 1 : size(obj.Center, 2) %lie 输入变量数
                    if xn(:, j) < obj.Center(i, j, 1) % upper MF
                        mu_upper(i, j) = exp(-0.5 * ((xn(:, j) - obj.Center(i, j, 1))/ obj.Sigma(i, j))^2);
                    elseif xn(:, j) >= obj.Center(i, j, 1) && xn(:, j) <= obj.Center(i, j, 2)
                        mu_upper(i, j) = 1;
                    else % xn(:,j) > C(i,j,2)
                        mu_upper(i, j) = exp(-0.5 * ((xn(:, j) - obj.Center(i, j, 2))/ obj.Sigma(i, j))^2);
                    end

                    if xn(:, j) <= ((obj.Center(i, j, 1) + obj.Center(i, j, 2))/ 2) % lower MF
                        mu_lower(i, j) = exp(-0.5 * ((xn(:, j) - obj.Center(i, j, 2))/ obj.Sigma(i, j))^2);
                    else
                        mu_lower(i, j) = exp(-0.5 * ((xn(:, j) - obj.Center(i, j, 1))/ obj.Sigma(i, j))^2);
                    end
                end
            end
            % NaN judge
            lower_hasNaN = any(isnan(mu_lower));
            upper_hasNaN = any(isnan(mu_upper));
            if lower_hasNaN
                mu_lower(isnan(mu_lower)) = 1e-10;
            end
            if upper_hasNaN
                mu_upper(isnan(mu_upper)) = 1e-10;
            end
            firing_strength = [prod(mu_lower, 2), prod(mu_upper, 2)];
            firing_mean = mean(firing_strength, 2);
        end
        function y_pre = output_calculation(obj, xn)
            % description: Prediction output calculation
            % Input:
            %        obj: Rule-base(struct)
            %        xn:
            % Returns:
            %    y_pre: System prediction output
            xe = [1 xn];
            [F, ~] = firing_strength_calculation(obj, xn);
            y_i = zeros(obj.Num_Rule,SEIT2FS.M);
            y_pre = zeros(1,SEIT2FS.M);
            for i = 1: obj.Num_Rule
                y_i(i,:) = xe * obj.W(:, :, i)';
            end
            for i = 1: size(y_i,2)
                Y = [y_i(:,i) y_i(:,i)];
                [yLeft, yRight] = SEIT2FS.BMM_reduction_algorithm(F, Y, 0.5, 0.5);
                y_pre(:, i) = 0.5 * (yLeft + yRight);
                if isnan(y_pre(:, i))
                    y_pre(:, i) = 0;
                end
            end
        end
        function [W, P] = LWRLS(obj, xn, yn)
            % description: local weighted recursive least square method
            % Input:
            %        obj: Rule-base(struct)
            %        xn:
            %        yn:
            % Returns:
            %        W: Consequent parameters
            %        P: Covariance matrix
            xe = [1 xn];
            [~, firing_mean] = firing_strength_calculation(obj, xn);
            firing_mean = firing_mean./ (sum(firing_mean) + 0.00000001);
            for i = 1: size(firing_mean, 1)
                W = obj.W(:, :,i);
                P = obj.P(:, :, i);
                yi = xe * W';
                y_pre = yi;
                error = yn - y_pre;
                gamma = (P * xe') / (1/ (firing_mean(i,:)+0.00000001) + xe * P * xe');
                W = W + (gamma * error)';
                P = (eye(length(xe)) - gamma * xe) * P;
                obj.W(:, :, i) = W;
                obj.P(:, :, i) = P;
            end
            W = obj.W;
            P = obj.P;
        end

        function similarity = similarity_measure(obj, i_max, j_max)
            % description: Rule similarity measure
            % Input:
            %        obj: Rule-base(struct)
            %        i_max:
            %        j_max:
            % Returns:
            %        similarity:  Rule similarity
            %             membership_degree = ones(1,size(obj.Center, 2));
            %             for i = 1: size(obj.Center, 2)
            %                 membership_degree(i) = sqrt(0.5 * (obj.Center(i_max, i, 1) - obj.Center(j_max, i, 1))^2 + 0.5 * (obj.Center(i_max, i, 2) - obj.Center(j_max, i, 2))^2 + (obj.Sigma(i_max, i) - obj.Sigma(j_max, i))^2);
            %             end
            membership_degree = sqrt(0.5 .* (obj.Center(i_max, :, 1) - obj.Center(j_max, :, 1)).^2 + 0.5 .* (obj.Center(i_max, :, 2) - obj.Center(j_max, :, 2)).^2 + (obj.Sigma(i_max, :) - obj.Sigma(j_max, :)).^2);
            Merging_metric = min(membership_degree); % 集合 t-范数
            similarity = 1/ (1 + (Merging_metric));
        end

        function obj = antecedent_parameters_learning(obj, xn, error)
            % description: Antecedent parameters learning (gradient descent method)
            % Input:
            %        obj: Rule-base(struct)
            %        xn:
            %        error:
            % Returns:
            %        obj: Rule-base(struct)
            xe = [1 xn];
            [firing_strength, ~] = firing_strength_calculation(obj, xn);
            Center_mean = mean(obj.Center(:, :, :), 3);
            delta_Center = 0.5 * (obj.Center(:, :, 2) - obj.Center(:, :, 1));
            fupper_mj1 = zeros(size(obj.Center, 1), size(obj.Center, 2));
            flower_mj1 = zeros(size(obj.Center, 1), size(obj.Center, 2));
            y_i = zeros(obj.Num_Rule, SEIT2FS.M);
            % delta_Center_out = zeros(size(obj.Center, 1), size(obj.Center, 2));

            for i = 1: size(obj.Center, 1) % 规则数
                for j = 1: size(obj.Center, 2) % 输入变量数
                    if xn(:, j) < obj.Center(i, j, 1) %
                        fupper_mj1(i, j) = firing_strength(i, 2) * ((xn(:, j) + delta_Center(i, j, 1) - Center_mean(i,j))/ obj.Sigma(i, j)^2);
                    elseif xn(:, j) > obj.Center(i, j, 2)
                        fupper_mj1(i, j) = firing_strength(i, 2) * ((xn(:, j) - delta_Center(i, j, 1) - Center_mean(i,j))/ obj.Sigma(i, j)^2);
                    else
                        fupper_mj1(i, j) =0;
                    end

                    if xn(:, j) > Center_mean(i,j)
                        flower_mj1(i, j) = firing_strength(i, 1) * ((xn(:, j) - delta_Center(i, j, 1) - Center_mean(i,j))/ obj.Sigma(i, j)^2);
                    else
                        flower_mj1(i, j) = firing_strength(i, 1) * ((xn(:, j) + delta_Center(i, j, 1) - Center_mean(i,j))/ obj.Sigma(i, j)^2);
                    end
                end
            end
            % y_l_fupper y_l_flower y_r_fupper y_r_flower
            %y_i = xe * Rule.W'; %1*n
            for i = 1: obj.Num_Rule
                y_i(i, :) = xe * obj.W(:, :, i)';
            end
            y_ij = y_i;
            %y_i = norm(y_i);
            y_i = vecnorm(y_ij, 2, 2);
            y_flower = 0.5 * (y_i - sum(firing_strength(:, 1).*y_i)/sum(firing_strength(:, 1)));
            y_fupper = 0.5 * (y_i - sum(firing_strength(:, 2).*y_i)/sum(firing_strength(:, 2)));
            delta_Center_out = delta_Center(:, :, 1) - (SEIT2FS.ETA * error) .* (y_flower .* flower_mj1 + y_fupper .* fupper_mj1);

            delta_Center_out(:, :)=min(delta_Center_out(:, :),0.3*obj.Sigma(:, :));
            delta_Center_out(:, :)=max(delta_Center_out(:, :),0.01*obj.Sigma(:, :));
            obj.Center(:, :, 1) = Center_mean - delta_Center_out;
            obj.Center(:, :, 2) = Center_mean + delta_Center_out;
        end

        function obj = threshold_update(obj)
            if SEIT2FS.TEST == 1
                obj.generate = exp(-0.5)*((exp(SEIT2FS.XXX*obj.Cumulative_Error)-exp(-SEIT2FS.XXX*obj.Cumulative_Error))/(exp(SEIT2FS.XXX*obj.Cumulative_Error)+exp(-SEIT2FS.XXX*obj.Cumulative_Error)));
                %obj.merg = 1 - 0.5 *((exp(SEIT2FS.XXX*obj.Cumulative_Error)-exp(-SEIT2FS.XXX*obj.Cumulative_Error))/(exp(SEIT2FS.XXX*obj.Cumulative_Error)+exp(-SEIT2FS.XXX*obj.Cumulative_Error)));
                obj.merg = 0.9;
                obj.prune = exp(-2) *((exp(obj.Cumulative_Error)-exp(-obj.Cumulative_Error))/(exp(obj.Cumulative_Error)+exp(-obj.Cumulative_Error)));
            elseif SEIT2FS.TEST == 2
                obj.generate = SEIT2FS.GENERATE;
                obj.merg = SEIT2FS.MERG;
                obj.prune = SEIT2FS.PRUNE;
            end
        end
    end
    methods(Static)
        function [yLeft, yRight] = BMM_reduction_algorithm(F, Y, alfa, beta) % BMM_reduction_algorithm: alfa = 0.5 ;beta = 0.5;
            % description: Begian-Melek-Mendel (BMM)-type reduction algorithm
            % Input:
            %        F:
            %        Y:
            %        alfa: m
            %        beta: n
            % Returns:
            %        yLeft:
            %        yRight:
            % Sort Y matrix
            lowerY = Y(:,1);
            upperY = Y(:,2);
            [~, ind] = sort(lowerY);
            lowerY = lowerY(ind,:);
            upperY = upperY(ind,:);
            sortedF = F(ind,:);
            lowerF = sortedF(:,1);
            upperF = sortedF(:,2);
            % Convert to crisp Y matrix
            if isequal(lowerY,upperY)
                y=lowerY;
            else
                y=(lowerY+upperY)/2;
            end
            yLeft=alfa*(sum(y.*(lowerF)))/sum(lowerF)+beta*(sum(y.*(upperF)))/sum(upperF);
            yRight=yLeft;
        end
    end
end
