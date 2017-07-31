//http://hihocoder.com/contest/hiho161/problem/1

//包含N个点M条边的无向图是树的充分必要条件是N=M+1且N个点连通。

//判断连通性
//从一个点（比如1号点）开始进行DFS/BFS，搜索过程中把遇到的点都标记上，最后检查是不是N个点都被标记了。
#include<bits/stdc++.h>
using namespace std;

const int MAXN = 510;
const double EPS = 1e-6;

bool graph[MAXN][MAXN];
bool vis[MAXN];
int N, M;

void dfs(int i) {
    vis[i] = true;
    for (int k = 0; k < N; k++) {
        if (k != i && graph[i][k] == true && vis[k] == false) {
            dfs(k);
        }
    }
}

int main () {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &N, &M);
        memset(graph, 0, sizeof(graph));
        memset(vis, 0, sizeof(vis));
        for (int k = 0; k < M; k++) {
            int i, j;
            scanf("%d %d", &i, &j);
            graph[i-1][j-1] = true;
            graph[j-1][i-1] = true;
        }
        if (N != M+1) {
            printf("NO\n");
            continue;
        }
        dfs(0);
        bool ok = true;
        for (int i = 0; i < N; i++) {
            if (vis[i] == false) {
                ok = false;
                //break;
            }
        }
        if (ok) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}

//判断连通性
//用并查集，依次处理每一条边，把每条边的两个顶点都合并到一个集合里。最后检查是不是N个点都在同一个集合中。
