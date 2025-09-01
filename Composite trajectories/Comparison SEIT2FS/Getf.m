function [sys, x0, str, ts, simStateCompliance] = Getf(t, x, u, flag, robot)

switch flag,
    case 0,
        [sys, x0, str, ts, simStateCompliance] = mdlInitializeSizes(robot);

    case {1, 2, 4, 9},
        sys = [];
    case 3,
        sys = mdlOutputs(t, x, u, robot);
    otherwise
        DAStudio.error('Simulink:blocks:unhandledFlag', num2str(flag));
end

function [sys, x0, str, ts, simStateCompliance] = mdlInitializeSizes(robot)
global M;
M=[robot.links(1:3).m];

sizes = simsizes;
sizes.NumContStates  = 0;
sizes.NumDiscStates  = 0;
sizes.NumOutputs     = 6;
sizes.NumInputs      = 18;
sizes.DirFeedthrough = 1;
sizes.NumSampleTimes = 1;   % at least one sample time is needed
sys = simsizes(sizes);

x0  = [];
str = [];
ts  = [-1 0];
simStateCompliance = 'UnknownSimState';

function sys = mdlOutputs(t, x, u, robot)
global M;

load xmax;load xmin;%上下限

x_in = (reshape(u(1:18),[1,18]));
x_in=(x_in-xmin)./(xmax-xmin);%归一化

if t>2*pi
    for i=1:3
         robot.links(i).m=M(i)*(4-3*exp(-0.3*(t-pi)));
         % robot.links(i).m=M(i)*1.3;
    end
end

global efs_model_1
if efs_model_1.Num_Rule == 0
    sys = [0 0 0 0 0 0];
else

[u_efs_1] = efs_model_1.output_calculation(x_in);

sys = [u_efs_1(1) u_efs_1(2) u_efs_1(3) 0 0 0];

end
