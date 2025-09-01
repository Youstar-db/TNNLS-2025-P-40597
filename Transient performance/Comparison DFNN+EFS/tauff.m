function [sys,x0,str,ts,simStateCompliance] = tauff(t,x,u,flag,robot)
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
global dfnn;
load dfnn_sim_6;
dfnn=dfnn_sim_6;

global M;
M=[robot.links(1:3).m];

global efs;
data_gen;
efs=ENFIS(x_train,6,0.05);

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
global efs;
global dfnn;
global M;
load xmax;load xmin;

x=u(1:18)';
x=(x-xmin)./(xmax-xmin);
uff=zeros(1,6);
%*********dfnn*************
for i=1:6
    uff(i)=dfnn(i).Pred(x);
end
uff=uff+efs.Pred(x);
uff(2) = 0;
uff(3) = 0;
uff(4) = 0;
uff(5) = 0;
uff(6) = 0;
sys=uff;

function sys=mdlGetTimeOfNextVarHit(t,x,u)

sampleTime = 1;
sys = t + sampleTime;

function sys=mdlTerminate(t,x,u)

sys = [];


