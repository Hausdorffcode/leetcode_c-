//http://hihocoder.com/contest/hiho156/problem/1

//dfs
#include<cstdio>
#include<cstring>
const int maxn = 60;

char pic[maxn][maxn];
int visited[maxn][maxn];
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};
int N, M;

void dfs(int row, int col, int cnt) {
    visited[row][col] = cnt;
    for (int i = 0; i < 4; i++) {
        if (row+dx[i] >= 0 && row+dx[i] < N && col+dy[i] >= 0 && col+dy[i] < M && pic[row+dx[i]][col+dy[i]] == '#' && visited[row+dx[i]][col+dy[i]] == 0) {
            dfs(row+dx[i], col+dy[i], cnt);
        }
    }
}

int main() {
    freopen("input.txt", "r", stdin);
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
                dfs(i, j, ++cnt);
            }
        }
    }

    printf("%d\n", cnt );

  return 0;
}