//http://hihocoder.com/contest/mstest2017april/problem/2

//贪心，前几次全用来造人，之后一鼓作气做事，遍历前几次要几次即可
//特别注意数的取值范围，long long 排错找了好久。。。。
#include<bits/stdc++.h>
using namespace std;
const int MAXN = 100010;
const double EPS = 1e-6;

int Q;
long long N;


int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%lld %d", &N, &Q);
    long long ret = N;
    long long power = 1;
    for (int k = 1; ; k++) {   //从1开始特别重要
        power *= 2;
        long long cnt = (long long)ceil(N*1.0 / power) + k * Q;
        if (cnt < ret) {
            ret = cnt;
        }
        else if (cnt > ret) {
            break;
        }
    }
    printf("%lld\n", ret);
    return 0;
}