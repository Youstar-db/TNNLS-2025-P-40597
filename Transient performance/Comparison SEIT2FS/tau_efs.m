function [sys,x0,str,ts,simStateCompliance] = tau_efs(t,x,u,flag,robot)
switch flag,
    case 0,
        [sys,x0,str,ts,simStateCompliance]=mdlInitializeSizes(robot);
    case 1,
        sys=mdlDerivatives(t,x,u);
    case 2,
        sys=mdlUpdate(t,x,u);
    case 3,
        sys=mdlOutputs(t,x,u,robot);
    case 4,
        sys=mdlGetTimeOfNextVarHit(t,x,u);
    case 9,
        sys=mdlTerminate(t,x,u);
    otherwise
        DAStudio.error('Simulink:blocks:unhandledFlag', num2str(flag));

end

function [sys,x0,str,ts,simStateCompliance]=mdlInitializeSizes(robot)
global efs_model M ;

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

function sys=mdlDerivatives(t,x,u)

sys = [];

function sys=mdlUpdate(t,x,u)

sys = [];

function sys=mdlOutputs(t,x,u,robot)
global efs_model M;

load xmax;load xmin;

x=u(1:18)';

x=(x-xmin)./(xmax-xmin);



global efs_model
if efs_model.Num_Rule == 0
    u_out = [0 0 0 0 0 0];
else

    u_efs = efs_model.output_calculation(x);
    u_out = [u_efs(1) 0 0 0 0 0];
end

sys = u_out;
% sys(sys>400)=800;
% sys(sys<-400)=-800;

function sys=mdlGetTimeOfNextVarHit(t,x,u)

sampleTime = 1;
sys = t + sampleTime;


function sys=mdlTerminate(t,x,u)

sys = [];


