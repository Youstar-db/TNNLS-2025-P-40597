function [sys,x0,str,ts,simStateCompliance] = taulgpr(t,x,u,flag,robot)
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
global M;
M=[robot.links(1:6).m];
global O_LGPR;
input_dim = 18;
output_dim = 6;
N_max = 50;
lambda = 0.2;
sigma_f = 1;
sigma_n = 0.05;
O_LGPR = LGPR(input_dim, output_dim, N_max, lambda, sigma_f, sigma_n);


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
global O_LGPR M;

load xmax;load xmin;

x=u(1:18)';%q，qd，qdd
x_t=(x-xmin)./(xmax-xmin);

if t>10
    for i=1:6
        robot.links(i).m=M(i)*(4-3*exp(-0.3*(t-10)));
    end
end

%*************LGPR***********
ulgpr = O_LGPR.predict(x_t);

sys=ulgpr';

function sys=mdlGetTimeOfNextVarHit(t,x,u)

sampleTime = 1;
sys = t + sampleTime;

function sys=mdlTerminate(t,x,u)

sys = [];

