function delt_u = Fls( error,d_error )
%FLS 此处显示有关此函数的摘要
%   此处显示详细说明
n=length(error);
delt_u=zeros(1,n);
for k=1:n
    mf=ones(3,3);
    C=[-1 1 0.5;-0.5 0 -0.5;0.5 1 -1];
    for i=1:3
        for j=1:3
            mf(i,j)=MF(error(k),i)*MF(d_error(k),j);
        end
    end
    delt_u(k)=sum((sum(mf.*C)));
end
end

function mf=MF(e,n)
switch n
    case 1
    if(e<-1)
        mf=1;
    elseif(e>=-1&&e<=0)
        mf=-e;
    elseif(e>0&&e<=1)
        mf=e;
    else
        mf=0;
    end
    case 2
    if(e>=-1&&e<=0)
        mf=e+1;
    elseif(e>0&&e<=1)
        mf=-e+1;
    else
        mf=0;
    end
    case 3
    if(e<0)
        mf=0;
    elseif(e>=0&&e<=1)
        mf=e;
    else
        mf=1;
    end
end
end