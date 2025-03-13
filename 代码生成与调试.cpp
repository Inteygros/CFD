#include<cmath>
#include<stdio.h>
//定义函数F(x)
int F_function(double x){
    double F;
    F = sin(x);
    return F;
}

//定义一阶导数两点向前差分
int Difference_1(double delta_x, double x){
    double result;
    result = (F_function(x + delta_x) - F_function(x))/delta_x;
    return result;
}

//定义一阶导数三点向前差分
int Difference_2(double delta_x, double x){
    double result;
    result = (-3 * F_function(x) + 4 * F_function(x + delta_x) - F_function(x + 2 * delta_x))/(2 * delta_x);
    return result;
}

//定义二阶导数三点向前差分
int Difference_3(double delta_x, double x){
    double result;
    result = (F_function(x) - 2 * F_function(x + delta_x) + F_function(x + 2 * delta_x))/(delta_x * delta_x);
    return result;
}

//定义二阶导数中心差分
int Difference_4(double delta_x, double x){
    double result;
    result = (F_function(x - delta_x) - 2 * F_function(x) + F_function(x + delta_x))/(delta_x * delta_x);
    return result;
}

int main()
{
    double x, delta_x, y1, y2, y3, y4;
    scanf("输入自变量的值：%lf 网格间距：%lf", &x, &delta_x);
    y1 = Difference_1(delta_x, x);//计算一阶导数两点向前差分
    y2 = Difference_2(delta_x, x);//计算一阶导数三点向前差分
    y3 = Difference_3(delta_x, x);//计算二阶导数三点向前差分
    y4 = Difference_4(delta_x, x);//计算二阶导数中心差分
    printf("一阶导数两点向前差分:%lf\n一阶导数三点向前差分:%lf\n二阶导数三点向前差分:%lf\n二阶导数中心差分:%lf", y1, y2, y3, y4);
    return 0;
}