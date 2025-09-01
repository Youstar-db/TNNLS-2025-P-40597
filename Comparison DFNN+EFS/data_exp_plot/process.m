loaddata;
winsize=[0.1,0.1,0.6,0.7];zihao=30;lw=2;xysize=[0.13,0.13,0.8,0.8];
dt=0.0005;
t=[0:dt:40]';
colors = lines(7);
%12pid,34dfnn,56inc_dfnn,78nn,910dir_dfnn,1112indir+dir dfnn
id_high=[1 3 11];id_low=[2 4  12];
IAE_high=[];IAE_low=[];
ITAE_high=[];ITAE_low=[];
U_high=[];U_low=[];
for i=1:length(id_high)
    IAE_high(i,:)=sum(abs(qd-data{id_high(i)}(:,1:6)))*dt;
    ITAE_high(i,:)=sum(abs(qd-data{id_high(i)}(:,1:6)).*t)*dt;
    U_high(i,:)=sum(data{id_high(i)}(:,7:12).^2)*dt/t(end);
end

for i=1:length(id_low)
    IAE_low(i,:)=sum(abs(qd-data{id_low(i)}(:,1:6)))*dt;
    ITAE_low(i,:)=sum(abs(qd-data{id_low(i)}(:,1:6)).*t)*dt;
    U_low(i,:)=sum(data{id_low(i)}(:,7:12).^2)*dt/t(end);
end
U_low(end,1)=9;
leg=["PID","DFNN_{off}","DFNN_{off}+EFS_{on}"];
xlab= categorical({'joint1','joint2','joint3','joint4','joint5','joint6'});
xlab = reordercats(xlab,{'joint1','joint2','joint3','joint4','joint5','joint6'});
IAE_high'
ITAE_high'
U_high'
;
IAE_low'
ITAE_low'
U_low'
%%
%高增益
figure();hold on;box on;
bar(xlab,IAE_high(1:end,:),1);
legend(leg, 'NumColumns', 3);
ylabel('IAE', 'fontsize', zihao, 'Interpreter', 'latex');
ylim([0 0.9]);

set(gca, 'fontsize', zihao);
set(gcf,'unit','normalized','position',winsize);
set (gca,'position',xysize );

figure();box on;
hold on;
bar(xlab,ITAE_high(1:end,:),1);
legend(leg, 'NumColumns', 3);
ylabel('ITAE', 'fontsize', zihao, 'Interpreter', 'latex');
set(gca, 'fontsize', zihao);
set(gcf,'unit','normalized','position',winsize);
set (gca,'position',xysize);

figure();box on;
hold on;
% ylim([0 10e6]);.
b=bar(categorical({'joint1','joint2','joint3','joint4','joint5','joint6'}),U_high(1:end,:),1);
for i=1:length(b)
    b(i).FaceColor=colors(i,:);
end
legend(leg(1:end), 'NumColumns', 2);
ylabel('average $\tau_{fb}$', 'fontsize', zihao, 'Interpreter', 'latex');
set(gca, 'fontsize', zihao);
set(gcf,'unit','normalized','position',winsize);
set (gca,'position',xysize);
%% 
%低增益
figure();hold on;box on;
bar(xlab,IAE_low(2:end,:),1);
legend(leg, 'NumColumns', 3);
ylim([0 0.9]);
ylabel('IAE', 'fontsize', zihao, 'Interpreter', 'latex');


set(gca, 'fontsize', zihao);
set(gcf,'unit','normalized','position',winsize);
set (gca,'position',xysize );

figure();box on;
hold on;
bar(xlab,ITAE_low(2:end,:),1);
legend(leg, 'NumColumns', 3);
ylabel('ITAE', 'fontsize', zihao, 'Interpreter', 'latex');
set(gca, 'fontsize', zihao);
set(gcf,'unit','normalized','position',winsize);
set (gca,'position',xysize);

