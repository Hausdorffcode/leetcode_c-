//http://hihocoder.com/problemset/problem/1043?sid=1163817

//dp
//超时了，哇。。。。有原因的因为best(i, x)的大部分计算都在best(i, x - need(i))中已经计算过了
#include<bits/stdc++.h>
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
    //freopen("output.txt", "w", stdout);
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        cin >> need[i] >> val[i];
    }
    memset(f, 0, sizeof(f));
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= M; j++) {
            for (int k = 0; k <= j/need[i]; k++) {
                f[i][j] = max(f[i][j], f[i-1][j-k*need[i]] + k*val[i]);
            }
        }
    }
    cout << f[N][M] << endl;
    return 0;
}


//
#include<bits/stdc++.h>
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
    //freopen("output.txt", "w", stdout);
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        cin >> need[i] >> val[i];
    }
    memset(f, 0, sizeof(f));
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= M; j++) {   //这里j要从0开始，不是need[i]
            if (j < need[i]) f[i][j] = f[i-1][j];
            else f[i][j] = max(f[i-1][j], f[i][j-need[i]] + val[i]);
        }
    }
    cout << f[N][M] << endl;
    return 0;
}

//优化空间
#include<bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
const double eps = 1E-6;
const int MAXN = 100010;

int N, M;
int need[MAXN];
int val[MAXN];
int f[MAXN];

int main()
{
    freopen("test.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        cin >> need[i] >> val[i];
    }
    memset(f, 0, sizeof(f));
    for (int i = 1; i <= N; i++) {
        for (int j = need[i]; j <= M; j++) {
            f[j] = max(f[j], f[j-need[i]] + val[i]);
        }
    }
    cout << f[M] << endl;
    return 0;
}

