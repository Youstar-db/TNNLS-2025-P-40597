%%
data_gen;
net=[];
for k=1:6
    x=x_train(1:100,:)';
    y=y_train(1:100,k)';
    Ntr=size(x_train,1);
    
    %% 训练神经网络参数设定
    numHiddenUnits =20;    %指定LSTM层的隐含单元个数为50
    
    
    %% 输入有5个特征，输出有1个特征。
    numFeatures =  numel(x(:,1));
    numResponses =  numel(y(:,1));
    
    layers = [ ...
        sequenceInputLayer(numFeatures)
        lstmLayer(numHiddenUnits)
        fullyConnectedLayer(numResponses) %为全连接层，是输出的维数。
        regressionLayer];         %其计算回归问题的半均方误差模块 。即说明这不是在进行分类问题。
    
    options = trainingOptions('adam', ... %指定训练选项，求解器设置为adam， 1000轮训练。
        'MaxEpochs',150, ...    %最大训练周期为150
        'MiniBatchSize',64, ...
        'ExecutionEnvironment','gpu',...
        'InitialLearnRate',0.1, ...  %指定初始学习率 0.01
        'LearnRateSchedule','piecewise', ...  %每当经过一定数量的时期时，学习率就会乘以一个系数。
        'LearnRateDropPeriod', 50, ...
        'LearnRateDropFactor',0.5, ...  %在50轮训练后通过乘以因子 0.5 来降低学习率。
        'Verbose',1, ...   %如果将其设置为true，则有关训练进度的信息将被打印到命令窗口中,0即是不打印 。
        'Plots','none');   %构建曲线图 ，不想构造就将'training-progress'替换为none
    
    
    net{k} = trainNetwork(x,y,layers,options);    %训练神经网络
end
save('LSTM_net', 'net');
%%
for k=1:6
    net{k} = resetState(net{k});
    yp=zeros(size(y_test'));
    % yp=net.predict(x_train')';
    for i = 2:size(x_test',2)
        [net{k},yp(:,i)] = predictAndUpdateState(net{k},x_test(i-1,:)','ExecutionEnvironment','cpu');  %
    end
    figure();hold on;
    plot(yp);plot(y_test(:,k));
    rmse(y_test(:,k),yp')
end
