//http://hihocoder.com/problemset/problem/1238?sid=1198372
//http://hihocoder.com/discuss/question/3600

//先读入数据到邻接表，在构造树，同时计算THD，统计每个结点子树，并记录树的边权值
//关于读入后暂时存储的结构：这里我用的数组的邻接表，也可以使用vector数组表示的邻接表，权值也用vector数组，存在对应位置
//还可以使用map<int, int>数组，其中map[u] = <v, w>代表uv边权重为w，这里和之前一样由于无向图，一条边要添加两次
//其实这边本质上并不需要father数组，我们要的是快速找到一条边，知道它的权值，知道它两侧的结点数量，可用level数组代替father
#include<bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
const double eps = 1E-6;
const int MAXN = 100010;

int N, M;
long long total = 0;
int father[MAXN];    //树
int weight[MAXN];    //指向父结点的路径权重
int nodecnt[MAXN];   //子树节点数
int root = 1;        //root node
bool vis[MAXN];

//邻接表
int p[MAXN*2];
int nextEdge[MAXN*2];
int head[MAXN];
int dist[MAXN*2];
int edgecnt = 0;

void addEdge(int u, int v, int k) {
    edgecnt++;
    dist[edgecnt] = k;
    p[edgecnt] = v;
    nextEdge[edgecnt] = head[u];
    head[u] = edgecnt;
    edgecnt++;
    dist[edgecnt] = k;
    p[edgecnt] = u;
    nextEdge[edgecnt] = head[v];
    head[v] = edgecnt;
}

void buildTree(int u) {
    vis[u] = true;
    nodecnt[u] = 1;
    for (int i = head[u]; i; i = nextEdge[i]) {
        int v = p[i];
        if (!vis[v]) {
            father[v] = u;
            weight[v] = dist[i];
            buildTree(v);
            nodecnt[u] += nodecnt[v];
            total += (long long)weight[v] * nodecnt[v] * (N-nodecnt[v]);
        }
    }
}

void query() {
    printf("%lld\n", total);
}

void edit(int u, int v, int k) {
    if (v == father[u]) {
        swap(u, v);
    }
    long long det = (long long)(k-weight[v])* nodecnt[v] * (N-nodecnt[v]);
    total += det;
    weight[v] = k;
}

int main() {
    freopen("test.txt", "r", stdin);
    int u, v, k;
    char op[10];
    scanf("%d %d", &N, &M);
    for (int i = 1; i < N; i++) {
        scanf("%d %d %d", &u, &v, &k);
        addEdge(u,v,k);
    }
    buildTree(root);
    for (int i = 0; i < M; i++) {
        scanf("%s", op);
        if (strcmp(op, "EDIT") == 0) {
            scanf("%d %d %d", &u, &v, &k);
            edit(u, v, k);
        }
        else {
            query();
        }
    }
    return 0;
}


//大神的代码写得很清楚
//他只记录了树结构，其它权值之类用图表示，性能下降了一些，但可以ac
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <cstring>
#include <iostream>
using namespace std;
#define MAXN 100010

vector<int> edges[MAXN];  //用邻接表表示的带权值的图
vector<int> d[MAXN];

int child[MAXN];     //子结点个数，这里他没有把本结点算进去
int fa[MAXN];       //记录树结构
long long thd = 0;

int N, M;

void addEdge(int u, int v, int w) {
    edges[u].push_back(v);
    d[u].push_back(w);
}

void addDEdge(int u, int v, int w) {
    addEdge(u, v, w);
    addEdge(v, u, w);
}

void dfs(int u, vector<int> &vis) {
    vis[u] = 1;
    child[u] = 0;
    for (int i = 0; i < edges[u].size(); ++i) {
        int v = edges[u][i];
        if (!vis[v]) {
            fa[v] = u;
            dfs(v, vis);
            child[u] += child[v] + 1;
            thd += (long long)d[u][i] * (child[v] + 1)*(N - 1 - child[v]);
        }
    }
}

int update(int u, int v, int k) {
    int old = 0;
    for (int i = 0; i < edges[u].size(); ++i) {   
        if (edges[u][i] == v) {
            old = d[u][i];
            d[u][i] = k;    
        }
    }

    for (int i = 0; i < edges[v].size(); ++i) {
        if (edges[v][i] == u) {
            d[v][i] = k;
        }
    }

    return old;
}

int main() {
    
    scanf("%d%d", &N, &M);
    for (int i = 0; i < N - 1; ++i) {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        addDEdge(u, v, w);
    }
    vector<int> vis(N+1, 0);
    fa[1] = 0;
    dfs(1, vis);

    for (int k = 1; k <= M; ++k) {
        char op[10];
        scanf("%s", op);
        if (strcmp(op, "EDIT") == 0) {
            int u, v, k;
            scanf("%d%d%d", &u, &v, &k);
            int old = update(u, v, k);
            if (fa[v] == u) {
                thd += (long long)(k - old) * (child[v] + 1) * (N - 1 - child[v]);
            }
            else {
                thd += (long long)(k - old) * (child[u] + 1) * (N - 1 - child[u]);
            }
        }
        else {
            printf("%lld\n", thd);
        }
    }
}