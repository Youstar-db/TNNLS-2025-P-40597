function [sys, x0, str, ts, simStateCompliance] = FLS(t, x, u, flag)
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
sizes.NumOutputs     = 3;
sizes.NumInputs      = 6;
sizes.DirFeedthrough = 1;
sizes.NumSampleTimes = 0;   % at least one sample time is needed
sys = simsizes(sizes);
x0  = [];
str = [];
ts  = [];
simStateCompliance = 'UnknownSimState';
global fuzzy
fuzzy = fuzzy_compensator();

function sys = mdlOutputs(t, x, u)
global fuzzy
q = [u(1); u(2); u(3)];
dq = [u(4); u(5); u(6)];
fuzzy = fuzzy.adapt(q,dq);
[net_output,~] = fuzzy.output(q);
u = [net_output(1) net_output(2) net_output(3)];
sys = u;

