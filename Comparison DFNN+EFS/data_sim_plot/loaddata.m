% load pid_h;
% load lwpr_h;
% load dfnn_h;
% load dfnn_efs_h;
% load rne_h;
% load dfnn_efs_exp;
% load pid_exp;
% load dfnn_exp;
% load lwpr_exp;
% load rne_exp;
% load dfnn_efs_step;
% load lwpr_step;
% load dfnn_step;
% load pid_step;
% load rne_step;
% load g_step;
% 
% 
% 
% data=[];
% data{1,1}=pid_exp;
% data{1,2}=dfnn_exp;
% data{1,3}=lwpr_exp;
% data{1,4}=dfnn_efs_exp;
% data{1,5}=rne_exp;
% 
% data{2,1}=pid_step;
% data{2,2}=dfnn_step;
% data{2,3}=lwpr_step;
% data{2,4}=dfnn_efs_step;
% data{2,5}=rne_step;
% 

desiredtraj;
load pid_step;
load dfnn_step;
load dfnn_efs_step;
load lwpr_step;
load pid_exp;
load dfnn_efs_exp;
load lwpr_exp;
load dfnn_exp;
data{1,1}=pid_exp;
data{1,2}=dfnn_exp;
data{1,3}=lwpr_exp;
data{1,4}=dfnn_efs_exp;

data{2,1}=pid_step;
data{2,2}=dfnn_step;
data{2,3}=lwpr_step;
data{2,4}=dfnn_efs_step;

% data{3,1}=pid_h;
% data{3,2}=dfnn_h;
% data{3,3}=lwpr_h;
% data{3,4}=dfnn_efs_h;
% data{3,5}=rne_h;
