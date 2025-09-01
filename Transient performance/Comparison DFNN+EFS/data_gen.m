load puma1;Data1=puma1(100:end-1,:);
load puma2;Data2=puma2(100:end-1,:);
load puma3;Data3=puma3(100:end-1,:);
load puma4;Data4=puma4(100:end-1,:);
load puma5;Data5=puma5(100:end-1,:);
load puma6;Data6=puma6(100:end-1,:);
load puma7;Data7=puma7(100:end-1,:);
load puma8;Data8=puma8(100:end-1,:);
load puma9;Data9=puma9(100:end-1,:);
load puma10;Data10=puma10(100:end-1,:);
data=[Data1;Data2;Data3;Data4;Data5;Data6;Data7;Data8;Data9;Data10];
% load Data_exp412;
% data=Data_exp;

% data=round(data,2);

X=data(:,1:end-6);
Y=data(:,end-5:end);
q=X(:,1:6);
ymax=max(Y)
ymin=min(Y)
xmax=max(X)
xmin=min(X)
X=(X-min(X))./(max(X)-min(X));

% X=X+0.0*randn(size(X));

x_train=X(1:40000,:);
y_train=Y(1:40000,:);
randIndex = randperm(size(X,1));
% X=X(randIndex,:);Y=Y(randIndex,:);

x_test=X(40001:end,:);
y_test=Y(40001:end,:);