function  idx= argmin(A)
%ARGMIN 此处显示有关此函数的摘要
%   此处显示详细说明
[B,I]=sort(A,'ascend');
idx=I(1);
end

