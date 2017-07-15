//https://vjudge.net/problem/UVA-572
#include<bits/stdc++.h>
using namespace std;

const int maxn = 105;

char oil[maxn][maxn];
int idx[maxn][maxn];
int m, n;

bool isOk(int i, int j)
{
    return i >= 0 && i < m && j >= 0 && j < n;
}

void dfs(int i, int j, int n)
{
    idx[i][j] = n;
    for (int dr = -1; dr <= 1; dr++) {
        for (int dc = -1; dc <= 1; dc++) {
            if (isOk(i+dr, j+dc) && oil[i+dr][j+dc] == '@' && (dr != 0 || dc != 0) && idx[i+dr][j+dc] == 0) {
                dfs(i+dr, j+dc, n);
            }
        }
    }
}

void dfs1(int r, int c, int id)
{
    if(r < 0 || r >= m || c < 0 || c >= n) return;
    //if (!isOk(r, c)) return;
    if (oil[r][c] != '@' || idx[r][c] > 0) return;
    idx[r][c] = id;

    for(int dr = -1; dr <= 1; dr++){
        for(int dc = -1; dc <= 1; dc++){
            if(dr != 0 || dc != 0) dfs1(r+dr, c+dc, id);
        }
    }
}

int main () {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    while (scanf("%d %d", &m, &n) == 2 && m != 0) {
        for (int i = 0; i < m; i++) {
            scanf("%s", oil[i]);
        }
        memset(idx, 0, sizeof(idx));
        int cnt = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (idx[i][j] == 0 && oil[i][j] == '@') {
                    dfs(i, j, ++cnt);
                }
            }
        }
        printf("%d\n", cnt);
    }
    return 0;
}