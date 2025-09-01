function f = fuzzy(x)
%FUZZY 此处显示有关此函数的摘要
%   此处显示详细说明
f=zeros(size(x,1),5*size(x,2));
c=[-1 -0.5 0 0.5 1];
for i=1:size(x,2)
    f(:,(i-1)*5+1:(i-1)*5+5)=exp(-(x(:,i)-c).^2/2/0.3^2);
end

% f=zeros(size(x,1),3*size(x,2));
% c=[0 0.5 1];
% for i=1:size(x,2)
%     f(:,(i-1)*3+1:(i-1)*3+3)=exp(-(x(:,i)-c).^2/2/0.3^2);
% end
end

