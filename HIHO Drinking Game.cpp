//http://hihocoder.com/problemset/problem/1095?sid=1176915

//简单枚举T，果断超时。。。 O(KN)
#include<bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
const double eps = 1E-6;
const int MAXN = 100010;

int d[MAXN];

int main() {
    freopen("test.txt", "r", stdin);
    int N, K, T=0, hoScore = 0;
    scanf("%d %d", &N, &K);
    for (int i = 0; i < N; i++) {
        scanf("%d", &d[i]);
    }
    while (true) {
        T++;
        hoScore = 0;
        int leftWater = 0;
        for (int i = 0; i < N; i++) {
            if (T+leftWater > d[i]) { hoScore++; leftWater = T + leftWater - d[i]; }
            else leftWater = 0;
        }
        if (2*hoScore > N) {
            printf("%d\n", T);
            break;
        }
    }
    return 0;

}

//二分O(NlgK)
#include<bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
const double eps = 1E-6;
const int MAXN = 100010;

int d[MAXN];
int N;

int f(int t) {
    int hoScore = 0;
    int leftWater = 0;
    for (int i = 0; i < N; i++) {
        if (t+leftWater > d[i]) { hoScore++; leftWater = t + leftWater - d[i]; }
        else leftWater = 0;
    }
    return hoScore;
}

int main() {
    freopen("test.txt", "r", stdin);
    int K, T;
    scanf("%d %d", &N, &K);
    for (int i = 0; i < N; i++) {
        scanf("%d", &d[i]);
    }
    int p = 0, q = K+1;
    while (p <= q) {
        T = p + (q-p)/2;
        int ret = f(T);
        if (2*ret > N) q = T-1;
        else p = T+1;
    }
    printf("%d\n", q+1);
    return 0;

}

