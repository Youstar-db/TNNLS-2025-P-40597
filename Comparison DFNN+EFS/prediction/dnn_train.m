clear;close all;
%% 
data_gen
%% 
hidnum1=100;
hidnum2=100;
dnn_sim=DNN([size(x_train,2) hidnum1 hidnum2 6],0.01,0.0001);
dnn_sim=dnn_sim.train(x_train,y_train,x_test,y_test,64,100);

taudnn=dnn_sim.Pred(x_train);
for i=1:6
    figure
    plot(y_test(:,i),'r');hold on;
    plot(taudnn(:,i),'b');
end
 r=rmsen(y_test,taudnn)
 mean(r)
 save('dnn_sim','dnn_sim');
 
 
%  figure()
%  hold on;
%  plot(dnn_exp.loss); plot(dfnn_exp.loss);legend('1','2')