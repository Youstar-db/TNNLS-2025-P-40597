desiredtraj;
load pid_step;
load dfnn_step;
load dfnn_efs_step;
load lwpr_step;
i=1;
data{i}=pid_step;i=i+1;
data{i}=dfnn_step;i=i+1;
data{i}=lwpr_step;i=i+1;
data{i}=dfnn_efs_step;i=i+1;

winsize=[0.1,0.1,0.55,0.7];zihao=25;lw=2;xysize=[0.13,0.13,0.75,0.75];
winsize=[0.1,0.1,0.6,0.7];zihao=30;lw=2;xysize=[0.13,0.13,0.8,0.8];
leg=["PID","DFNN_{off}","LWPR","DFNN_{off}+EFS_{on}"];
xlab= categorical({'joint1','joint2','joint3','joint4','joint5','joint6'});
xlab = reordercats(xlab,{'joint1','joint2','joint3','joint4','joint5','joint6'});


for i=1:6
    for j=1:length(data)
        iae(i,j)=(IAE(q(:,i),data{j}(:,i),dt));
        ITAE(i,j)=(ite(q(:,i)-data{j}(:,i),t,dt));
        U(i,j)=(sum(abs(data{j}(:,24+i)),1)*dt/t(end));
        %         RMSE(:,i)=mean(cumsum(abs(q-data{i}(:,1:6)))*dt./t,2);
    end
end
% round(iae*1000,2)
% round(ITAE*1000,2)
% round(U,2)


%%

for i=1:6
    fig=figure;hold on;box on;
    %plot(t,q(:,i),'linewidth',lw);
    for j=1:4
        plot(t,abs(q(:,i)-data{j}(:,i)),'linewidth',lw);
    end
    %         ylim([0,0.002]);
    set(gca, 'fontsize', zihao);
    set(gcf,'unit','normalized','position',winsize);
    set (gca,'position',xysize);
    legend([ leg],'NumColumns', 4,'Location', 'north')
    xlabel('Time s', 'fontsize', zihao, 'Interpreter', 'latex');
    ylabel(['$|\tilde q_{'  num2str(i) '}(t) |$ rad'], 'fontsize', zihao, 'Interpreter', 'latex');
    axes('position',[0.2 0.4 0.6 0.2]);hold on;axis([0 t(end) 0 0.0005]);
    set(gca, 'fontsize', 15);
    
    for j=1:4
        plot(t,abs(q(:,i)-data{j}(:,i)),'linewidth',lw);
    end
%         print(fig,['e',num2str(i),'_step.emf'],'-r400','-dmeta'); % 设置图片格式、分辨率
end
%%

fig=figure;hold on;box on;
for j=1:4
    plot(t,cumsum(mean(abs(q-data{j}(:,1:6)),2))*dt,'linewidth',lw);
end
%         ylim([-0.001,0.001]);
set(gca, 'fontsize', zihao);
set(gcf,'unit','normalized','position',winsize);
set (gca,'position',xysize);
legend([ leg],'NumColumns', 4,'Location', 'north')
xlabel('Time s', 'fontsize', zihao, 'Interpreter', 'latex');
ylabel(['$\mathrm{IAE(average)} $ '], 'fontsize', zihao, 'Interpreter', 'latex');
%     print(fig,['iae_mean','_step.emf'],'-r400','-dmeta'); % 保存图片


