function [sys,x0,str,ts,simStateCompliance] = update(t,x,u,flag)
switch flag,

  %%%%%%%%%%%%%%%%%%
  % Initialization %
  %%%%%%%%%%%%%%%%%%
  case 0,
    [sys,x0,str,ts,simStateCompliance]=mdlInitializeSizes;

  %%%%%%%%%%%%%%%
  % Derivatives %
  %%%%%%%%%%%%%%%
  case 1,
    sys=mdlDerivatives(t,x,u);

  %%%%%%%%%%
  % Update %
  %%%%%%%%%%
  case 2,
    sys=mdlUpdate(t,x,u);

  %%%%%%%%%%%
  % Outputs %
  %%%%%%%%%%%
  case 3,
    sys=mdlOutputs(t,x,u);

  %%%%%%%%%%%%%%%%%%%%%%%
  % GetTimeOfNextVarHit %
  %%%%%%%%%%%%%%%%%%%%%%%
  case 4,
    sys=mdlGetTimeOfNextVarHit(t,x,u);

  %%%%%%%%%%%%%
  % Terminate %
  %%%%%%%%%%%%%
  case 9,
    sys=mdlTerminate(t,x,u);

  %%%%%%%%%%%%%%%%%%%%
  % Unexpected flags %
  %%%%%%%%%%%%%%%%%%%%
  otherwise
    DAStudio.error('Simulink:blocks:unhandledFlag', num2str(flag));

end

function [sys,x0,str,ts,simStateCompliance]=mdlInitializeSizes


sizes = simsizes;

sizes.NumContStates  = 0;
sizes.NumDiscStates  = 0;
sizes.NumOutputs     = 6;
sizes.NumInputs      = 42;
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

function sys=mdlOutputs(t,x,u)
global dfnn;
global efs;
global lwpr;

load xmax;load xmin;
e=u(1:6)';
ed=u(7:12)';
q=u(13:18)';
qd=u(19:24)';
qdd=u(25:30)';
tau=u(31:36)';
dqdd=u(37:42)';



x=([q,qd,qdd]-xmin)./(xmax-xmin);
x1=([q,qd,dqdd]-xmin)./(xmax-xmin);

uff=zeros(1,6);
for i=1:6
    uff(i)=dfnn(i).Pred(x);
end


tau_error=tau-uff;
Kp=8;Kd=1;
%delt_u=10.*(Kp.*e+Kd.*ed);
delt_u=1*tau.*Fls(e/0.05,ed/0.5);


efs=efs.organize([x;x1]);
efs = efs.ConsequentUpdate([x;x1],[tau_error;efs.Pred(x1)+delt_u]);

%***************LWPR*****************
% [lwpr,~,~] = lwpr_update(lwpr,x',tau'); 

sys=delt_u;

function sys=mdlGetTimeOfNextVarHit(t,x,u)

sampleTime = 1;    %  Example, set the next hit to be one second later.
sys = t + sampleTime;

function sys=mdlTerminate(t,x,u)

sys = [];


