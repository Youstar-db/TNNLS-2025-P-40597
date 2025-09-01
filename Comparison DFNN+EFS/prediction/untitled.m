close all;data_gen;
%********比较预测精度************
load taulstm;
load tauinc;
load taunn;
load taulwpr;
load taudfnn;
load taugpr;
load tauefs;
load taudnn;
data=[];
data{1}=taulstm';
data{2}=taulwpr;
data{3}=tauegpr;
data{4}=taudnn;
data{5}=tauenn+taunn_train;

data{6}=taunn_train;


leg=["LSTM","LWPR","GP","EFS","NN","DFNN"];
dt=0.001;
t=[1:size(y_test,1)]'*dt;

% for i=1:size(y_test,2)
    
   figure;hold on; 
    for j=1:length(data)
        
%         plot(cumsum(dt*abs(y_test(:,i)-data{j}(:,i)))./t);
        plot(t,cumsum(mean((y_test-data{j}).^2,2))*dt./t);
%         plot(t,cumsum(dt*sum((y_test-data{j}).^2./var(y_test),2))./t);
    end
    legend(leg);
    
% end
for j=1:length(data)
    rmsen(y_test,data{j})
end



