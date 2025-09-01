close all;
data_gen;
load dfnn;
dfnn=dnn;
load dfnn;
load gpr_model;
load LSTM_net;

lwpr = lwpr_init(18,6,'name','lwpr_test');
lwpr = lwpr_set(lwpr,'init_D',diag(1./((max(x_train)-min(x_train)))/10));
lwpr = lwpr_set(lwpr,'init_alpha',ones(18)*250);
lwpr = lwpr_set(lwpr,'w_gen',0.1);
lwpr = lwpr_set(lwpr,'diag_only',0);
lwpr = lwpr_set(lwpr,'meta',1);
lwpr = lwpr_set(lwpr,'meta_rate',250);
lwpr = lwpr_set(lwpr,'kernel','Gaussian');
lwpr = lwpr_storage('Store',lwpr);

taulwpr_train=zeros(size(y_train));
taugpr_train=zeros(size(y_train));
taudfnn_train=zeros(size(y_train));
taudnn_train=zeros(size(y_train));
taulstm_train=zeros(size(y_train));
z=zeros(size(x_train,1),1);
for i=1:6
    net{i} = resetState(net{i});
end
for i=1:size(x_train,1)
    taulwpr_train(i,:)= lwpr_predict(lwpr,x_train(i,:)');
    [lwpr,~,~] = lwpr_update(lwpr,x_train(i,:)',y_train(i,:)');
end

taudfnn_train=dfnn.Pred(x_train);
taudnn_train=dnn.Pred(x_train);

for j=1:6
    taugpr_train(:,j)=predict(gpr{j},x_train(:,:));
end

for k=1:6
    net{k} = resetState(net{k});
    for i = 2:size(x_train',2)
        [net{k},taulstm_train(k,i)] = predictAndUpdateState(net{k},x_train(i-1,:)');  %
    end   
end

save('taulwpr_train','taulwpr_train');
save('taugpr_train','taugpr_train');
save('taudfnn_train','taudfnn_train');
save('taudnn_train','taudnn_train');
save('taulstm_train','taulstm_train');