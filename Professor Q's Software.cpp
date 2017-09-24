//http://hihocoder.com/problemset/problem/1136?sid=1175985

//构建一幅有向无环图，暴力dfs，可惜过不了。。。。
#include<bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
const double eps = 1E-6;
const int MAXN = 100010;

const int magicNum = 142857;

struct module {
    int activeSign;
    vector<int> sendSign;
};

int n, m;
module modules[MAXN];
vector<int> signCanActiveModules[MAXN];
int cntModules[MAXN];

void init() {
    for (int i = 0; i < MAXN; i++) {
        signCanActiveModules[i].clear();
    }
    memset(cntModules, 0, sizeof(cntModules));
}

void dfs(int index) {
    cntModules[index]++;
    cntModules[index] %= magicNum;
    for (int i = 0; i < modules[index].sendSign.size(); i++) {
        int sign = modules[index].sendSign[i];
        for (int j = 0; j < signCanActiveModules[sign].size(); j++) {
            int aimModule = signCanActiveModules[sign][j];
            if (aimModule != 0) {
                dfs(aimModule);
            }
        }
    }
}

int main() {
    //freopen("test.txt", "r", stdin);
    int T;
    scanf("%d", &T);
    while (T--) {
        init();
        scanf("%d %d", &n, &m);
        modules[0].activeSign = -1;
        int msign;
        for (int i = 0; i < m; i++) {
            scanf("%d", &msign);
            modules[0].sendSign.push_back(msign);
        }
        for (int i = 1; i <= n; i++) {
            int k, e;
            scanf("%d %d", &(modules[i].activeSign), &k);
            signCanActiveModules[modules[i].activeSign].push_back(i);
            for (int j = 0; j < k; j++) {
                scanf("%d", &e);
                modules[i].sendSign.push_back(e);
            }
        }
        dfs(0);
        for (int i = 1;  i <= n; i++) {
            if (i == n) printf("%d\n", cntModules[i]);
            else printf("%d ", cntModules[i]);
        }
    }
    return 0;
}

//又过不了。。
#include<bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
const double eps = 1E-6;
const int MAXN = 100010;

const int magic = 142857;

struct module{
    int activeSign;
    vector<int> sendSign;
};

int N, M;
module modules[MAXN];
vector<int> activeSignToModules[MAXN];
int callcnt[MAXN];

int head[MAXN];
int p[MAXN];
int nextModule[MAXN];
int edgecnt;
int deg[MAXN];

void addEdge(int u, int v) {
    ++edgecnt;
    p[edgecnt] = v;
    nextModule[edgecnt] = head[u];
    head[u] = edgecnt;
}

void init() {
    for (int i = 0; i < MAXN; i++) {
        activeSignToModules[i].clear();
    }
    memset(callcnt, 0, sizeof(callcnt));
    memset(head, 0, sizeof(head));
    memset(p, 0, sizeof(p));
    memset(nextModule, 0, sizeof(nextModule));
    edgecnt = 0;
    memset(deg, 0, sizeof(deg));
}

void dfs(int x) {
    callcnt[x]++;
    callcnt[x] %= magic;
    for (int i = head[x]; i; i = nextModule[i]) {
        int v = p[i];
        dfs(v);
    }
}

void toposort() {
    queue<int> q;
    q.push(0);
    callcnt[0] = 1;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int i = head[u]; i; i = nextModule[i]) {
            int v = p[i];
            deg[v] -= 1;
            callcnt[v] += callcnt[u];
            callcnt[v] %= magic;
            if (deg[v] == 0) q.push(v);
        }
    }
}

