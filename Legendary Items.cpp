//http://hihocoder.com/problemset/problem/1489

//O(100N)
#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
const double eps = 1E-6;
const int MAXN = 1e6+1;

int main()
{
    //freopen("test.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int P, Q, N;
    cin >> P >> Q >> N;
    double ex = 0;
    for (int i = N-1; i >= 0; i--) {
        int p = i > 6 ? 0 : P/(1<<i);
        double pp = 1;
        bool loop = true;
        for (int j = 1; loop; j++) {
            if (p == 100) loop = false;
            ex += 0.01 * p * j * pp;
            pp *= (100-p) * 0.01;
            p += Q;
            if (p > 100) { p = 100;}
        }
    }
    printf("%.2lf\n", ex);
    return 0;
}


//O(100+8)
#include<bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
const double eps = 1E-6;
const int MAXN = 2010;

double f[101];

int main() {
    freopen("test.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int P, Q, N;
    cin >>P>>Q>>N;
    f[100] = 1;
    for (int i = 99; i >= 0; i--) {
        int j = min(100, i + Q);
        f[i] = i*0.01 + (100-i) * 0.01 * (f[j]+1);
    }

    double ex = 0;
    for (int i = 0; i < min(N, 7); i++) {
        int p = P / (1<<i);
        ex += f[p];
    }
    if (N > 7) {
        ex += f[0] * (N-7);
    }
    printf("%.2lf\n", ex);
    return 0;
}
