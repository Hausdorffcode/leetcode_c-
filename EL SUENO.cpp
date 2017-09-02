//http://hihocoder.com/contest/mstest2017april/problem/4

//树dp
#include<bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
const double eps = 1E-6;
const int MAXN = 2010;

int N;
int F[MAXN];
int IN[MAXN];
int C[MAXN];
int IP[MAXN];
vector<int> mp[MAXN];

int dfs(int x) {
    vector<int> f(IN[x]+1, 1e9);  //初始化
    f[0] = 0;    //背包为0时合法
    for (int i = 0; i < mp[x].size(); i++) {
        int v = mp[x][i];
        int temp = dfs(v);
        for (int j = IN[x]; j > 0; j--) {   //超过背包容量时继续，就是要超过>=，不超过不合法
            f[j] = min(f[j], f[max(j-IP[v], 0)] + C[v] + temp);
        }
    }
    return f[IN[x]];
}

int main() {
    freopen("test.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> N;
    int root = 0;
    for (int i = 1; i <= N; i++) {  //读入从1开始，因为文中f是1-N的
        cin >> F[i] >> IN[i] >> IP[i] >> C[i];
        if (F[i] == 0) root = i;
        mp[F[i]].push_back(i);   //管好儿子
    }
    int ans = dfs(root);
    if (ans >= 1e9) printf("-1\n");
    else printf("%d\n", ans + C[root]);
    return 0;
}
