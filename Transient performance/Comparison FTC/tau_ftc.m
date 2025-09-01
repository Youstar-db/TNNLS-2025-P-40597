function [sys,x0,str,ts,simStateCompliance] = tau_ftc(t,x,u,flag,robot)
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
global M ;
M=[robot.links(1:3).m];
global kappa2 init fuzzy;
init = [];


fuzzy = fuzzy_compensator();

sizes = simsizes;
sizes.NumContStates  = 0;
sizes.NumDiscStates  = 0;
sizes.NumOutputs     = 6;
sizes.NumInputs      = 24;
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
global M;

load xmax;load xmin;

x=u(1:18)';
x=(x-xmin)./(xmax-xmin);

global kappa2 init fuzzy;
% beta = 1; c_1 = 10; c_2= 5; tau2 = 0.9;
beta = 0.95; c_1 = 10; c_2= 10; 

tau2 = 0.15;

q = u(1:6);
q_desire = u(7:12);
e1 = q - q_desire;
dq = u(13:18);
dq_desire = u(19:24);
kappa2_old = kappa2;

M0=robot.inertia(q');
C0=robot.coriolis(q',dq');
G0=robot.gravload(q');


alpha1 = -c_1 * abs(e1).^(2*beta-1).*sign(e1) - e1 + dq_desire;

if isempty(init)
    init = 1;
    kappa2= alpha1;
    s2 = dq - kappa2;
    input1=q(1:3);
    fuzzy = fuzzy.adapt(input1,s2);
    [net_output,~] = fuzzy.output(input1);
    u = inv(M0)*(-c_2 * abs(s2).^(2*beta-1).*sign(s2)-net_output+M0*(C0*dq+G0')-1/2*s2-e1);
else
    kappa2 = (alpha1-kappa2_old)*1e-3/tau2 + kappa2_old;
    s2 = dq - kappa2;
    input1=q(1:3);
    fuzzy = fuzzy.adapt(input1,s2);
    [net_output,~] = fuzzy.output(input1);
    u =  inv(M0)*(-c_2 * abs(s2).^(2*beta-1).*sign(s2)-net_output+M0*(C0*dq+G0')-1/2*s2-e1+(kappa2-kappa2_old)/tau2);
end


u(2)=0;
u(3)=0;
u(4)=0;
u(5)=0;
u(6)=0;
sys = u;

function sys=mdlGetTimeOfNextVarHit(t,x,u)

sampleTime = 1;
sys = t + sampleTime;

function sys=mdlTerminate(t,x,u)

sys = [];


