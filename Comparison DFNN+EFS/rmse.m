function out = rmse(y,yp)
%RMSE 此处显示有关此函数的摘要
%   此处显示详细说明
out=sqrt(mean((y-yp).^2));
end

