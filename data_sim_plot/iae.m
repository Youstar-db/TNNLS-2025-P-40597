function out = iae(y,yp,dt)
%IAE 此处显示有关此函数的摘要
%   此处显示详细说明
out=sum(abs(y-yp))*dt;
end

