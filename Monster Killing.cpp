//http://hihocoder.com/contest/mstest2017march/problem/3

//不可行的方案，想用回溯，发现存在一个大问题
#include<bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
const double eps = 1E-6;
const int MAXN = 30;

typedef pair<int, int> pii;
struct Monster {
    int h;
    int a;
};

int N, M;
char maze[MAXN][MAXN];
bool vis[MAXN][MAXN];
map<pii, int> trans;
vector<Monster> monsters;
Monster hero;
int monsterLeft;
int score = 0;
int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};

void dfs(int x, int y, int buff) {
//严重的问题：翻开的格子是可以随意跳的
//    printf("%d  %d  score=%d\n", x+1, y+1, hero.h);
//    printf("buff=%d\n", buff);
//    printf("monster=%d\n", monsterLeft);
    if (monsterLeft == 0) { score = max(score, hero.h); return; }
    if (score >= hero.h) return;  //剪枝
    int lastHeroH = hero.h;
    vis[x][y] = true;
    if (maze[x][y] == 'M' || maze[x][y] == 'S') {
        Monster monster = monsters[trans[make_pair(x, y)]];
        int detbout = (monster.h % hero.a) ? monster.h / hero.a + 1 : monster.h / hero.a;
        buff--;
        hero.h -= monster.a * max(0, detbout-buff);
        monsterLeft--;
        int newbuff = max(0, buff-detbout);
        if (maze[x][y] == 'S') newbuff = 5;
        for (int i = 0; i < 4; i++) {
            int newx = x+dx[i];
            int newy = y+dy[i];
            if (newx >= 0 && newx < N && newy >= 0 && newy < M && vis[newx][newy] == false) {
                dfs(newx, newy, newbuff);
            }
        }
        monsterLeft++;
    }
    else {
        for (int i = 0; i < 4; i++) {
            int newx = x+dx[i];
            int newy = y+dy[i];
            if (newx >= 0 && newx < N && newy >= 0 && newy < M && vis[newx][newy] == false) {
                dfs(newx, newy, max(0, buff-1));
            }
        }
    }
    vis[x][y] = false;
    hero.h = lastHeroH;
}

int main() {
    freopen("test.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    memset(vis, 0, sizeof(vis));
    int start_x, start_y;
    scanf("%d %d", &N, &M);
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        scanf("%s", maze[i]);
        for (int j = 0; j < M; j++) {
            if (maze[i][j] == 'D') {
                start_x = i;
                start_y = j;
            }
            else if (maze[i][j] != '.') {
                monsters.push_back((Monster){0, 0});
                trans[make_pair(i, j)] = cnt;
                cnt++;
            }
        }
    }
    int h, a;
    for (int i = 0; i < monsters.size(); i++) {
        scanf("%d %d", &h, &a);
        monsters[i].a = a;
        monsters[i].h = h;
    }
    scanf("%d %d", &h, &a);
    hero.a = a;
    hero.h = h;
    monsterLeft = monsters.size();
    dfs(start_x, start_y, 6);
    if (score > 0) printf("%d\n", score);
    else printf("DEAD\n");
    return 0;
}

//应该用的是状态空间搜索+剪枝

