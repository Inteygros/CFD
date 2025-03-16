output = readmatrix('output\error_data.csv');
data = reshape(output', 5, []);
h = data(1, :);%网格间距
errors = abs(data(2:5, :)); % 误差并转换成绝对值

% 绘制一阶导数
loglog(h, errors(1, :), 'Marker', 'o', 'DisplayName', '一阶导数两点向前差分');
hold on;
loglog(h, errors(2, :), 'Marker', 's', 'DisplayName', '一阶导数三点向前差分');
hold off;
% 设置坐标轴标签和标题
xlabel('网格间距h ');
ylabel('误差');
title('一阶差分格式误差随网格间距变化');
grid on;
legend('Location', 'best');%图例
saveas(gcf, 'figure\一阶差分格式误差随网格间距变化.png');%保存

% 绘制二阶导数
loglog(h, errors(3, :), 'Marker', '^', 'DisplayName', '二阶导数三点向前差分');
hold on;
loglog(h, errors(4, :), 'Marker', 'd', 'DisplayName', '二阶导数中心差分');
hold off;
% 设置坐标轴标签和标题
xlabel('网格间距h');
ylabel('误差');
title('二阶差分格式误差随网格间距变化');
grid on;
legend('Location', 'best');%图例
saveas(gcf, 'figure\二阶差分格式误差随网格间距变化.png');%保存
