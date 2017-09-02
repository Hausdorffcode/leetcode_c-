//http://hihocoder.com/problemset/problem/1038?sid=1163797

//dp
using namespace std;

const int INF = 0x3f3f3f3f;
const double eps = 1E-6;
const int MAXN = 100010;

const int bb = 505;

int N, M;
int need[MAXN];
int val[MAXN];
int f[bb][MAXN];

int main()
{
    freopen("test.txt", "r", stdin);

    scanf("%d %d" , &N, &M);
    for (int i = 1; i <= N; i++) {
        scanf("%d %d", &need[i], &val[i]);
    }
    int ans = 0;
    memset(f, 0, sizeof(f));

    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= M; j++) {   //这里j要从0开始，不是need[i]
            if (j < need[i]) f[i][j] = f[i-1][j];
            else f[i][j] = max(f[i-1][j], f[i-1][j-need[i]]+val[i]);
        }
    }
    printf("%d\n", f[N][M]);
    return 0;
}

//进一步考虑f的计算顺序，发现可以降低空间复杂度
using namespace std;

const int INF = 0x3f3f3f3f;
const double eps = 1E-6;
const int MAXN = 100010;

const int bb = 505;

int N, M;
int need[MAXN];
int val[MAXN];
int f[MAXN];

int main()
{
    scanf("%d %d" , &N, &M);
    for (int i = 1; i <= N; i++) {
        scanf("%d %d", &need[i], &val[i]);
    }
    int ans = 0;
    memset(f, 0, sizeof(f));

    for (int i = 1; i <= N; i++) {
        for (int j = M; j >= need[i]; j--) {
            f[j] = max(f[j], f[j-need[i]]+val[i]);
        }
    }
    printf("%d\n", f[M]);
    return 0;
}

//亦可
#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
const double eps = 1E-6;
const int MAXN = 100010;

const int bb = 505;

int N, M;
int need[MAXN];
int val[MAXN];
int f[MAXN];

int main()
{
    scanf("%d %d" , &N, &M);
    for (int i = 0; i < N; i++) {
        scanf("%d %d", &need[i], &val[i]);
    }
    int ans = 0;
    memset(f, 0, sizeof(f));

    for (int i = 0; i < N; i++) {
        for (int j = M; j >= need[i]; j--) {
            f[j] = max(f[j], f[j-need[i]]+val[i]);
        }
    }
    printf("%d\n", f[M]);
    return 0;
}


