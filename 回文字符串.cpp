//http://hihocoder.com/contest/hiho162/problem/1

//dp
#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
const double eps = 1E-6;
const int MAXN = 110;

int f[MAXN][MAXN];
string s;
int vis[MAXN][MAXN];

int cal(int i, int j) {
    if (i >= j) {
        vis[i][j] = 1;
        return f[i][j];
    }
    if (s[i] == s[j]) {
        vis[i][j] = 1;
        return f[i][j] = cal(i+1, j-1);
    }
    if (vis[i][j]) return f[i][j];
    int a = cal(i+1, j) + 1;
    int b = cal(i, j-1) + 1;
    int c = cal(i+1, j-1) + 1;
    f[i][j] = min(a, min(b, c));
    vis[i][j] = 1;
    return f[i][j];
}

int main()
{
    freopen("test.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> s;
    memset(f, 0, sizeof(f));
    memset(vis, 0, sizeof(vis));
    printf("%d\n", cal(0, s.size()-1));
    return 0;
}
