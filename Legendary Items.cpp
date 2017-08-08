//http://hihocoder.com/problemset/problem/1489

//
#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
const double eps = 1E-6;
const int MAXN = 1e6+1;

double f[MAXN];

int main()
{
    freopen("test.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int P, Q, N;
    cin >> P >> Q >> N;
    memset(f, 0, sizeof(f));
    f[N] = 1;
    for (int i = N-1; i >= 0; i--) {
        double e = 0;
        int p = i > 6 ? 0 : P/(1<<i);
        double pp = 1;
        bool loop = true;
        for (int j = 1; loop; j++) {
            if (p == 100) loop = false;
            e += 0.01 * p * j * pp;
            //printf("e = %lf\n", e);
            pp *= (100-p) * 0.01;
            p += Q;
            if (p > 100) { p = 100;}
        }
        f[i] = e;
        //printf("f[%d] = %lf\n", i, f[i]);
    }
    double sum = 0;
    for (int i = 0; i < N; i++) {
        sum += f[i];
    }
    printf("%.2lf\n", sum);
    return 0;
}
