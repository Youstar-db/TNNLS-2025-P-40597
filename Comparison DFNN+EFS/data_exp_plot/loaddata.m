clear;close all;
len=2000*40;%40s
%high：高反馈增益
%low：低反馈增益
%ind：间接，dir：直接+间接
load high_dfnn
q_dfnn=[q_degree_0.Value',q_degree_1.Value',q_degree_2.Value',q_degree_3.Value',q_degree_4.Value',q_degree_5.Value']*pi/180;
qd=[q_des_t_0.Value',q_des_t_1.Value',q_des_t_2.Value',q_des_t_3.Value',q_des_t_4.Value',q_des_t_5.Value']*pi/180;
index=find(q_des_t_0.Value~=0);
qd=qd(index(1):index(1)+len,:);
dqd=diff(qd);
dqdd=diff(dqd);

taufb_dfnn=[tau_pd_0.Value',tau_pd_1.Value',tau_pd_2.Value',tau_pd_3.Value',tau_pd_4.Value',tau_pd_5.Value'];
index=find(q_des_t_0.Value~=0);
q_dfnn=q_dfnn(index(1):index(1)+len,:);
e_dfnn=qd-q_dfnn;
taufb_dfnn=taufb_dfnn(index(1):index(1)+len,:);
data{3}=[q_dfnn taufb_dfnn];

load low_dfnn
q_dfnn_low=[q_degree_0.Value',q_degree_1.Value',q_degree_2.Value',q_degree_3.Value',q_degree_4.Value',q_degree_5.Value',]*pi/180;
taufb_dfnn_low=[tau_pd_0.Value',tau_pd_1.Value',tau_pd_2.Value',tau_pd_3.Value',tau_pd_4.Value',tau_pd_5.Value'];

index=find(q_des_t_0.Value~=0);
q_dfnn_low=q_dfnn_low(index(1):index(1)+len,:);

e_pd=qd-q_dfnn_low;
taufb_dfnn_low=taufb_dfnn_low(index(1):index(1)+len,:);
data{4}=[q_dfnn_low taufb_dfnn_low];

load high_pid
q_pd=[q_degree_0.Value',q_degree_1.Value',q_degree_2.Value',q_degree_3.Value',q_degree_4.Value',q_degree_5.Value',]*pi/180;
taufb_pd=[taupd_0.Value',taupd_1.Value',taupd_2.Value',taupd_3.Value',taupd_4.Value',taupd_5.Value'];

index=find(q_des_t_0.Value~=0);
q_pd=q_pd(index(1):index(1)+len,:);

e_pd=qd-q_pd;
taufb_pd=taufb_pd(index(1):index(1)+len,:);
data{1}=[q_pd taufb_pd];

load low_pid
q_pd_low=[q_degree_0.Value',q_degree_1.Value',q_degree_2.Value',q_degree_3.Value',q_degree_4.Value',q_degree_5.Value',]*pi/180;
taufb_pd_low=[taupd_0.Value',taupd_1.Value',taupd_2.Value',taupd_3.Value',taupd_4.Value',taupd_5.Value'];

index=find(q_des_t_0.Value~=0);
q_pd_low=q_pd_low(index(1):index(1)+len,:);
e_pd=qd-q_pd_low;
taufb_pd_low=taufb_pd_low(index(1):index(1)+len,:);
data{2}=[q_pd_low taufb_pd_low];




load high_inc
q_inrnn_high=[q_degree_0.Value',q_degree_1.Value',q_degree_2.Value',q_degree_3.Value',q_degree_4.Value',q_degree_5.Value',]*pi/180;
taufb_inrnn_high=[taupd_0.Value',taupd_1.Value',taupd_2.Value',taupd_3.Value',taupd_4.Value',taupd_5.Value'];
index=find(q_des_t_0.Value~=0);
q_inrnn_high=q_inrnn_high(index(1):index(1)+len,:);
e_inrnn=qd-q_inrnn_high;
taufb_inrnn_high=taufb_inrnn_high(index(1):index(1)+len,:);
data{5}=[q_inrnn_high taufb_inrnn_high];

load low_inc
q_inrnn_low=[q_degree_0.Value',q_degree_1.Value',q_degree_2.Value',q_degree_3.Value',q_degree_4.Value',q_degree_5.Value',]*pi/180;
taufb_inrnn_low=[taupd_0.Value',taupd_1.Value',taupd_2.Value',taupd_3.Value',taupd_4.Value',taupd_5.Value'];
index=find(q_des_t_0.Value~=0);
q_inrnn_low=q_inrnn_low(index(1):index(1)+len,:);
e_inrnn_low=qd-q_inrnn_low;
taufb_inrnn_low=taufb_inrnn_low(index(1):index(1)+len,:);
data{6}=[q_inrnn_low taufb_inrnn_low];


