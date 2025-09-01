function [sys, x0, str, ts, simStateCompliance] = pid_controller(t, x, u, flag)
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
sizes = simsizes;
sizes.NumContStates  = 0;
sizes.NumDiscStates  = 0;
sizes.NumOutputs     = 6;
sizes.NumInputs      = 18;
sizes.DirFeedthrough = 1;
sizes.NumSampleTimes = 0;   % at least one sample time is needed
sys = simsizes(sizes);
x0  = [];
str = [];
ts  = [];
simStateCompliance = 'UnknownSimState';

function sys = mdlOutputs(t, x, u)
e=u(1:6);
ie=u(7:12);
ed=u(13:18);
%仿真
% Kp=1*[200;200;200;5;5;5]*1000;Kd=1*[1000;1000;1000;300;300;300];Ki=1*[10;10;10;5;5;5]*4000;
%收集数据
Kp=1*[100;100;100;5;5;5]*1000;Kd=1*[1500;1500;1500;300;300;300];
upd=(Kp.*e+Kd.*ed)*1;

upd(4) = 0;
upd(5) = 0;
upd(6) = 0;


sys=upd'*1;


