//http://hihocoder.com/problemset/problem/1092

//bfs，最短路，只要找到两个相邻的s，把他们的最短路径相加即可
#include<bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
const double eps = 1E-6;
const int MAXN = 110;

struct point{
    int x;
    int y;
    point(int x, int y) : x(x), y(y) {}
};

int N, M;
char cafeteria[MAXN][MAXN];
int vis[MAXN][MAXN];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
queue<point> q;

int cal(int x, int y) {
    bool ok = false;
    int ret = INF;
    for (int i = 0; i < 4; i++) {
        int xx = x+dx[i];
        int yy = y+dy[i];
        if (xx >= 0 && xx < N && yy >= 0 && yy < M && vis[xx][yy] > 0 && ret > vis[xx][yy] && cafeteria[xx][yy] == 'S') {
            ret = vis[xx][yy];
        }
    }
    if (ret == INF) return 0;
    else return ret + vis[x][y];
}

int main() {
    freopen("test.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d %d", &N, &M);
    memset(vis, 0, sizeof(vis));
    int startx, starty;
    for (int i = 0; i < N; i++) {
        scanf("%s", cafeteria[i]);
        for (int j = 0; j < M; j++) {
            if (cafeteria[i][j] == 'H') {
                startx = i;
                starty = j;
            }
        }
    }
    point p(startx, starty);
    int cnt = 0;
    q.push(p);
    bool ok = false;
    int ret = 0;
    while (!q.empty()) {
        point temp = q.front(); q.pop();
        int xx = temp.x;
        int yy = temp.y;
        if (cafeteria[xx][yy] == 'S') {
            ret = cal(xx, yy);
            //printf("%d\n", ret);
            if (ret > 0) {
                ok = true;
                break;
            }
            continue;
        }
        for (int i = 0; i < 4; i++) {
            int xxx = xx+dx[i];
            int yyy = yy+dy[i];
            if (xxx >= 0 && xxx < N && yyy >= 0 && yyy < M && (cafeteria[xxx][yyy] == '.' || cafeteria[xxx][yyy] == 'S') && vis[xxx][yyy] == 0) {
                point pp(xxx, yyy);
                vis[xxx][yyy] = vis[xx][yy] + 1;
                q.push(pp);
            }
        }
    }
    if (ok) printf("%d\n", ret);
    else printf("Hi and Ho will not have lunch.\n");
    return 0;
}
