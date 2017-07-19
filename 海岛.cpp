//http://hihocoder.com/contest/hiho156/problem/1

//dfs，用相对位置判断岛屿形状
#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
const double eps = 1E-6;
const int MAXN = 60;

char pic[MAXN][MAXN];
int visited[MAXN][MAXN];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
int N, M;
vector<int> area;
set<vector<pair<int, int> > > locs;

void dfs(int row, int col, int cnt, int &a, vector<pair<int, int> > &loc, int rx, int ry) {
    visited[row][col] = cnt;
    a++;
    loc.push_back(make_pair(row-rx, col-ry));
    for (int i = 0; i < 4; i++) {
        if (row+dx[i] >= 0 && row+dx[i] < N && col+dy[i] >= 0 && col+dy[i] < M && pic[row+dx[i]][col+dy[i]] == '#' && visited[row+dx[i]][col+dy[i]] == 0) {
            dfs(row+dx[i], col+dy[i], cnt, a, loc, rx, ry);
        }
    }
}

bool isSame(vector<pair<int, int> > &c1, vector<pair<int, int> > &c2) {
    int n = c1.size();
    if (n == 0) return true;
    int dx = c1[0].first - c2[0].first;
    int dy = c1[0].second - c2[0].second;
    bool ok = true;
    for (int i = 1; i < n; i++) {
        if (dx != c1[i].first - c2[i].first || dy != c1[i].second - c2[i].second) {
            ok = false;
            break;
        }
    }
    return ok;
}

int main()
{
    freopen("test.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int cnt = 0;
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++) {
        scanf("%s", pic[i]);
    }

    memset(visited, 0, sizeof(visited));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (visited[i][j] == 0 && pic[i][j] == '#') {
                int a = 0;
                vector<pair<int, int> > loc;
                dfs(i, j, ++cnt, a, loc, i, j);
                area.push_back(a);
                locs.insert(loc);
            }
        }
    }



    int ac = 0;
    sort(area.begin(), area.end());
    for (int i = 0; i < area.size(); i++) {
        if (!i || area[i] != area[i-1]) ac++;
    }
    printf("%d %d %d\n", cnt, ac, locs.size());
    return 0;
}