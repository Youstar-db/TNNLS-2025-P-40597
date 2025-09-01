clc;clear;
clear;close all;
% parpool('local');
data_gen
ind=6;
x_train=x_train(1:100:end,:);
y_train=y_train(1:100:end,:);
gpr=[];yp=zeros(size(y_test));
%%  fitgp matlab自带的高斯拟合
for i=1:6
gpr{i} = fitrgp(x_train,y_train(:,i));
end
yp=[]
for i=1:6
yp(:,i) = predict(gpr{i},x_test);
end
%% 画图
for i=1:6
    figure();hold on;
    plot(yp(:,i));plot(y_test(:,i));
end
rmsen(y_test,yp)
