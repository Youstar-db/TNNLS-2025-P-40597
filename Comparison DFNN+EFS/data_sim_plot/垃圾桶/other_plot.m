
desiredtraj;
load pid_high;
load dfnn_efs_high;
load dfnn_high;
load lwpr_high;

load pid_step;
load dfnn_step;
load dfnn_efs_step;
load lwpr_step;

load pid_exp;
load dfnn_efs_exp;
load dfnn_exp;
load lwpr_exp;
i=1;
data{i}=pid_exp;i=i+1;
data{i}=dfnn_exp;i=i+1;
data{i}=lwpr_exp;i=i+1;
data{i}=dfnn_efs_exp;i=i+1;

data{i}=pid_high;i=i+1;
data{i}=dfnn_high;i=i+1;
data{i}=lwpr_high;i=i+1;
data{i}=dfnn_efs_high;i=i+1;

data{i}=pid_step;i=i+1;
data{i}=dfnn_step;i=i+1;
data{i}=lwpr_step;i=i+1;
data{i}=dfnn_efs_step;i=i+1;

winsize=[0.1,0.1,0.55,0.7];zihao=25;lw=2;xysize=[0.13,0.13,0.75,0.75];
winsize=[0.1,0.1,0.6,0.7];zihao=30;lw=2;xysize=[0.13,0.13,0.8,0.8];
xlab=string();
leg=["PID","DFNN_{off}","LWPR","DFNN_{off}+EFS_{on}"];
% leg=["1","2","3","4","5","6","7"];
xlab= categorical({'joint1','joint2','joint3','joint4','joint5','joint6'});
xlab = reordercats(xlab,{'joint1','joint2','joint3','joint4','joint5','joint6'});
% xlab= categorical({'1','2','3'});
% xlab = reordercats(xlab,{'1','2','3'});
id=1;
for i=1:6
    for j=1:length(data)
        iae(i,j)=(IAE(q(:,i),data{j}(:,i),dt));
        ITAE(i,j)=(ite(q(:,i)-data{j}(:,i),t,dt));
        U(i,j)=(sum(abs(data{j}(:,24+i)),1)*dt/t(end));
%         RMSE(:,i)=mean(cumsum(abs(q-data{i}(:,1:6)))*dt./t,2);
%         id=id+1;
    end
end
round(iae*1000,2)
round(ITAE*1000,2)
round(U,2)
% iae=[iae(1:4,:) iae(5:8,:)];
% ITAE=[ITAE(1:4,:) ITAE(5:8,:)];
% U=[U(1:4,:) U(5:8,:)];
%% 
% zihao=20
iae_n=(iae-min(min(iae)))/(max(max(iae))-min(min(iae)));
figure;
iae_n=(ITAE-min(min(ITAE)))/(max(max(ITAE))-min(min(ITAE)));
h = image(iae_n*255);
xlabel('joint');
% ylabel('method');
set(gca,'xtick',[1 2 3 4 5 6]);
set(gca,'ytick',[1 2 3 4 5 6 7 8]);
set(gca,'xticklabel',num2cell([1 2 3 4 5 6]));
set(gca,'yticklabel',num2cell([leg]));
set(gca, 'fontsize', zihao);
set(gcf,'unit','normalized','position',winsize); 
r1 = colorbar();
r1.TickLabels=round(linspace(min(min(ITAE)),max(max(ITAE)),10),3);

figure;set(gca, 'fontsize', zihao);
    set(gcf,'unit','normalized','position',winsize);
U_n=(U-min(min(U)))/(max(max(U))-min(min(U)));
h = image(U_n*400);
xlabel('joint');
% ylabel('method');
set(gca,'xtick',[1 2 3 4 5 6]);
set(gca,'ytick',[1 2 3 4 5 6 7 8]);
set(gca,'xticklabel',num2cell([1 2 3 4 5 6]));
set(gca,'yticklabel',num2cell([leg]));
set(gca, 'fontsize', zihao);
    set(gcf,'unit','normalized','position',winsize);
r3 = colorbar('TickLabels',round([linspace(min(min(U)),max(max(U)),10)],3));
%% 
xlab= categorical({'low','high'});
xlab = reordercats(xlab,{'low','high'});
figure();box on;
iaem=mean(iae,2);
bar(xlab,iaem,1);
legend(leg ,'NumColumns',4);
ylabel('IAE(avg)', 'fontsize', zihao, 'Interpreter', 'latex');
ylim([0 0.04]);
% set(gca,'YTick',[0:0.5:4]);%设置要显示坐标刻度
set(gca, 'fontsize', zihao);
set(gcf,'unit','normalized','position',winsize);
set (gca,'position',xysize );

figure();
box on;
ITAEm=mean(ITAE,2);
ITAEm=[ITAEm(1:4) ITAEm(5:end)];
bar(xlab,ITAEm,1);
legend(leg,'NumColumns', 4);
ylabel('ITAE(avg)', 'fontsize', zihao, 'Interpreter', 'latex');
% ylim([0,2.5]);
set(gca, 'fontsize', zihao);
set(gcf,'unit','normalized','position',winsize);
set (gca,'position',xysize);
hold off;

figure();
box on;

bar(xlab,Um,1);
legend(leg,'NumColumns', 4);
% ylim([0,6.3*100000]);
ylabel('average $\overline {\mathrm |{\tau_{fb}}|}$', 'fontsize', zihao, 'Interpreter', 'latex');
set(gca, 'fontsize', zihao);
set(gcf,'unit','normalized','position',winsize);
set (gca,'position',xysize );
% set(gca,'YTick',[0:10:80]);%设置要显示坐标刻度
% set(gca,'YTickLabel',[0:200:1500]);%给坐标加标签