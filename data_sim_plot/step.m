
clc
close all

desiredtraj;
load pid_step;
load dfnn_efs_step;
load lwpr_step;
load dfnn_step;
load LGPR_step;
i=1;
data{i}=pid_step;i=i+1;
data{i}=dfnn_step;i=i+1;
data{i}=lwpr_step;i=i+1;
data{i}=LGPR_step;i=i+1;
data{i}=dfnn_efs_step;i=i+1;

winsize=[0.1,0.1,0.6,0.7];zihao=30;lw=2;xysize=[0.13,0.13,0.8,0.8];
leg=["PID","DFNN_{off}","LWPR","LGPR","DFNN_{off}+EFS_{on}"];
xlab= categorical({'joint1','joint2','joint3','joint4','joint5','joint6'});
xlab = reordercats(xlab,{'joint1','joint2','joint3','joint4','joint5','joint6'});


IAE=zeros(6,5);
ITAE=zeros(6,5);
U=zeros(6,5);
RMSE=zeros(6,5);
for i=1:6
    for j=1:length(data)
        IAE(i,j)=(iae(q(:,i),data{j}(:,i),dt));
        ITAE(i,j)=(ite(q(:,i)-data{j}(:,i),t,dt));
        U(i,j)=(sum(abs(data{j}(:,24+i)),1)*dt/t(end));
        RMSE(i,j) =  sqrt(mean((q(:,i) - data{j}(:,i)) .^ 2));
    end
end

% error
for i=1:6
    fig=figure;hold on;box on;
    for j=1:5
        plot(t,abs(q(:,i)-data{j}(:,i)),'linewidth',lw);
    end
    ylim([0,0.001]);
    set(gca, 'fontsize', zihao);
    set(gcf,'unit','normalized','position',winsize);
    set(gca,'position',[0.1, 0.13, 0.85, 0.8]);
    set(gcf, 'Color', 'w');
    set(gca, 'LineWidth', 1);
    legend(leg,'NumColumns', 5,'Location', 'north')
    xlabel('Time s', 'fontsize', zihao, 'Interpreter', 'latex');
    ylabel(['$|\tilde q_{' num2str(i) '}(t) |$ rad'], 'fontsize', zihao, 'Interpreter', 'latex');

end

% traj
winsize = [0.1, 0.1, 0.6, 0.7];
lw = 2;
leg_traj = ["Desired Trajectory", "PID", "DFNN_{off}", "LWPR", "LGPR", "DFNN_{off}+EFS_{on}"];
zihao2 = 18;

color_map.Desired = '#000000';
color_map.PID     = '#FF0000';
color_map.DFNN    = '#779043';
color_map.LWPR    = '#800080';
color_map.LGPR    = '#CD5C5C';
color_map.EFS     = '#0000FF';

color_order = { color_map.Desired, color_map.PID, color_map.DFNN, ...
    color_map.LWPR, color_map.LGPR, color_map.EFS };
for fig_id = 1:3
    figure; clf;
    set(gcf, 'unit', 'normalized', 'position', winsize);

    set(gcf, 'Color', 'w');
    h_legends = gobjects(1,6);
    for subplot_id = 1:2
        joint_id = (fig_id - 1) * 2 + subplot_id;

        subplot(2,1,subplot_id); hold on; box on;

        % Desired trajectory
        h_legends(1) = plot(t, q(:,joint_id), '--','Color', color_order{1}, 'LineWidth', lw);
        for j = 1:5
            h_legends(j+1) = plot(t, data{j}(:,joint_id), 'Color', color_order{j+1}, 'LineWidth', lw);
        end
        set(gca, 'LineWidth', 1);
        set(gca, 'fontsize', zihao2);
        xlabel('Time s', 'fontsize', zihao2, 'Interpreter', 'latex');
        ylabel(['$|\tilde q_{' num2str(joint_id) '}(t)|$ rad'], 'fontsize', zihao2, 'Interpreter', 'latex');
    end
    lgd = legend(h_legends, leg_traj, ...
        'NumColumns', 6, ...
        'Orientation', 'horizontal', ...
        'FontSize', zihao2-2);

end

fig=figure;hold on;box on;
for j=1:5
    plot(t,cumsum(mean(abs(q-data{j}(:,1:6)),2))*dt,'linewidth',lw);
end
set(gca, 'fontsize', zihao);
set(gcf,'unit','normalized','position',winsize);
%set (gca,'position',xysize);
set(gcf, 'Color', 'w');
set(gca, 'LineWidth', 1);
set(gca,'position',[0.1, 0.13, 0.85, 0.8]);
legend(leg,'NumColumns', 5,'Location', 'north')
xlabel('Time s', 'fontsize', zihao, 'Interpreter', 'latex');
ylabel(['$\mathrm{IAE(average)} $ '], 'fontsize', zihao, 'Interpreter', 'latex');

%print(fig,['iae_mean','_gradual.emf'],'-r600','-dmeta'); % 保存图片


%print(fig,['iae_mean','_gradual.emf'],'-r600','-dmeta'); % 保存图片