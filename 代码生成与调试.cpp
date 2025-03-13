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

    return 0;
}