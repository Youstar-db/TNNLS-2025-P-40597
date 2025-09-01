close all;
data_gen;
load dfnn;
load gpr_model;
dnn.lr=0.001;
lwpr = lwpr_init(18,6,'name','lwpr_test');
lwpr = lwpr_set(lwpr,'init_D',diag(1./((max(x_test)-min(x_test)))/10));    
lwpr = lwpr_set(lwpr,'init_alpha',ones(18)*250);
lwpr = lwpr_set(lwpr,'w_gen',0.1); 
lwpr = lwpr_set(lwpr,'diag_only',0);   
lwpr = lwpr_set(lwpr,'meta',1); 
lwpr = lwpr_set(lwpr,'meta_rate',250); 
lwpr = lwpr_set(lwpr,'kernel','Gaussian'); 
lwpr = lwpr_storage('Store',lwpr);

errormodel=DFNN(size(x_test,2),[100 50 size(y_test,2)],0.001,0.0001);
dnn_online=dnn;
enfis=ENFIS(x_train,6,0.1);
taudfnn=dnn.Pred(x_train);
tau_error=y_train-taudfnn;
% enfis=enfis.train(x_train,y_train-tau_error,64,10);
% errormodel=errormodel.train(x_train,y_train-tau_error,x_train,y_train-tau_error,64,10);

yp_enfis=zeros(size(y_test));
taunn_train=zeros(size(y_test));
taufs=zeros(size(y_test));
tauenn=zeros(size(y_test));
taulwpr=zeros(size(y_test));
taueonn=zeros(size(y_test)); 
tauegpr=zeros(size(y_test));

z=zeros(size(x_test,1),1);
pretime_fs=z;traintime_fs=z;
pretime_enn=z;traintime_enn=z;
pretime_gpr=z;traintime_gpr=z;
pretime_lwpr=z;traintime_fs=z;
for i=1:size(x_test,1)
    taunn_train(i,:)=dnn.Pred(x_test(i,:));
    tic
    taufs(i,:)=enfis.Pred(x_test(i,:));
    pretime_fs(i)=toc;
    tic
    tauenn(i,:)=errormodel.Pred(x_test(i,:));
    pretime_enn(i)=toc;
%     taulwpr(i,:)= lwpr_predict(lwpr,x_test(i,:)');
    
    taueonn(i,:)=dnn_online.Pred(x_test(i,:));
    tic
    for j=1:6
    tauegpr(i,j)=predict(gpr{j},x_test(i,:));
    end
    pretime_gpr(i)=toc;
    errornn=y_test(i,:)-taunn_train(i,:);
    tic
    dnn_online=dnn_online.Update(x_test(i,:),y_test(i,:));
    traintime_enn(i)=toc;
    tic
    enfis=enfis.organize(x_test(i,:));
    enfis=enfis.ConsequentUpdate(x_test(i,:),errornn);
    traintime_fs(i)=toc;
    errormodel=errormodel.Update(x_test(i,:),errornn);
%     [lwpr,~,~] = lwpr_update(lwpr,x_test(i,:)',y_test(i,:)');
end

for i=1:size(y_test,2)
    figure;hold on;
plot(y_test(:,i)-taunn_train(:,i));
plot(y_test(:,i)-taunn_train(:,i)-tauenn(:,i));
plot(y_test(:,i)-taunn_train(:,i)-taufs(:,i));

% plot(taulwpr(:,i));
plot(y_test(:,i)-taueonn(:,i));
plot(tauegpr(:,i));
legend('1','2','3','4','5','6');
end
%% 
t=[1:size(y_test,1)]'*0.001;
for i=1:size(y_test,2)
figure;hold on;
plot(cumsum(abs(y_test(:,i)-taunn_train(:,i)))./t);
plot(cumsum(abs(y_test(:,i)-taunn_train(:,i)-tauenn(:,i)))./t);
plot(cumsum(abs(y_test(:,i)-taunn_train(:,i)-taufs(:,i)))./t);

% plot(taulwpr(:,i));
plot(cumsum(abs(y_test(:,i)-taueonn(:,i)))./t);
plot(cumsum(abs(y_test(:,i)-tauegpr(:,i)))./t);
legend('1','2','3','4','5','6');
end
rmsen(y_test,taunn_train)
rmsen(y_test,taunn_train+taufs)
rmsen(y_test,taunn_train+tauenn)
% rmse(y_test,taulwpr)
rmsen(y_test,taueonn)
rmsen(y_test,tauegpr)

mean(pretime_fs)
mean(pretime_enn)
mean(pretime_gpr)

mean(traintime_fs)
mean(traintime_enn)