//http://hihocoder.com/problemset/problem/1138?sid=1196297
//http://hihocoder.com/discuss/question/2792/

//预处理+dijstra单源最短路径
#include<bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
const double eps = 1E-6;
const int MAXN = 100010;

struct point {
    int x, y;
    int id;
};


bool cmp1 (const point& p1, const point& p2) {
    return p1.x < p2.x;
}

bool cmp2 (const point& p1, const point& p2) {
    return p1.y < p2.y;
}

int N;
vector<point> nodes;

struct Edge {
    int from, to, dist;
    Edge(int from, int to, int dist) : from(from), to(to), dist(dist) {}
};

struct HeapNode {
    int d, u;
    bool operator < (const HeapNode& rhs) const {
        return d > rhs.d;
    }
};

//struct Dijkstra {
    int n, m;
    vector<Edge> edges;
    vector<int> G[MAXN];
    bool done[MAXN]; //是否已永久标号
    int d[MAXN];     //s到各个点的距离
    int p[MAXN];     //最短距离中的上一条弧

    void init(int a) {
        n = a;
        for (int i = 0; i < n; i++) {
            G[i].clear();
        }
        edges.clear();
    }

    void AddEdge(int from, int to, int dist) {
        edges.push_back(Edge(from, to, dist));
        m = edges.size();
        G[from].push_back(m-1);
    }

    void dijkstra(int s) {
        priority_queue<HeapNode> q;
        for (int i = 0; i < n; i++) d[i] = INF;
        d[s] = 0;
        memset(done, 0, sizeof(done));
        q.push((HeapNode){0, s});
        while (!q.empty()) {
            HeapNode x = q.top(); q.pop();
            int u = x.u;
            if (done[u]) continue;
            done[u] = true;
            for (int i = 0; i < G[u].size(); i++) {
                Edge& e = edges[G[u][i]];
                if (d[e.to] > d[u] + e.dist) {
                    d[e.to] = d[u]+e.dist;
                    p[e.to] = G[u][i];
                    q.push((HeapNode){d[e.to], e.to});
                }
            }
        }
    }
//};

int main() {
    freopen("test.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &N);
    if (N < 1) return 0;
    for (int i = 0; i < N; i++) {
        point p;
        scanf("%d %d", &p.x, &p.y);
        p.id = i;
        nodes.push_back(p);
    }
    init(N);
    sort(nodes.begin(), nodes.end(), cmp1);
    for (int i = 1; i < nodes.size(); i++) {
        if (nodes[i].x == nodes[i-1].x) {
            AddEdge(nodes[i].id, nodes[i-1].id, 0);
            AddEdge(nodes[i-1].id, nodes[i].id, 0);
        }
        else {
            AddEdge(nodes[i].id, nodes[i-1].id, nodes[i].x - nodes[i-1].x);
            AddEdge(nodes[i-1].id, nodes[i].id, nodes[i].x - nodes[i-1].x);
        }
    }
    sort(nodes.begin(), nodes.end(), cmp2);
    for (int i = 1; i < nodes.size(); i++) {
        if (nodes[i].y == nodes[i-1].y) {
            AddEdge(nodes[i].id, nodes[i-1].id, 0);
            AddEdge(nodes[i-1].id, nodes[i].id, 0);
        }
        else {
            AddEdge(nodes[i].id, nodes[i-1].id, nodes[i].y - nodes[i-1].y);
            AddEdge(nodes[i-1].id, nodes[i].id, nodes[i].y - nodes[i-1].y);
        }
    }
    dijkstra(0);
    printf("%d\n", d[N-1]);
    return 0;
}
