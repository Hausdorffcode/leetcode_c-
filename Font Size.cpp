//http://hihocoder.com/contest/mstest2016april1/problem/1

//Math
#include<bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
const double eps = 1E-6;
const int MAXN = 1010;

int a[MAXN];

int main()
{
    freopen("test.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int TASKS;
    scanf("%d", &TASKS);
    while (TASKS--) {
        int N, P, W, H;
        scanf("%d %d %d %d", &N, &P, &W, &H);
        for (int i = 0; i < N; i++) {
            scanf("%d", &a[i]);
        }
        int S = 1;
        while (true) {
            int w_s = W/S;
            int h_s = H/S;
            if (w_s == 0 || h_s == 0) {   //注意这两个变量可能变0， 可以从字体最大值min（W，H）开始枚举避免
                break;
            }
            int total_line = 0;
            for (int i = 0; i < N; i++) {
                total_line += a[i] % w_s == 0 ? a[i] / w_s : a[i] / w_s + 1;
            }
            int total_page = total_line % h_s == 0 ? total_line / h_s : total_line / h_s + 1;
            if (total_page > P) {
                break;
            }
            else {
                S++;
            }
        }
        printf("%d\n", S-1);   //注意输出值
    }
    return 0;
}

