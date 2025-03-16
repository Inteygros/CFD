#include<cmath>
#include<stdio.h>
//定义函数F(x)
double F_function(double x){
    double F;
    F = sin(2 * x);//
    return F;
}

//定义精确的一阶导函数
double Difference1(double x){
    double F;
    F = 2 * cos(2 * x);//
    return F;
}

//定义精确的二阶导函数
double Difference2(double x){
    double F;
    F = -4 * sin(2 * x);// 
    return F;
}

//定义一阶导数两点向前差分
double Difference1_1(double delta_x, double x){
    double result;
    result = (F_function(x + delta_x) - F_function(x))/delta_x;
    return result;
}

//定义一阶导数三点向前差分
double Difference1_2(double delta_x, double x){
    double result;
    result = (-3 * F_function(x) + 4 * F_function(x + delta_x) - F_function(x + 2 * delta_x))/(2 * delta_x);
    return result;
}

//定义二阶导数三点向前差分
double Difference2_1(double delta_x, double x){
    double result;
    result = (F_function(x) - 2 * F_function(x + delta_x) + F_function(x + 2 * delta_x))/(delta_x * delta_x);
    return result;
}

//定义二阶导数中心差分
double Difference2_2(double delta_x, double x){
    double result;
    result = (F_function(x - delta_x) - 2 * F_function(x) + F_function(x + delta_x))/(delta_x * delta_x);
    return result;
}

int main()
{
    double x, h, y1, y1_1, e1_1, p1_1, y1_2, e1_2, p1_2, y2, y2_1, e2_1, p2_1, y2_2, e2_2, p2_2;
    printf("自变量值：");
    scanf("%lf", &x);
    printf("初始网格间距：");
    scanf("%lf", &h);
    int i = 1;
    FILE *output_file = fopen("error_data.csv", "w");

    while(h > 10e-8){
        y1 = Difference1(x);//计算精确的一阶导函数
        y1_1 = Difference1_1(h, x);//计算一阶导数两点向前差分
        y1_2 = Difference1_2(h, x);//计算一阶导数三点向前差分

        y2 = Difference2(x);//计算精确的二阶导函数
        y2_1 = Difference2_1(h, x);//计算二阶导数三点向前差分
        y2_2 = Difference2_2(h, x);//计算二阶导数中心差分

        if(i >1){
            p1_1 = log2(fabs(e1_1)/fabs(y1_1-y1));
            p1_2 = log2(fabs(e1_2)/fabs(y1_2-y1));
            p2_1 = log2(fabs(e2_1)/fabs(y2_1-y2));
            p2_2 = log2(fabs(e2_2)/fabs(y2_2-y2));//计算精度p
        }

        e1_1 = y1_1 - y1;//计算误差
        e1_2 = y1_2 - y1;//计算误差
        e2_1 = y2_1 - y2;//计算误差
        e2_2 = y2_2 - y2;//计算误差
        printf("当前循环数%d 网格间距:%lf\n", i, h);
        printf("一阶差分1:%lf 一阶差分2:%lf 一阶导数:%lf\n二阶差分1:%lf 二阶差分2:%lf 二阶导数:%lf\n", y1_1, y1_2, y1, y2_1, y2_2, y2);
        printf("一阶差分1误差:%lf 一阶差分2误差:%lf\n二阶差分1误差:%lf 二阶差分2误差:%lf\n", e1_1, e1_2, e2_1, e2_2);
        if(i >1){
            printf("一阶差分1精度:%lf 一阶差分2精度:%lf\n二阶差分1精度:%lf 二阶差分2精度:%lf\n\n", p1_1, p1_2, p2_1, p2_2);
        }
        fprintf(output_file, "%.10e %.10e %.10e %.10e %.10e\n", h, e1_1, e1_2, e2_1, e2_2);
        h = h / 2;
        i = i + 1;
    }

    fclose(output_file);
    printf("\n误差数据已保存到 error_data.csv\n");
    
    return 0;
}