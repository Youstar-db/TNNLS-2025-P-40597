classdef ENFIS
    %ENFIS 此处显示有关此类的摘要
    %   此处显示详细说明
    
    properties
        Fp;%焦点
        Ml;%均值
        Mg;%全局均值
        El;%局部标量积
        Eg;%全局标量积
        R;%扩散半径
        Tdel=0.1;%规则删除阈值
        Rn;%规则数量
        Ns;%样本数
        W;%后件
        Pg;%全局海森矩阵
        Pl;
        iter;%迭代数
        U;
        Wm;
        Wv;
        beta1=0.9;
        beta2=0.999;
        a=0.001;
        isact=0;
        n;
        m;
        lr;
    end
    
    methods
        function obj = ENFIS(x,n,lr)
            %ENFIS 构造此类的实例
            %   此处显示详细说明
            x0=x(1,:);
            obj.m=size(x,2);
            obj.n=n;
            obj=obj.initialize(x0,n);
            obj.lr=lr;
            %             obj = obj.organize(x);
        end
        
        function obj=initialize(obj,x0,n)
            
            obj.Fp=x0;%焦点
            obj.Ml=x0;%均值
            obj.Mg=x0;%全局均值
            obj.El=sum(x0.^2);%局部标量积
            obj.Eg=sum(x0.^2);%全局标量积
            obj.R=0;%扩散半径
            obj.Tdel=0.01;%规则删除阈值
            obj.Rn=1;%规则数量
            obj.Ns=1;%样本数
            obj.W(:,:,1)=0.01*rand(length(x0)+1,n);
            obj.Wm(:,:,1)=zeros(length(x0)+1,n);
            obj.Wv(:,:,1)=zeros(length(x0)+1,n);
            obj.Pg=1000*eye(length(x0)+1);%全局海森矩阵
            obj.Pl(:,:,1)=10000*eye(length(x0)+1);
            obj.iter=1;%迭代数
            obj.U=1;
        end
        function obj=pretrain(obj,x)
            [coeff, score, latent, tsquared, explained, mu]=pca(x);
            y=score(:,1:obj.n);   % 取转换后的矩阵score的前k列为PCA降维后特征
            obj=obj.train(x,y,1000,10,0.01);
        end
        function obj = organize(obj,X)
            %FAC 构造此类的实例
            %   此处显示详细说明
            %1中间层输入不可控导致模糊集不好确定2
            
            for i=1:size(X,1)
                x=X(i,:);
                Fs = obj.Fire(x);
                f=argmin(-Fs);
                if max(Fs)<exp(-3)
                    obj.Fp=[obj.Fp;x];
                    obj.Ml=[obj.Ml;x];
                    obj.El=[obj.El;sum(x.^2)];
                    obj.U=[obj.U;1];
                    obj.R=[obj.R;1];
                    obj.Rn=obj.Rn+1;
                    obj.Ns=[obj.Ns;1];

                    obj.W(:,:,end+1)=mean(obj.W,3);
                    %             obj.W(:,:,end+1)=0.01*rand(obj.m+1,obj.n);
                    obj.Wm(:,:,end+1)=zeros(size(obj.W(:,:,1)));
                    obj.Wv(:,:,end+1)=zeros(size(obj.W(:,:,1)));
                    obj.Pg=[obj.Pg zeros(size(obj.Pg,1),length(x)+1);
                        zeros(length(x)+1,size(obj.Pg,1)) 1000*eye(length(x)+1)];
                    obj.Pl(:,:,end+1)=10000*eye(length(x)+1);
                    %             disp("generate!");
                    %             obj.Rn
                else
                    obj.Ml(f,:)=(obj.Ml(f,:)*obj.Ns(f)+x)/(obj.Ns(f)+1);
                    obj.El(f)=(obj.El(f)*obj.Ns(f)+sum(x.^2))/(obj.Ns(f)+1);
                    obj.R(f)=(obj.R(f)+sqrt(obj.El(f,:)-sum(obj.Ml(f,:).^2)))/2;
                    obj.Ns(f)=obj.Ns(f)+1;
                end
                Fs = obj.Fire(x);
                obj.U=(obj.U*obj.iter+Fs')/(obj.iter+1);
                obj.Mg=(obj.Mg*sum(obj.Ns)+x)/(sum(obj.Ns)+1);
                obj.Eg=(obj.Eg*sum(obj.Ns)+sum(x.^2))/(sum(obj.Ns)+1);
            end
        end
        function obj = RuleGenerate(obj,x,f)
            %METHOD1 此处显示有关此方法的摘要
            %   此处显示详细说明
            
        end
        
        function obj = RuleUpdate(obj,x,f)
            %METHOD1 此处显示有关此方法的摘要
            %   此处显示详细说明
            %             obj.Fp(f,:)=x;
            
        end
        
        function obj = GlobalUpdate(obj,x)
            %METHOD1 此处显示有关此方法的摘要
            %   此处显示详细说明
            
        end
        
        function yp = Pred(obj,X)
            %预测
            N=size(X,1);
            yp=zeros(N,obj.n);
            Fs=obj.Fire(X);
            Fs=Fs./(sum(Fs,2)+1e-6);
            X=[ones(N,1) X];
            W=reshape(obj.W,obj.m+1,obj.n*obj.Rn);
            Y=X*W;
            for i=1:N
                y=reshape(Y(i,:),obj.n,obj.Rn);
                yp(i,:)=Fs(i,:)*y';
            end
            if obj.isact
                yp=sigmoid(yp);
            end
        end
        
        function Fs = Fire(obj,x)
            %Fire 激活强度
            Fs=zeros(size(x,1),size(obj.Ml,1));
            for i=1:size(x,1)
                Fs(i,:)=exp(-2*sum((x(i,:)-obj.Fp).^2,2)./(obj.Eg-sum(obj.Mg.^2)+obj.El-sum(obj.Ml.^2,2)+1e-6));
            end
        end
        
        function obj = ConsequentUpdate(obj,X,y)
            %ConsequentUpdate 梯度下降后件更新
            Fs = obj.Fire(X);
            yp = Pred(obj,X);
            e=yp-y;
            k=obj.iter;
            dw=zeros(size(obj.W));
            X2=[ones(size(X,1),1),X];
            Fs=Fs./(sum(Fs,2)+1e-6);
            for i=1:size(obj.Ml,1)
                Fsi=Fs(:,i);
                dw(:,:,i)=(X2.*Fsi)'*e;
            end
            dw=dw+obj.W*0.0001;
            obj.Wm=obj.beta1*obj.Wm+(1-obj.beta1)*dw;
            obj.Wv=obj.beta2*obj.Wv+(1-obj.beta2)*dw.^2;
            mh=obj.Wm./(1-obj.beta1.^k);
            vh=obj.Wv./(1-obj.beta2.^k);
            obj.W=obj.W-obj.lr*mh./(sqrt(vh)+10^(-8));
            %             obj.W=obj.W-lr*dw;
            obj.iter=obj.iter+1;
        end
        
        function dw = ydw(obj,X,dh)
            %ydw 输出对后件微分
            Fs = obj.Fire(X);
            
            dw=zeros(size(obj.W));
            Fs=Fs./sum(Fs,2);
            
            if obj.isact
                h = obj.Pred(X);
                h=h.*(1-h);
            else
                h=1;
            end
            X=[ones(size(X,1),1),X];
            dh=h.*reshape(sum(dh,2),[size(dh,3),size(dh,1)]);
            for i=1:size(obj.Ml,1)
                Fsi=Fs(:,i);
                dw(:,:,i)=(X.*Fsi)'*dh;
            end
        end
        function obj = encoderupdate(obj,X,dh)
            %encoderupdate 编码器更新，输出等于输入
            k=obj.iter;
            dw=obj.ydw(X,dh)+obj.W*0.0;
            obj.Wm=obj.beta1*obj.Wm+(1-obj.beta1)*dw;
            obj.Wv=obj.beta2*obj.Wv+(1-obj.beta2)*dw.^2;
            mh=obj.Wm./(1-obj.beta1.^k);
            vh=obj.Wv./(1-obj.beta2.^k);
            obj.W=obj.W-obj.lr*mh./(sqrt(vh)+10^(-8));
            %             obj.W=obj.W-lr*dw;
            obj.iter=obj.iter+1;
        end
        
        function dx = edx(obj,x,y)
            %输出误差对输入求导
            Fs = obj.Fire(x);
            yp = Pred(obj,x);
            e=yp-y;
            dx=zeros([size(obj.W,1)-1,size(obj.W,2),size(x,1)]);
            Fss=sum(Fs,2);
            tau=(obj.Eg-sum(obj.Mg.^2)+obj.El-sum(obj.Ml.^2))/2;
            
            for i=1:size(x,1)
                xi=x(i,:);
                Ds=sum(Fs(i,:)*2.*(obj.Fp-xi)'./(tau'),2);
                lamadadx=Fs(i,:)./Fss(i)*2.*(obj.Fp-xi)'./tau'-Ds*Fs(i,:)./Fss(i).^2;
                ydx=zeros([size(obj.W,1)-1,size(obj.W,2),size(obj.W,3)]);
                for j=1:size(obj.Ml,1)
                    x1=[1 xi];
                    if obj.isact
                        y=sigmoid(x1*obj.W(:,:,j));
                        ydx(:,:,j)=lamadadx(:,j).*y+Fs(i,j)./Fss(i).*(y-y.^2).*obj.W(2:end,:,j);
                    else
                        y=x1*obj.W(:,:,j);
                        ydx(:,:,j)=lamadadx(:,j).*y+Fs(i,j)./Fss(i).*obj.W(2:end,:,j);
                    end
                end
                
                dx(:,:,i)=e(i,:).*sum(ydx,3);
            end
        end
        
        function dx = ydx(obj,x,d_1)
            %ydx 输出对输入微分
            Fs = obj.Fire(x);
            dx=zeros([size(obj.W,1)-1,size(obj.W,2),size(x,1)]);
            Fss=sum(Fs,2);
            tau=(obj.Eg-sum(obj.Mg.^2)+obj.El-sum(obj.Ml.^2))/2;
            for i=1:size(x,1)
                xi=x(i,:);
                Ds=sum(Fs(i,:)./Fss(i,:)*2.*(obj.Fp-xi)'./(tau'),2);
                lamadadx=Fs(i,:)./Fss(i,:)*2.*(obj.Fp-xi)'./tau'-Ds*Fs(i,:)./Fss(i,:).^2;
                ydx=zeros([size(obj.W,1)-1,size(obj.W,2),size(obj.W,3)]);
                for j=1:size(obj.Ml,1)
                    x1=[1 xi];
                    if obj.isact
                        y=sigmoid(x1*obj.W(:,:,j));
                        ydx(:,:,j)=lamadadx(:,j).*y+Fs(i,j)./Fss(i).*(y-y.^2).*obj.W(2:end,:,j);
                    else
                        y=x1*obj.W(:,:,j);
                        ydx(:,:,j)=lamadadx(:,j).*y+Fs(i,j)./Fss(i).*obj.W(2:end,:,j);
                    end
                end
                dx(:,:,i)=sum(ydx,3).*sum(d_1(:,:,i),2)';
            end
        end
        function [obj] = train(obj,x_train,y_train,batch,epoch)
            %train 
            l=length(x_train);
            for i=1:epoch
                for j=1:l/batch
                    if j*batch>l
                        xbatch=x_train(end-batch:end,:);
                        ybatch=y_train(end-batch:end,:);
                        obj=obj.ConsequentUpdate(xbatch,ybatch);
                    else
                        xbatch=x_train((j-1)*batch+1:j*batch,:);
                        ybatch=y_train((j-1)*batch+1:j*batch,:);
                        obj=obj.ConsequentUpdate(xbatch,ybatch);
                        
                    end
                    
                end
                yp=obj.Pred(x_train);
                r=rmse(y_train,yp)
            end
        end
        function [obj] = RLS(obj,x_train,y_train)
            %全局递归最小二乘
            %             Fs = obj.Fire(x_train);
            %             Fs=Fs./sum(Fs,2);
            %             x=[ones(size(x_train,1),1) x_train];
            %             for i=1:obj.Rn
            %                  Q=diag(Fs(:,i));
            %                  Pi=inv(x'*Q*x);
            %                  obj.Pl(:,:,i)=Pi;
            %                 obj.W(:,:,i)=Pi*x'*Q*y_train;
            %             end
            %局部
            for i=1:size(x_train,1)
                obj = obj.ILRLS(x_train(i,:),y_train(i,:));
            end
        end
        
        function [obj] = ILRLS(obj,x_train,y_train)
            %局部增量式
            Fs = obj.Fire(x_train);
            xn=[ones(size(x_train,1),1) x_train];
            Fs=Fs./(sum(Fs)+1e-6);
            for k=1:obj.Rn
                Fsk=Fs(k);
                Wk=obj.W(:,:,k);
                Pi=obj.Pl(:,:,k);
                yp=xn*Wk;
                error=(y_train-yp);
                gama=Pi*xn'/(1/Fsk+xn*Pi*xn');
                Pi=1*(eye(obj.m+1)-gama*xn)*Pi;
                dW=gama*error;
                Wk=Wk+dW;
                obj.W(:,:,k)=Wk;
                obj.Pl(:,:,k)=Pi;
            end
        end
    end
end

