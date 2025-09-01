close all;
clear;
loaddata;

% data{3}=inc_dfnn_low;
% data{4}=nn_nn_low;
% data{4}=dfnn_efs_sim;


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
for i=1:size(data,1)
    for j=1:size(data,2)
        iae(id,:)=(IAE(q,data{i,j}(:,1:6),dt));
        ITAE(id,:)=(ite(q-data{i,j}(:,1:6),t,dt));
        U(id,:)=(sum(abs(data{i,j}(:,25:30)),1)*dt/t(end));
%         RMSE(:,i)=mean(cumsum(abs(q-data{i}(:,1:6)))*dt./t,2);
id=id+1;
    end
    
end
%%
iae1=iae(1:4,:);
ITAE1=ITAE(1:4,:);
U1=U(1:4,:);

iae2=iae(5:8,:);
ITAE2=ITAE(5:8,:);
U2=U(5:8,:);
%% 
% zihao=20
figure;
iae_n=(iae1-min(min(iae1)))/(max(max(iae1))-min(min(iae1)));
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
r1.TickLabels=round(linspace(min(min(iae1)),max(max(iae1)),10),3);

figure;set(gca, 'fontsize', zihao);
    set(gcf,'unit','normalized','position',winsize);
ITAE_n=(ITAE1-min(min(ITAE1)))/(max(max(ITAE1))-min(min(ITAE1)));
h = image(ITAE_n*255);
xlabel('joint');
% ylabel('method');
set(gca,'xtick',[1 2 3 4 5 6]);
set(gca,'ytick',[1 2 3 4 5 6 7 8]);
set(gca,'xticklabel',num2cell([1 2 3 4 5 6]));
set(gca,'yticklabel',num2cell([leg]));
set(gca, 'fontsize', zihao);
    set(gcf,'unit','normalized','position',winsize);
r2 = colorbar('TickLabels',round([linspace(min(min(ITAE1)),max(max(ITAE1)),10)],3));


figure;set(gca, 'fontsize', zihao);
    set(gcf,'unit','normalized','position',winsize);
U_n=(U1-min(min(U1)))/(max(max(U1))-min(min(U1)));
h = image(U_n*255);
xlabel('joint');
% ylabel('method');
set(gca,'xtick',[1 2 3 4 5 6]);
set(gca,'ytick',[1 2 3 4 5 6 7 8]);
set(gca,'xticklabel',num2cell([1 2 3 4 5 6]));
set(gca,'yticklabel',num2cell([leg]));
set(gca, 'fontsize', zihao);
    set(gcf,'unit','normalized','position',winsize);
r3 = colorbar('TickLabels',round([linspace(min(min(U1)),max(max(U1)),10)],3));
%% 
figure;
iae_n=(iae-min(min(iae)))/(max(max(iae))-min(min(iae)));
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
r1.TickLabels=round(linspace(min(min(iae)),max(max(iae)),10),3);

figure;set(gca, 'fontsize', zihao);
    set(gcf,'unit','normalized','position',winsize);
ITAE_n=(ITAE-min(min(ITAE)))/(max(max(ITAE))-min(min(ITAE)));
h = image(ITAE_n*255);
xlabel('joint');
% ylabel('method');
set(gca,'xtick',[1 2 3 4 5 6]);
set(gca,'ytick',[1 2 3 4 5 6 7 8]);
set(gca,'xticklabel',num2cell([1 2 3 4 5 6]));
set(gca,'yticklabel',num2cell([leg]));
set(gca, 'fontsize', zihao);
    set(gcf,'unit','normalized','position',winsize);
r2 = colorbar('TickLabels',round([linspace(min(min(ITAE)),max(max(ITAE)),10)],3));


figure;set(gca, 'fontsize', zihao);
    set(gcf,'unit','normalized','position',winsize);
U_n=(U-min(min(U)))/(max(max(U))-min(min(U)));
h = image(U_n*255);
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
% figure();box on;
% plot(RMSE);
% legend(leg ,'NumColumns',3);
% ylabel('RMSE', 'fontsize', zihao, 'Interpreter', 'latex');
% ylim([0 4]);
% set(gca, 'fontsize', zihao);
% set(gcf,'unit','normalized','position',winsize);
% set (gca,'position',xysize );
%% IAE

