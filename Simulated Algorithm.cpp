#include<bits/stdc++.h>
using namespace std;

const int maxn = 20;
const double eps = 1e-6;

/// Simulated Algorithm for Functional Maximum Problem

/// f(x) = x+10*sin(5*x)+7*cos(4*x), x∈[0,9]
double f(double x) {
    return x + 10*sin(5*x) + 7*cos(4*x);
    //return -1*x*x + 10*x + 100;
    //return sin(x);
}
int upper_bound_num = 9;        // 自变量的区间上限
int lower_bound_num = 0;        // 自变量的区间下限

const double T_min = 0.0001;    //温度阈值
const double T_start = 10000;   //初始温度
const double delta = 0.99;      //每次温度变化系数


int main () {
    srand(2811);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    //初始值
    double x = lower_bound_num + (double)rand() / RAND_MAX * (upper_bound_num - lower_bound_num);
    double best_x = x;  //历史最好x值
    double best_y = f(x);  //历史最好函数值
    double T = T_start;
    while (T > T_min) {
        double coff = rand() > RAND_MAX/2 ? -1 : 1;
        double x_new = x + coff * rand()/RAND_MAX * T / (upper_bound_num-lower_bound_num) * 0.1;
        if (x_new < lower_bound_num) x_new = lower_bound_num;
        if (x_new > upper_bound_num) x_new = upper_bound_num;
        double dE = f(x_new) - f(x);
        if (dE) {
            x = x_new;
        }
        else {
            if ((double)rand()/RAND_MAX < exp(dE/T)) {
                x = x_new;
            }
        }
        if (f(x) > best_y) {
            best_x = x;
            best_y = f(x);
        }
        T *= delta;
    }
    printf("%lf\n", best_x);
    printf("%lf\n", best_y);
    return 0;
}
