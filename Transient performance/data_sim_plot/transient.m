clc
close all


load SEIT2DSDIC_transient;
load IT2FLFNN_transient;
load FTC_transient;
load DFNN_EFS_transient;
load traj_des_transient;

dt=0.001;
t=0:dt:5;

i=1;
data{i}=FTC_transient;i=i+1;
data{i}=IT2FLFNN_transient;i=i+1;
data{i}=SEIT2DSDIC_transient;i=i+1;
data{i}=DFNN_EFS_transient;i=i+1;

q = traj_des_transient;

winsize=[0.1,0.1,0.6,0.7];zihao=30;lw=2;xysize=[0.13,0.13,0.8,0.8];
leg=["AFTFTC","IT2FLFNN", "SEIT2FS-ILLC","DFNN_{off}+EFS_{on}"];
xlab= categorical({'joint1','joint2','joint3','joint4','joint5','joint6'});
xlab = reordercats(xlab,{'joint1','joint2','joint3','joint4','joint5','joint6'});


% error
for i=1:1
    fig=figure;hold on;box on;
    for j=1:4
        plot(t,abs(q(:,i)-data{j}(:,i)),'linewidth',lw);
    end
    % ylim([0,0.001]);
    set(gca, 'fontsize', zihao);
    set(gcf,'unit','normalized','position',winsize);
    set(gca,'position',[0.1, 0.13, 0.85, 0.8]);
    set(gcf, 'Color', 'w');
    set(gca, 'LineWidth', 1);
    legend(leg,'NumColumns', 5,'Location', 'north')
    xlabel('Time s', 'fontsize', zihao, 'Interpreter', 'latex');
    ylabel(['$|\tilde q_{' num2str(i) '}(t) |$ rad'], 'fontsize', zihao, 'Interpreter', 'latex');

end

color_map.Desired = '#000000';
color_map.AFTFTC    = '#0000FF';
color_map.SEIT2DSDIC     = '#FF0000';
color_map.IT2FLFNN    = '#779043';
color_map.EFS    = '#800080';


color_order = { color_map.Desired, color_map.AFTFTC, color_map.SEIT2DSDIC, color_map.IT2FLFNN, ...
    color_map.EFS};
leg_traj=["Desired Trajectory", "AFTFTC","IT2FLFNN", "SEIT2FS-ILLC","DFNN_{off}+EFS_{on}"];
for i=1:1
    fig=figure;hold on;box on;
    fill([0,2.5,2.5,0],[0.475,0.475,0.525,0.525],[1 0.8 0.8],"Facealpha",0.5,"EdgeColor","none");
    fill([2.5,5,5,2.5],[-0.025,-0.025,0.025,0.025],[1 0.8 0.8],"Facealpha",0.5,"EdgeColor","none");


    plot1 = plot(t, q(:,1), '--' ,'Color', color_order{1}, 'LineWidth', lw);
    hold on
    plot2 = plot(t, data{1}(:,i), '--' ,'Color', color_order{2}, 'LineWidth', lw);
    hold on
    plot3 = plot(t, data{2}(:,i), '--' ,'Color', color_order{3}, 'LineWidth', lw);
    hold on
    plot4 = plot(t, data{3}(:,i), '--' ,'Color', color_order{4}, 'LineWidth', lw);
    hold on
    plot5 = plot(t, data{4}(:,i), '--' ,'Color', color_order{5}, 'LineWidth', lw);
    % ylim([0,0.001]);

    set(gca, 'fontsize', zihao);
    set(gcf,'unit','normalized','position',winsize);
    set(gca,'position',[0.11, 0.13, 0.85, 0.8]);
    set(gcf, 'Color', 'w');
    set(gca, 'LineWidth', 1);
    legend([plot1,plot2,plot3,plot4,plot5], leg_traj,'NumColumns', 5,'Location', 'north', 'FontSize', 18)
    xlabel('Time s', 'fontsize', zihao, 'Interpreter', 'latex');
    ylabel('Trajectory', 'fontsize', zihao, 'Interpreter', 'latex');

end

