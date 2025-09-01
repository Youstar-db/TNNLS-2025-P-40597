function [sys,x0,str,ts,simStateCompliance] = m_pid(t,x,u,flag)
switch flag,
  case 0,
    [sys,x0,str,ts,simStateCompliance]=mdlInitializeSizes;
  case 1,
    sys=mdlDerivatives(t,x,u);
  case 2,
    sys=mdlUpdate(t,x,u);
  case 3,
    sys=mdlOutputs(t,x,u);
  case 4,
    sys=mdlGetTimeOfNextVarHit(t,x,u);
  case 9,
    sys=mdlTerminate(t,x,u);
  otherwise
    DAStudio.error('Simulink:blocks:unhandledFlag', num2str(flag));

end

function [sys,x0,str,ts,simStateCompliance]=mdlInitializeSizes
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

function sys=mdlDerivatives(~,x,u)

sys = [];

function sys=mdlUpdate(t,x,u)

sys = [];

function sys=mdlOutputs(t,x,u)
e=u(1:6);
ed=u(7:12);
ie=u(13:18);
Kp=1*[200;200;200;5;5;5]*1000;Kd=1*[1500;1500;1500;300;300;300];
%Kp=1*[100;100;100;5;5;5]*1000; Kd=1*[1500;1500;1500;300;300;300];
upd=(Kp.*e+Kd.*ed);
sys=upd';
% sys(sys>400)=400;
% sys(sys<-400)=-400;

function sys=mdlGetTimeOfNextVarHit(t,x,u)

sampleTime = 1;
sys = t + sampleTime;

function sys=mdlTerminate(t,x,u)

sys = [];

