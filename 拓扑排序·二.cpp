//http://hihocoder.com/problemset/problem/1175?sid=1176335

//拓扑排序应用 O(N+M)
#include<bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
const double eps = 1E-6;
const int MAXN = 500010;
const int MAXM = 100010;

const int magic = 142857;

int N, M, K;
int x, y;
int deg[MAXM];
int viruscnt[MAXM];
queue<int> q;

int edgecnt;
int p[MAXN];
int head[MAXM];
int nextEdge[MAXN];

void init () {
    edgecnt = 0;
    memset(p, 0, sizeof(p));
    memset(head, 0, sizeof(head));
    memset(nextEdge, 0, sizeof(nextEdge));
    memset(deg, 0, sizeof(deg));
    memset(viruscnt, 0, sizeof(viruscnt));
}

void addedge(int u, int v) {
    ++edgecnt;
    p[edgecnt] = v;
    nextEdge[edgecnt] = head[u];
    head[u] = edgecnt;
}

int main() {
    freopen("test.txt", "r", stdin);
    init();
    scanf("%d %d %d", &N, &M, &K);
    int a;
    for (int i = 0; i < K; i++) {
        scanf("%d", &a);
        viruscnt[a]++;
    }
    for (int i = 0; i < M; i++) {
        scanf("%d %d", &x, &y);
        addedge(x, y);
        deg[y]++;
    }
    for (int i = 1; i <= N; i++) {
        if (deg[i] == 0) q.push(i);
    }

    while (!q.empty()) {
        int discard_point = q.front(); q.pop();
        for (int i = head[discard_point]; i ; i = nextEdge[i]) {
            deg[p[i]] -= 1;
            viruscnt[p[i]] += viruscnt[discard_point];
            viruscnt[p[i]] %= magic;
            if (deg[p[i]] == 0) q.push(p[i]);
        }
    }

    int total = 0;
    for (int i = 1; i <= N; i++) {
        total += viruscnt[i];
        total %= magic;
    }
    printf("%d\n", total);

    return 0;
}