figure();box on;
bar(xlab,iae,1);
legend(leg ,'NumColumns',3);
ylabel('IAE', 'fontsize', zihao, 'Interpreter', 'latex');
% ylim([0 4]);
set(gca,'YTick',[0:0.5:4]);%设置要显示坐标刻度
set(gca, 'fontsize', zihao);
set(gcf,'unit','normalized','position',winsize);
set (gca,'position',xysize );
%% ITAE

figure();
box on;
bar(xlab,ITAE,1);
legend(leg,'NumColumns', 2);
ylabel('ITAE', 'fontsize', zihao, 'Interpreter', 'latex');
% ylim([0,2.5]);
set(gca, 'fontsize', zihao);
set(gcf,'unit','normalized','position',winsize);
set (gca,'position',xysize);
hold off;
%% U

figure();
box on;
bar(xlab,U',1);
legend(leg,'NumColumns', 2);
% ylim([0,6.3*100000]);
ylabel('average $\mathrm |{\tau_{fb}}|$', 'fontsize', zihao, 'Interpreter', 'latex');
set(gca, 'fontsize', zihao);
set(gcf,'unit','normalized','position',winsize);
set (gca,'position',xysize );
% set(gca,'YTick',[0:10:80]);%设置要显示坐标刻度
% set(gca,'YTickLabel',[0:200:1500]);%给坐标加标签
%%
%  figure;hold on;
idsubplo=[231 232 233 234 235 236];
% for i=1:6
%     subplot(idsubplo(i));
for i=1:6
    fig=figure;hold on;box on;
    %         plot(t,q(:,i),'linewidth',lw);
    for j=1:length(data)
        plot(t,abs(q(:,i)-data{1,j}(:,i)),'linewidth',lw);

    end
        ylim([0,0.001]);
    %     axis([t(1) t(end) 0 0.1]);
    set(gca, 'fontsize', zihao);
    set(gcf,'unit','normalized','position',winsize);
    set (gca,'position',xysize);
    legend([ leg],'NumColumns', 4,'Location', 'north')
    xlabel('Time s', 'fontsize', zihao, 'Interpreter', 'latex');
    ylabel(['$|\tilde q_{'  num2str(i) '}(t) |$ rad'], 'fontsize', zihao, 'Interpreter', 'latex');
%     print(fig,['e',num2str(i),'_gradual.eps'],'-r600','-depsc'); % 设置图片格式、分辨率
end
for i=1:6
    fig=figure;hold on;box on;
    %         plot(t,q(:,i),'linewidth',lw);
    for j=1:length(data)
        plot(t,abs(q(:,i)-data{2,j}(:,i)),'linewidth',lw);
%         plot(t,cumsum(abs(q(:,i)-data{2,j}(:,i)))./t,'linewidth',lw);
    end
ylim([0,0.001]); 
    %     axis([t(1) t(end) 0 0.1]);
    set(gca, 'fontsize', zihao);
    set(gcf,'unit','normalized','position',winsize);
    set (gca,'position',xysize);
    legend([ leg],'NumColumns', 4,'Location', 'north')
    xlabel('Time s', 'fontsize', zihao, 'Interpreter', 'latex');
    ylabel(['$|\tilde q_{'  num2str(i) '}(t)| $ rad'], 'fontsize', zihao, 'Interpreter', 'latex');
%     print(fig,['e',num2str(i),'_step.eps'],'-r600','-depsc'); % 设置图片格式、分辨率
end
% for i=1:6
%     figure;hold on;box on;
%     %         plot(t,q(:,i),'linewidth',lw);
%     for j=1:length(data)
%         plot(t,q(:,i)-data{3,j}(:,i),'linewidth',lw);
%     end
%     %     ylim([-0.006,0.006]);
%     
%     
%     %     axis([t(1) t(end) 0 0.1]);
%     set(gca, 'fontsize', zihao);
%     set(gcf,'unit','normalized','position',winsize);
%     set (gca,'position',xysize);
%     legend([ leg],'NumColumns', 4,'Location', 'north')
%     xlabel('Time s', 'fontsize', zihao, 'Interpreter', 'latex');
%     ylabel(['$\tilde q_{'  num2str(i) '}(t) $ rad'], 'fontsize', zihao, 'Interpreter', 'latex');
%     
% end
% end
%% 
    fig=figure;hold on;box on;
    %         plot(t,q(:,i),'linewidth',lw);
    for j=1:length(data)
%         plot(t,q(:,i)-data{1,j}(:,i),'linewidth',lw);
         plot(t,cumsum(mean(abs(q-data{1,j}(:,1:6)),2))*dt,'linewidth',lw);
    end
%         ylim([-0.001,0.001]);
    %     axis([t(1) t(end) 0 0.1]);
    set(gca, 'fontsize', zihao);
    set(gcf,'unit','normalized','position',winsize);
    set (gca,'position',xysize);
    legend([ leg],'NumColumns', 4,'Location', 'north')
    xlabel('Time s', 'fontsize', zihao, 'Interpreter', 'latex');
    ylabel(['$\mathrm{IAE(average)} $ '], 'fontsize', zihao, 'Interpreter', 'latex');
%     print(fig,['iae_mean','_gradual.eps'],'-r600','-depsc'); % 设置图片格式、分辨率
        
    fig=figure;hold on;box on;
    %         plot(t,q(:,i),'linewidth',lw);
    for j=1:length(data)
%         plot(t,q(:,i)-data{1,j}(:,i),'linewidth',lw);
         plot(t,cumsum(mean(abs(q-data{2,j}(:,1:6)),2))*dt,'linewidth',lw);
    end
%         ylim([-0.001,0.001]);
    %     axis([t(1) t(end) 0 0.1]);
    set(gca, 'fontsize', zihao);
    set(gcf,'unit','normalized','position',winsize);
    set (gca,'position',xysize);
    legend([ leg],'NumColumns', 4,'Location', 'north')
    xlabel('Time s', 'fontsize', zihao, 'Interpreter', 'latex');
    ylabel(['$\mathrm{IAE(average)} $ '], 'fontsize', zihao, 'Interpreter', 'latex');
%     print(fig,['iae_mean','_step.eps'],'-r600','-depsc'); % 设置图片格式、分辨率
%%
% figure;hold on;box on;
idsubplo=[231 232 233 234 235 236];
for i=1:6
    figure;hold on;box on;
    %       subplot(idsubplo(i));hold on;
    for j=1:length(data)
        plot(t,abs(data{1,j}(:,24+i)),'-','linewidth',lw);
    end
    %     axis([t(1) t(end) 0 0.1]);
    ylim([0,150]);
    set(gca, 'fontsize', zihao);
    set(gcf,'unit','normalized','position',winsize);
    set (gca,'position',xysize);
    xlabel('Time s', 'fontsize', zihao, 'Interpreter', 'latex');
    ylabel( [ '${ \mathrm |{\tau_{fb}^{' num2str(i) '}}(t)|}\mathrm{N\cdot m} $'], 'fontsize', zihao, 'Interpreter', 'latex');
    legend([leg],'NumColumns', 4,'Location', 'north')
end
for i=1:6
    figure;hold on;box on;
    %       subplot(idsubplo(i));hold on;
    for j=1:length(data)
        plot(t,abs(data{2,j}(:,24+i)),'-','linewidth',lw);
    end
    %     axis([t(1) t(end) 0 0.1]);
%     ylim([0,150]);
    set(gca, 'fontsize', zihao);
    set(gcf,'unit','normalized','position',winsize);
    set (gca,'position',xysize);
    xlabel('Time s', 'fontsize', zihao, 'Interpreter', 'latex');
    ylabel( [ '${ \mathrm |{\tau_{fb}^{' num2str(i) '}}(t)|}\mathrm{N\cdot m} $'], 'fontsize', zihao, 'Interpreter', 'latex');
    legend([leg],'NumColumns', 4,'Location', 'north')
end
for i=1:6
    figure;hold on;box on;
    %       subplot(idsubplo(i));hold on;
    for j=1:length(data)
        plot(t,abs(data{3,j}(:,24+i)),'-','linewidth',lw);
    end
    %     axis([t(1) t(end) 0 0.1]);
%     ylim([0,150]);
    set(gca, 'fontsize', zihao);
    set(gcf,'unit','normalized','position',winsize);
    set (gca,'position',xysize);
    xlabel('Time s', 'fontsize', zihao, 'Interpreter', 'latex');
    ylabel( [ '${ \mathrm |{\tau_{fb}^{' num2str(i) '}}(t)|}\mathrm{N\cdot m} $'], 'fontsize', zihao, 'Interpreter', 'latex');
    legend([leg],'NumColumns', 4,'Location', 'north')
end