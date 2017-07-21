//http://hihocoder.com/contest/hiho159

//dfs，存储坐标，判断是否相邻
#include<bits/stdc++.h>
using namespace std;

const int MAXN = 110;
const double EPS = 1e-6;

int N, M, x, y;
int pic[MAXN][MAXN];
bool visited[MAXN][MAXN];
vector<pair<int, int> > locs;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

bool isN(pair<int, int> &a, pair<int, int> &b) {
    if ((abs(a.first - b.first) == 1 && abs(a.second - b.second) == 0) ||
    (abs(a.first - b.first) == 0 && abs(a.second - b.second) == 1)){
        return true;
    }
    return false;
}

void dfs(int row, int col, int &cnt, int val) {
    visited[row][col] = true;
    cnt += 4;
    pair<int, int> pp = make_pair(row, col);
    for (int i = 0; i < locs.size(); i++) {
        if (isN(locs[i], pp)) {cnt -= 2;}
     }
    locs.push_back(pp);
    for(int i = 0; i < 4; i++) {
        int new_x = row + dx[i];
        int new_y = col + dy[i];
        if (new_x >= 0 && new_x < N && new_y >= 0 && new_y < M && visited[new_x][new_y] == false && pic[new_x][new_y] == val) {
            dfs(new_x, new_y, cnt, val);
        }
    }
}

int main () {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d %d %d %d", &N, &M, &x, &y);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%d", &pic[i][j]);
        }
    }
    memset(visited, 0, sizeof(visited));
    int cnt = 0;
    dfs(x, y, cnt, pic[x][y]);

    printf("%d\n", cnt);

    return 0;
}

//对于一个区域中的方格来说，它一共有上下左右四条长度为1边。
//其中某条边是边界的一部分当且仅当这条边另一侧的方格不是本区域的方格或者根本不存在（在地图之外）。
#include<bits/stdc++.h>
using namespace std;

const int MAXN = 110;
const double EPS = 1e-6;

int N, M, x, y;
int pic[MAXN][MAXN];
bool visited[MAXN][MAXN];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void dfs(int row, int col, int &cnt, int val) {
    visited[row][col] = true;
    for(int i = 0; i < 4; i++) {
        int new_x = row + dx[i];
        int new_y = col + dy[i];
        if (new_x < 0 || new_x >= N || new_y < 0 || new_y >= M  || pic[new_x][new_y] != val) {cnt++;}
        else if (visited[new_x][new_y] == false) {
            dfs(new_x, new_y, cnt, val);
        }
    }
}

int main () {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d %d %d %d", &N, &M, &x, &y);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%d", &pic[i][j]);
        }
    }
    memset(visited, 0, sizeof(visited));
    int cnt = 0;
    dfs(x, y, cnt, pic[x][y]);
    printf("%d\n", cnt);
    return 0;
}