int main() {
    freopen("test.txt", "r", stdin);
    int T;
    scanf("%d", &T);
    while (T--) {
        init();
        scanf("%d %d", &N, &M);
        modules[0].activeSign = -1;
        int initialSign;
        modules[0].sendSign.clear();
        for (int i = 0; i < M; i++) {
            scanf("%d", &initialSign);
            modules[0].sendSign.push_back(initialSign);
        }
        for (int i = 1; i <= N; i++) {
            int s, k, e;
            scanf("%d %d", &s, &k);
            modules[i].activeSign = s;
            modules[i].sendSign.clear();
            activeSignToModules[s].push_back(i);
            for (int j = 0; j < k; j++) {
                scanf("%d", &e);
                modules[i].sendSign.push_back(e);
            }
        }

        //build picture
        for (int i = 0; i <= N; i++) {
            for (int j = 0; j < modules[i].sendSign.size(); j++) {
                int sign = modules[i].sendSign[j];
                for (int k = 0; k < activeSignToModules[sign].size(); k++) {
                    int m = activeSignToModules[sign][k];
                    addEdge(i, m);
                    deg[m]++;
                }
            }
        }

        toposort();
        //dfs(0);

        for (int i = 1; i <= N; i++) {
            if (i == N) printf("%d\n", callcnt[i]);
            else printf("%d ", callcnt[i]);
        }
    }
    return 0;
}

//终于ac了。。。
#include<bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
const double eps = 1E-6;
const int MAXN = 100010;

const int magic = 142857;

struct module{
    int activeSign;
    int sendSignCnt;
    int sendSign[3];
};

int N, M;
module modules[MAXN];
int initSign[MAXN];
vector<int> activeSignToModules[MAXN];
int callcnt[MAXN];

int head[MAXN];
int p[MAXN];
int nextModule[MAXN];
int edgecnt;
int deg[MAXN];

void addEdge(int u, int v) {
    ++edgecnt;
    p[edgecnt] = v;
    nextModule[edgecnt] = head[u];
    head[u] = edgecnt;
}

void init() {
    for (int i = 0; i < MAXN; i++) {
        activeSignToModules[i].clear();
    }
    memset(callcnt, 0, sizeof(callcnt));
    memset(head, 0, sizeof(head));
    memset(p, 0, sizeof(p));
    memset(nextModule, 0, sizeof(nextModule));
    edgecnt = 0;
    memset(deg, 0, sizeof(deg));
}

void dfs(int x) {
    callcnt[x]++;
    callcnt[x] %= magic;
    for (int i = head[x]; i; i = nextModule[i]) {
        int v = p[i];
        dfs(v);
    }
}

void toposort() {
    queue<int> q;
    for (int i = 0; i < M; i++) {
        int sign = initSign[i];
        for (int j = 0; j < activeSignToModules[sign].size(); j++) {
            //q.push(activeSignToModules[sign][j]);
            callcnt[activeSignToModules[sign][j]]++;
        }
    }
    for (int i = 1; i <= N; i++) {
        if (deg[i] == 0) {
            q.push(i);
        }
    }
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int i = head[u]; i; i = nextModule[i]) {
            int v = p[i];
            deg[v] -= 1;
            callcnt[v] += callcnt[u];
            callcnt[v] %= magic;
            if (deg[v] == 0) q.push(v);
        }
    }
}

int main() {
    freopen("test.txt", "r", stdin);
    int T;
    scanf("%d", &T);
    while (T--) {
        init();
        scanf("%d %d", &N, &M);
        for (int i = 0; i < M; i++) {
            scanf("%d", &initSign[i]);
        }
        for (int i = 1; i <= N; i++) {
            int s, k, e;
            scanf("%d %d", &s, &k);
            modules[i].activeSign = s;
            modules[i].sendSignCnt = k;
            activeSignToModules[s].push_back(i);
            for (int j = 0; j < k; j++) {
                scanf("%d", &e);
                modules[i].sendSign[j] = e;
            }
        }

        //build picture
        for (int i = 1; i <= N; i++) {
            for (int j = 0; j < modules[i].sendSignCnt; j++) {
                int sign = modules[i].sendSign[j];
                for (int k = 0; k < activeSignToModules[sign].size(); k++) {
                    int m = activeSignToModules[sign][k];
                    addEdge(i, m);
                    deg[m]++;
                }
            }
        }

        toposort();             //两种方式：拓扑排序，dfs
//        for (int i = 0; i < M; i++) {
//            int sign = initSign[i];
//            for (int j = 0; j < activeSignToModules[sign].size(); j++) {
//                dfs(activeSignToModules[sign][j]);
//            }
//        }

        for (int i = 1; i <= N; i++) {
            if (i == N) printf("%d\n", callcnt[i]);
            else printf("%d ", callcnt[i]);
        }
    }
    return 0;
}