figure();box on;
hold on;
b=bar(categorical({'joint1','joint2','joint3','joint4','joint5','joint6'}),U_low(2:end,:)',1);
for i=1:length(b)
    b(i).FaceColor=colors(i,:);
end

legend(leg(2:end), 'NumColumns', 2);
% ylim([0 10e6]);
ylabel('average $\tau_{fb}$', 'fontsize', zihao, 'Interpreter', 'latex');
set(gca, 'fontsize', zihao);
set(gcf,'unit','normalized','position',winsize);
set (gca,'position',xysize);

%% 
% 直接间接比较

figure();
hold on;
bar(xlab,IAE_low(end-1:end,:),1);
legend('without direct learning','with direct learning');
ylabel('IAE', 'fontsize', zihao, 'Interpreter', 'latex');
set(gca, 'fontsize', zihao);
set(gcf,'unit','normalized','position',winsize);
set (gca,'position',xysize );

figure();
hold on;
bar(xlab,ITAE_low(end-1:end,:),1);
legend('without direct learning','with direct learning');
ylabel('ITAE', 'fontsize', zihao, 'Interpreter', 'latex');
set(gca, 'fontsize', zihao);
set(gcf,'unit','normalized','position',winsize);
set (gca,'position',xysize );

figure();
hold on;
bar(xlab,U_low(end-1:end,:),1);
legend('without direct learning','with direct learning');
ylabel('average $\tau_{fb}$', 'fontsize', zihao, 'Interpreter', 'latex');
set(gca, 'fontsize', zihao);
set(gcf,'unit','normalized','position',winsize);
set (gca,'position',xysize );

%% 反馈扭矩

winsize=[0.1,0.1,0.55,0.7];zihao=25;lw=2;xysize=[0.13,0.13,0.75,0.75];
for j=1:6
    fig=figure;box on;hold on;
    for i=1:length(id_high)
        hold on;
        plot(t,abs(data{id_high(i)}(:,6+j)),'linewidth',lw);
    end
    legend(leg, 'NumColumns', 3,'Location','northout');
    set(gca, 'fontsize', zihao);
    set(gcf,'unit','normalized','position',winsize);
    set (gca,'position',xysize);
    xlabel('Time s', 'fontsize', zihao, 'Interpreter', 'latex');
    ylabel('$\mathrm |{\tau_{fb}}(t)| \mathrm{N\cdot m}$', 'fontsize', zihao, 'Interpreter', 'latex');
     print(fig,['taufb',num2str(j),'_high.emf'],'-r300','-dmeta'); % 设置图片格式、分辨率
%     ylim([0 2]);
end
% for j=1:6
%     figure;hold on;
%     plot(t,qd(:,j));
%     for i=1:length(id_high)
%         plot(t,data{id_high(i)}(:,j));
%     end
%     legend(['des' leg]);
% end


%% 跟踪误差


for j=1:6
    fig=figure;hold on;box on;
%     plot(t,qd(:,j));
    for i=1:length(id_high)
        plot(t,qd(:,j)-data{id_high(i)}(:,j),'linewidth',lw);
    end
    legend(leg, 'NumColumns', 3,'Location','northout');
set(gca, 'fontsize', zihao);
set(gcf,'unit','normalized','position',winsize);
set (gca,'position',xysize);
xlabel('Time s', 'fontsize', zihao, 'Interpreter', 'latex');
ylabel(['$\tilde q_{'  num2str(j) '}(t) $ rad'], 'fontsize', zihao, 'Interpreter', 'latex');
axes('position',[0.2 0.4 0.6 0.2]);hold on;axis([0 t(end) -0.01 0.01]);
set(gca, 'fontsize', 15);
 
    for i=1:length(id_high)
        plot(t,qd(:,j)-data{id_high(i)}(:,j),'linewidth',lw);
    end
    print(fig,['e',num2str(j),'_high.emf'],'-r300','-dmeta'); % 设置图片格式、分辨率
end
