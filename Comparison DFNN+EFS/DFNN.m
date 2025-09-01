classdef DFNN
    %DNN 此处显示有关此类的摘要
    %   此处显示详细说明
    
    properties
        N;
        Layer;
        W;
        Wm;
        Wv;
        beta1=0.9;
        beta2=0.99;
        iter=1;
        lr=0.01;
        l2=0.001;
        bestW;bestb
        bestloss=100;
        loss;
        early_stop=0;
        b;bm;bv;
    end
    
    methods
        function obj = DFNN(layer,initlr,l2)
            %DFNN 构造此类的实例
            % layer：定义网络结构，
            % eg.[6，50,50,6]输入层6个输入，中间层分别有50，50个神经元，输出层6个
            % initlr：初始学习率
            % l2：l2正则化系数
            obj.Layer=layer;
            obj.Layer(1)=obj.Layer(1)*5;%模糊层
            obj.N=length(obj.Layer);
            obj.lr=initlr;
            obj.l2=l2;
            obj.W=[];
            for i=1:obj.N-1
                obj.W{i}=0.01*rand(obj.Layer(i),obj.Layer(i+1));
                obj.Wm{i}=zeros(obj.Layer(i),obj.Layer(i+1));
                obj.Wv{i}=zeros(obj.Layer(i),obj.Layer(i+1));
                obj.b{i}=0.01*rand(1,obj.Layer(i+1));
                obj.bm{i}=zeros(1,obj.Layer(i+1));
                obj.bv{i}=zeros(1,obj.Layer(i+1));
            end
        end
        
        function obj = Update(obj,x,y)
            %METHOD1 此处显示有关此方法的摘要
            %   此处显示详细说明
            x=fuzzy(x);
            f{1}=x;
            for i=2:obj.N-1
                f{i}=f{i-1}*obj.W{i-1}+obj.b{i-1};
%                 f{i}=sigmoid(f{i}); %sigmoid
%                 f{i}=relu(f{i});   %relu
               f{i}=tanh(f{i});     %tanh
            end
            f{end+1}=f{end}*obj.W{end}+obj.b{end};
            dw=obj.W;
            db=obj.b;
            de=f;
            for i=obj.N:-1:2
                if i~=obj.N
%                     de{i}=de{i+1}*obj.W{i}'.*f{i}.*(1-f{i}); %sigmoid
%                     de{i}=de{i+1}*obj.W{i}'.*[f{i}>=0];  %relu
                    de{i}=de{i+1}*obj.W{i}'.*(1-f{i}.^2); %tanh
%                     de{i}=de{i+1}*obj.W{i}';
                    dw{i-1}=f{i-1}'*de{i};
                    db{i-1}=sum(de{i});
                else
                    de{i}=f{i}-y;
                    dw{i-1}=f{i-1}'*de{i};
                    db{i-1}=sum(de{i});
                end
                obj.Wm{i-1}=obj.beta1*obj.Wm{i-1}+(1-obj.beta1)*dw{i-1};
                obj.Wv{i-1}=obj.beta2*obj.Wv{i-1}+(1-obj.beta2)*dw{i-1}.^2;
                mh=obj.Wm{i-1}/(1-obj.beta1.^obj.iter);
                vh=obj.Wv{i-1}/(1-obj.beta2.^obj.iter);
                h=mh./(sqrt(vh)+10^(-8));
                %W更新
                obj.W{i-1}=obj.W{i-1}-obj.lr*h-obj.l2*obj.W{i-1};
                
                obj.bm{i-1}=obj.beta1*obj.bm{i-1}+(1-obj.beta1)*db{i-1};
                obj.bv{i-1}=obj.beta2*obj.bv{i-1}+(1-obj.beta2)*db{i-1}.^2;
                mh=obj.bm{i-1}/(1-obj.beta1.^obj.iter);
                vh=obj.bv{i-1}/(1-obj.beta2.^obj.iter);
                h=mh./(sqrt(vh)+10^(-8));
                %b更新
                obj.b{i-1}=obj.b{i-1}-obj.lr*h-obj.l2*obj.b{i-1};
            end 
            obj.iter=obj.iter+1;
        end
        
        function [obj] = train(obj,x_train,y_train,x_test,y_test,batch,epoch)
            %批量训练
            l=length(x_train);
            obj.loss=zeros(epoch,1);
            randIndex = randperm(size(x_train,1));
            x_train=x_train(randIndex,:);
            y_train=y_train(randIndex,:);
            for i=1:epoch
                for j=1:l/batch
                    if j*batch>l
                        xbatch=x_train(end-batch:end,:);
                        ybatch=y_train(end-batch:end,:);
                        obj=obj.Update(xbatch,ybatch);
                    else
                        xbatch=x_train((j-1)*batch+1:j*batch,:);
                        ybatch=y_train((j-1)*batch+1:j*batch,:);
                        obj=obj.Update(xbatch,ybatch);
                    end
                end
                %学习率下降
                if mod(i,50)==0
                    obj.lr=0.5*obj.lr;
                end
                 yp=obj.Pred(x_test);
                 r=rmsen(y_test,yp);
                 obj.loss(i)=mean(r);
                 %最优参数
                 if obj.loss(i)<obj.bestloss
                     obj.bestloss=obj.loss(i);
                     obj.bestW=obj.W;obj.bestb=obj.b;
                 end
                 %早停
                 if i>1&&obj.loss(i)<=obj.loss(i-1)
                     obj.early_stop=0;
                 else
                     obj.early_stop=obj.early_stop+1;
                 end
                 ['epoch'+":"+num2str(i)+":"+'loss'+num2str(obj.loss(i))]
                 if obj.early_stop>10
                     break;
                 end
            end
            obj.W=obj.bestW;obj.b=obj.bestb;
        end
        function y = Pred(obj,x)
            %预测
            x=fuzzy(x);
            y=x;
            for i=2:length(obj.Layer)-1
                y=y*obj.W{i-1}+obj.b{i-1};
%                  y=y*obj.W{i-1};
%                 y=sigmoid(y);
                y=tanh(y);
%                 y=relu(y);
            end
            y=y*obj.W{end}+obj.b{end};
        end
    end
end

