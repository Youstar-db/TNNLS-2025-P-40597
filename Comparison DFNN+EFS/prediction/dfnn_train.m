clear;close all;
data_gen
%%
hidnum1=100;
hidnum2=50;
dfnn_exp=DFNN([size(x_train,2),  hidnum2 6],0.01,0.001);
dfnn_exp=dfnn_exp.train(x_train,y_train,x_test,y_test,32,100);
yp=dfnn_exp.Pred(x_test);

for i=1:6
    figure
    plot(y_test(:,i),'r');hold on;
    plot(yp(:,i),'b');
end
r=rmsen(y_test,yp)
mean(r)
% save('dfnn_sim','dfnn_sim');