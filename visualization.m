output = readmatrix('output\error_data.csv');
data = reshape(output', 5, []);
h = data(1, :);%������
errors = abs(data(2:5, :)); % ��ת���ɾ���ֵ

% ����һ�׵���
loglog(h, errors(1, :), 'Marker', 'o', 'DisplayName', 'һ�׵���������ǰ���');
hold on;
loglog(h, errors(2, :), 'Marker', 's', 'DisplayName', 'һ�׵���������ǰ���');
hold off;
% �����������ǩ�ͱ���
xlabel('������h ');
ylabel('���');
title('һ�ײ�ָ�ʽ�����������仯');
grid on;
legend('Location', 'best');%ͼ��
saveas(gcf, 'figure\һ�ײ�ָ�ʽ�����������仯.png');%����

% ���ƶ��׵���
loglog(h, errors(3, :), 'Marker', '^', 'DisplayName', '���׵���������ǰ���');
hold on;
loglog(h, errors(4, :), 'Marker', 'd', 'DisplayName', '���׵������Ĳ��');
hold off;
% �����������ǩ�ͱ���
xlabel('������h');
ylabel('���');
title('���ײ�ָ�ʽ�����������仯');
grid on;
legend('Location', 'best');%ͼ��
saveas(gcf, 'figure\���ײ�ָ�ʽ�����������仯.png');%����
