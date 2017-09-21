//http://hihocoder.com/problemset/problem/1174?sid=1176258

//拓扑排序，判断图中是否存在环 O(N+M)
#include<bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
const double eps = 1E-6;
const int MAXN = 500010;

int n, M;
int x, y;
int deg[MAXN];
queue<int> q;

//注意这里邻接表的表示
int edgecnt;
int p[MAXN];
int head[MAXN];
int nextEdge[MAXN];

void init () {
    edgecnt = 0;
    memset(p, 0, sizeof(p));
    memset(head, 0, sizeof(head));
    memset(nextEdge, 0, sizeof(nextEdge));
    memset(deg, 0, sizeof(deg));
}

void addedge(int u, int v) {
    ++edgecnt;
    p[edgecnt] = v;
    nextEdge[edgecnt] = head[u];
    head[u] = edgecnt;
}

int main() {
    freopen("test.txt", "r", stdin);
    int T;
    scanf("%d", &T);
    while (T--) {
        init();
        scanf("%d %d", &n, &M);
        for (int i = 0; i < M; i++) {
            scanf("%d %d", &x, &y);
            addedge(x, y);
            deg[y]++;
        }
        for (int i = 1; i <= n; i++) {
            if (deg[i] == 0) q.push(i);
        }
        int cnt = 0;
        while (!q.empty()) {
            cnt++;
            int discard_point = q.front(); q.pop();
            for (int i = head[discard_point]; i ; i = nextEdge[i]) {
                deg[p[i]] -= 1;
                if (deg[p[i]] == 0) q.push(p[i]);
            }
        }
        if (cnt == n) printf("Correct\n");
        else printf("Wrong\n");
    }
    return 0;
}

//也可以用dfs来判断是否有环
#include<stdio.h>
#include<memory.h>

inline int readInt()
{
    int val = 0, ch;
    while(((unsigned)(ch = getchar() - '0')) > 9)
        ;
    val = ch;
    while(((unsigned)(ch = getchar() - '0')) <= 9)
        val = (val << 3) + (val << 1) + ch;
    return val;
}

#define N 100001
#define M 500001
int hd[N];
int va[M];
int nx[M];
int cnt = 1;
int n,m;
void addEdge(int u,int v){
    va[cnt] = v;
    nx[cnt] = hd[u];
    hd[u] = cnt++;
}
char vis[N];
bool DFS(int start){
    vis[start] = -1;
    for(int i = hd[start];i ; i = nx[i]){
        if(vis[va[i]] == -1){
            return false;
        }else if(vis[va[i]] == 0){
            if(!DFS(va[i])){
                return false;
            }
        }
    }
    vis[start] = 1;
    return true;
}
int main(){
    int T;
    int u,v;
    T = readInt();
    while(T--){
        n = readInt();
        m = readInt();
        memset(hd,0,sizeof(int)*(n+1));
        memset(vis,0,sizeof(char)*(n+1));
        cnt = 1;
        for(int i = 0; i < m;i++){
            u = readInt();
            v = readInt();
            addEdge(u,v);
        }
        bool flag = true;
        for(int i = 1; i <= n;i++){
            if(vis[i] == 0 && !DFS(i)){
                flag = false;
                break;
            }
        }
        if(flag){
            printf("Correct\n");
        }else{
            printf("Wrong\n");
        }
    }
}
