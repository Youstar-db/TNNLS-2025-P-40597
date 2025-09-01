function out = energe(u,dt)
%ENERGE 此处显示有关此函数的摘要
%   此处显示详细说明
out=sum(sum(u.^2*dt));
end

