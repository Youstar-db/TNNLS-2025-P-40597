clc
close all

%desiredtraj;
load FTC_composite;
load IT2FLFNN_composite;
load SEIT2DSDIC_composite;
load DFNN_EFS_composite;
load traj_des_composite;

dt=0.001;
t=0:dt:4*pi;

i=1;
data{i}=FTC_composite;i=i+1;
data{i}=IT2FLFNN_composite;i=i+1;
data{i}=SEIT2DSDIC_composite;i=i+1;
data{i}=DFNN_EFS_composite;i=i+1;

q = traj_des_composite;

winsize=[0.1,0.1,0.6,0.7];zihao=30;lw=2;xysize=[0.13,0.13,0.8,0.8];
leg=["AFTFTC","IT2FLFNN","SEIT2FS-ILLC","DFNN_{off}+EFS_{on}"];
xlab= categorical({'joint1','joint2','joint3'});
xlab = reordercats(xlab,{'joint1','joint2','joint3'});


IAE=zeros(3,4);
ITAE=zeros(3,4);
RMSE=zeros(3,4);
for i=1:3
    for j=1:length(data)
        IAE(i,j)=(iae(q(:,i),data{j}(:,i),dt));
        ITAE(i,j)=(ite(q(:,i)-data{j}(:,i),t',dt));
        RMSE(i,j) =  sqrt(mean((q(:,i) - data{j}(:,i)) .^ 2));
    end
end
IAE_avg = mean(IAE,1)
ITAE_avg = mean(ITAE,1)
RMSE_avg = mean(RMSE,1)

    fig=figure;hold on;box on;
    for i=1:3
        plot(t',q(:,i),'linewidth',lw);
    end
    xlim([0,4*pi]);
    set(gca, 'fontsize', zihao);
    set(gcf,'unit','normalized','position',winsize);
    set(gca,'position',[0.1, 0.13, 0.85, 0.8]);
    set(gcf, 'Color', 'w');
    set(gca, 'LineWidth', 1);
    legend(leg,'NumColumns', 5,'Location', 'north')
    xlabel('Time s', 'fontsize', zihao, 'Interpreter', 'latex');
    ylabel(['$q_{3}(t) \quad q_{1}(t) \quad q_{2}(t)$ rad'], 'fontsize', zihao, 'Interpreter', 'latex');


% error
for i=1:3
    fig=figure;hold on;box on;
    for j=1:4
        plot(t',abs(q(:,i)-data{j}(:,i)),'linewidth',lw);
    end
    xlim([0,4*pi]);
    set(gca, 'fontsize', zihao);
    set(gcf,'unit','normalized','position',winsize);
    set(gca,'position',[0.1, 0.13, 0.85, 0.8]);
    set(gcf, 'Color', 'w');
    set(gca, 'LineWidth', 1);
    legend(leg,'NumColumns', 5,'Location', 'north')
    xlabel('Time s', 'fontsize', zihao, 'Interpreter', 'latex');
    ylabel(['$|\tilde q_{' num2str(i) '}(t) |$ rad'], 'fontsize', zihao, 'Interpreter', 'latex');
    
end

% % traj
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
        h_legends(1) = plot(t, q(:,joint_id), '--' ,'Color', color_order{1}, 'LineWidth', lw);
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
for j=1:4
    plot(t,cumsum(mean(abs(q-data{j}(:,1:6)),2))*dt,'linewidth',lw);
end
set(gca, 'fontsize', zihao);
set(gcf,'unit','normalized','position',winsize);
set(gcf, 'Color', 'w');
set(gca, 'LineWidth', 1);
set(gca,'position',[0.1, 0.13, 0.85, 0.8]);
legend(leg,'NumColumns', 5,'Location', 'north')
xlabel('Time s', 'fontsize', zihao, 'Interpreter', 'latex');
ylabel(['$\mathrm{IAE(average)} $ '], 'fontsize', zihao, 'Interpreter', 'latex');

%print(fig,['iae_mean','_gradual.emf'],'-r600','-dmeta');