load high_nn
q_high_nn=[q_degree_0.Value',q_degree_1.Value',q_degree_2.Value',q_degree_3.Value',q_degree_4.Value',q_degree_5.Value',]*pi/180;
taufb_high_nn=[taupd_0.Value',taupd_1.Value',taupd_2.Value',taupd_3.Value',taupd_4.Value',taupd_5.Value'];
index=find(q_des_t_0.Value~=0);
q_high_nn=q_high_nn(index(1):index(1)+len,:);
e_high_nn=qd-q_high_nn;
taufb_high_nn=taufb_high_nn(index(1):index(1)+len,:);
data{7}=[q_high_nn taufb_high_nn];


load low_nn
q_low_nn=[q_degree_0.Value',q_degree_1.Value',q_degree_2.Value',q_degree_3.Value',q_degree_4.Value',q_degree_5.Value',]*pi/180;
taufb_low_nn=[taupd_0.Value',taupd_1.Value',taupd_2.Value',taupd_3.Value',taupd_4.Value',taupd_5.Value'];
index=find(q_des_t_0.Value~=0);
q_low_nn=q_low_nn(index(1):index(1)+len,:);
e_low_nn=qd-q_low_nn;
taufb_low_nn=taufb_low_nn(index(1):index(1)+len,:);
data{8}=[q_low_nn taufb_low_nn];

load high_indefs
q_high_indefs=[q_degree_0.Value',q_degree_1.Value',q_degree_2.Value',q_degree_3.Value',q_degree_4.Value',q_degree_5.Value',]*pi/180;
taufb_high_indefs=[tau_pd_0.Value',tau_pd_1.Value',tau_pd_2.Value',tau_pd_3.Value',tau_pd_4.Value',tau_pd_5.Value'];
index=find(q_des_t_0.Value~=0);
q_high_indefs=q_high_indefs(index(1):index(1)+len,:);
taufb_high_indefs=taufb_high_indefs(index(1):index(1)+len,:);
e_high_indefs=qd-q_high_indefs;
data{9}=[q_high_indefs taufb_high_indefs];

load low_indefs
q_low_indefs=[q_degree_0.Value',q_degree_1.Value',q_degree_2.Value',q_degree_3.Value',q_degree_4.Value',q_degree_5.Value',]*pi/180;
taufb_low_indefs=[tau_pd_0.Value',tau_pd_1.Value',tau_pd_2.Value',tau_pd_3.Value',tau_pd_4.Value',tau_pd_5.Value'];
index=find(q_des_t_0.Value~=0);
q_low_indefs=q_low_indefs(index(1):index(1)+len,:);
taufb_low_indefs=taufb_low_indefs(index(1):index(1)+len,:);
e_low_indefs=qd-q_low_indefs;
data{10}=[q_low_indefs taufb_low_indefs];

load high_direfs
q_high_direfs=[q_degree_0.Value',q_degree_1.Value',q_degree_2.Value',q_degree_3.Value',q_degree_4.Value',q_degree_5.Value',]*pi/180;
taufb_high_direfs=[tau_pd_0.Value',tau_pd_1.Value',tau_pd_2.Value',tau_pd_3.Value',tau_pd_4.Value',tau_pd_5.Value'];
index=find(q_des_t_0.Value~=0);
q_high_direfs=q_high_direfs(index(1):index(1)+len,:);
taufb_high_direfs=taufb_high_direfs(index(1):index(1)+len,:);
e_high_direfs=qd-q_high_direfs;
data{11}=[q_high_direfs taufb_high_direfs];

load low_direfs
q_low_direfs=[q_degree_0.Value',q_degree_1.Value',q_degree_2.Value',q_degree_3.Value',q_degree_4.Value',q_degree_5.Value',]*pi/180;
taufb_low_direfs=[tau_pd_0.Value',tau_pd_1.Value',tau_pd_2.Value',tau_pd_3.Value',tau_pd_4.Value',tau_pd_5.Value'];
index=find(q_des_t_0.Value~=0);
q_low_direfs=q_low_direfs(index(1):index(1)+len,:);
taufb_low_direfs=taufb_low_direfs(index(1):index(1)+len,:);
e_low_direfs=qd-q_low_direfs;
data{12}=[q_low_direfs taufb_low_direfs];