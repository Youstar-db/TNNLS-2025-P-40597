
dt=0.001;
t=[0:dt:20]';
fq=1*ones(1,6);
B=[80 70 70 70 50 120]*pi/180;
q=[B.*sin(fq.*t)]+[0 90 -90 30 0 0]*pi/180;
qd=[B.*fq.*cos(fq.*t)];
qdd=[-B.*fq.*fq.*sin(fq.*t)];
% 
% rng('shuffle');
% k=20;
% a=randn(k,6);
% f=randn(k,6)*0.5*pi+0.7*pi;
% b=randn(k,6)*2*pi;
% winsize=[0.1,0.1,0.6,0.7];zihao=30;lw=2;xysize=[0.13,0.13,0.8,0.8];
% B=[160 135 135 140 100 266]*pi/180;
% for i=1:length(t)
%     q(i,:)=[B.*sum(a.*sin(f*t(i)+b))/k]'+[0 90 -90 30 0 0]'*pi/180;
%     qd(i,:)=[B.*sum(a.*f.*cos(f*t(i)+b))/k]';
%     qdd(i,:)=[B.*sum(-a.*f.*f.*sin(f*t(i)+b))/k]';
% end
% figure;
% plot(t,q,'linewidth',lw);
% legend('q1','q2','q3','q4','q5','q6','NumColumns', 6);
% % ylim([0,60]);
% set(gca, 'fontsize', zihao);
% set(gcf,'unit','normalized','position',winsize);
% set (gca,'position',xysize);
% xlabel('Time s', 'fontsize', zihao, 'Interpreter', 'latex');
% ylabel('$\mathrm{joint angle \ rad}$', 'fontsize', zihao, 'Interpreter', 'latex');