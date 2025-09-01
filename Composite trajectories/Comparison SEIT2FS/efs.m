function [sys, x0, str, ts, simStateCompliance] = efs(t, x, u, flag)
switch flag,
    case 0,
        [sys, x0, str, ts, simStateCompliance] = mdlInitializeSizes;
    case {1, 2, 4, 9},
        sys = [];
    case 3,
        sys = mdlOutputs(t, x, u);
    otherwise
        DAStudio.error('Simulink:blocks:unhandledFlag', num2str(flag));
end
function [sys, x0, str, ts, simStateCompliance] = mdlInitializeSizes
global efs_model_1 
% if isempty(efs_model_1)
    %% 模型参数初始化
    efs_model_1 = SEIT2FS(ones(1,18),zeros(1,6));

% end
sizes = simsizes;
sizes.NumContStates  = 0;
sizes.NumDiscStates  = 0;
sizes.NumOutputs     = 1;
sizes.NumInputs      = 24;
sizes.DirFeedthrough = 1;
sizes.NumSampleTimes = 1;   % at least one sample time is needed
sys = simsizes(sizes);
x0  = [];
str = [];
ts  = [-1 0];
simStateCompliance = 'UnknownSimState';

function sys = mdlOutputs(t, x, u)
% 12 input
global efs_model_1 
load xmax;load xmin;%上下限

xn = reshape(u(1:18), [1,18]);
xn=(xn-xmin)./(xmax-xmin);%归一化


yn = reshape(u(19:24), [1,6]);
error = zeros(1,6);

[efs_model_1,~] = efs_model_1.rule_evolve(xn, yn, error);
sys=efs_model_1.Num_Rule;

