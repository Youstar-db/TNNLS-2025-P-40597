clear;close all;
data_gen;
num_in=size(x_train,2);
winsize=[0.1,0.1,0.6,0.7];zihao=20;lw=2;xysize=[0.13,0.13,0.8,0.8];
%% dfnn每个关节单独训练%
hidnum1=100;
hidnum2=50;
dfnn_sim_6=[DFNN([num_in,hidnum1 hidnum2 1],0.01,0.001)
    DFNN([num_in,hidnum1 hidnum2 1],0.01,0.001)
    DFNN([num_in,hidnum1 hidnum2 1],0.01,0.001)
    DFNN([num_in,hidnum1 hidnum2 1],0.01,0.001)
    DFNN([num_in,hidnum1 hidnum2 1],0.002,0.001)
    DFNN([num_in,hidnum1 hidnum2 1],0.01,0.001)];
yp=zeros(size(y_test));
for i=1:6
    dfnn_sim_6(i)=dfnn_sim_6(i).train(x_train,y_train(:,i),x_test,y_test(:,i),64,100);
end
for i=1:6
    yp(:,i)=dfnn_sim_6(i).Pred(x_test);
end
figure;
sp=[321,322,323,324,325,326];

% set(gcf,'unit','normalized','position',winsize);
% set (gca,'position',xysize);

for i=1:6
    subplot(sp(i));
    plot(y_test(:,i),'r','linewidth',1.5);hold on;grid on;box on;
    plot(yp(:,i),'b','linewidth',1.5);
    set(gca, 'fontsize', zihao);
    ylabel(['T',num2str(i),' N*m']);
end
legend(["y","y_{predict}"],'NumColumns', 4,'Location', 'north');
mean(rmsen(y_test,yp));
% save('dfnn_sim_6','dfnn_sim_6');

%% %dfnn训练单个模型%
hidnum1=100;
hidnum2=50;
dfnn_sim1=DFNN([num_in hidnum1  hidnum2 6],0.01,0.001);
S=[regress(y_train(:,1),x_train)  regress(y_train(:,2),x_train) regress(y_train(:,3),x_train) regress(y_train(:,4),x_train) regress(y_train(:,5),x_train) regress(y_train(:,6),x_train)];
dfnn_sim1=dfnn_sim1.train(x_train,y_train,x_test,y_test,64,100);
yp=dfnn_sim1.Pred(x_test);

for i=1:6
    figure
    plot(y_test(:,i),'r');hold on;
    plot(yp(:,i),'b');
end
r=mean(rmsen(y_test,yp))
mean(r)
%  save('dfnn_sim1','dfnn_sim1');
