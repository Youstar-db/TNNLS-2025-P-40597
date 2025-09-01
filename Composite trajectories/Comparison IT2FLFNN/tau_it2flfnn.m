function [sys,x0,str,ts,simStateCompliance] = tau_it2flfnn(t,x,u,flag,robot)
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
global init rule;
init = [];
input = zeros(3,1);
[rule]=IT2_init(input);

sizes = simsizes;
sizes.NumContStates  = 0;
sizes.NumDiscStates  = 0;
sizes.NumOutputs     = 6;
sizes.NumInputs      = 30;
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
global init rule threshold_init threshold_delete;

if t>2*pi
    for i=1:3
        robot.links(i).m=M(i)*(4-3*exp(-0.3*(t-2*pi)));
    end
end


alpha=0.5; Te=0.75;
kappa=0.5; Ts=0.75;
varepsilon1=3;
varepsilon2=1;
delta=0.005;
tho=0.2;
n=3;

q = u(1:6);
q_desire = u(7:12);
dq = u(13:18);
dq_desire = u(19:24);
ddq_desire = u(25:30);

M0=robot.inertia(q');
C0=robot.coriolis(q',dq');
G0=robot.gravload(q');

error=q_desire-q;
derror=dq_desire-dq;


for j=1:6
    if error(j)>delta
        error_S_alpha(j)=power(abs(error(j)),(1-alpha))*sign(error(j));
    else
        error_S_alpha(j)=delta^(-alpha)*error(j)';
    end
    error_S_alpha = error_S_alpha';
end
error_Sig_alpha=power(abs(error),(1+alpha)).*sign(error);


for j=1:6
    if abs(error(j))>delta
        error_F_alpha(j)=(1-alpha)*abs(power(error(j),-alpha))*derror(j)';
    else
        error_F_alpha(j)=delta^(-alpha)*derror(j)';
    end
    error_F_alpha = error_F_alpha';
end
error_D_alpha=(1+alpha)*abs(power(error,alpha)).*derror;


s=derror+1/(Te*alpha)*(2*error+error_S_alpha+error_Sig_alpha);
s_Sig_kappa1=power(abs(s),(1-kappa)).*sign(s);
s_Sig_kappa2=(n+1)^(kappa/2)*power(abs(s),(1+kappa)).*sign(s);

u_sm=1/(Te*alpha)*M0*(2*derror+error_F_alpha+error_D_alpha)+...
    1/(Ts*kappa)*M0*(2*s+s_Sig_kappa1+s_Sig_kappa2)+...
    M0*ddq_desire+C0*dq+G0';

input=s(1:3);

% if isempty(init)
%     init = 1;
%     [rule]=IT2_init(input);
% 
% else
    [rule,threshold_init,threshold_delete] = IT2_self_organize(rule,input);
% end

[rule] = IT2_adaption(rule,input);

[O,rule]=IT2_output(rule,input);

u_IT2=M0*[O;zeros(3,1)];

if norm(s)>tho
    u_nc=M0*varepsilon1*sign(s)+1/(Ts*kappa)*M0*s/(norm(s)^2)*(2*varepsilon2+(varepsilon2)^(1-kappa/2)+4^(kappa/2)*(varepsilon2)^(1+kappa/2));
    u_sa=norm(u_sm+u_IT2+u_nc)/norm(s)*(1-0.65)*s;
else
    u_nc=M0*varepsilon1*s/tho+1/(Ts*kappa)*M0*s/tho^2*(2*varepsilon2+(varepsilon2)^(1-kappa/2)+4^(kappa/2)*(varepsilon2)^(1+kappa/2));
    u_sa=norm(u_sm+u_IT2+u_nc)/tho*(1-0.65)*s;
end

u=u_sm+u_IT2+u_nc+u_sa;
u(4)=0;
u(5)=0;
u(6)=0;


sys=u;

function sys=mdlGetTimeOfNextVarHit(t,x,u)

sampleTime = 1;
sys = t + sampleTime;

function sys=mdlTerminate(t,x,u)

sys = [];


