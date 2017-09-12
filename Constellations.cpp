//http://hihocoder.com/contest/mstest2015jan1/problem/1

//一定要找相对坐标
//枚举星星即可
#include<bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
const double eps = 1E-6;
const int MAXN = 110;

struct star {
    int cnt = 0;   //星空中的星星数
    //星星相对坐标
    int x[MAXN];
    int y[MAXN];
};

int K, N, M;
star constellation[30];
char sky[1010][1010];

bool isMatch(int index, int p, int q) {
    for (int i = 1; i < constellation[index].cnt; i++) {
        int dx = constellation[index].x[i] + p;
        int dy = constellation[index].y[i] + q;
        if (dx < 0 || dy < 0 || dx >= N || dy >= M || sky[dx][dy] != '#') return false;
    }
    return true;
}

int main()
{
    freopen("test.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &K);
    for (int i = 0; i< K ; i++) {
        int h, w;
        scanf("%d %d", &h, &w);
        int start_x, start_y;
        for (int j = 0; j < h; j++) {
            char c[MAXN];
            scanf("%s", c);
            for (int k = 0; k < w; k++) {
                if (c[k] == '#') {
                    if (constellation[i].cnt == 0) {
                        start_x = j;
                        start_y = k;
                        constellation[i].cnt++;
                    }
                    else {
                        constellation[i].x[constellation[i].cnt] = j-start_x;
                        constellation[i].y[constellation[i].cnt] = k-start_y;
                        constellation[i].cnt++;
                    }

                }
            }
        }
    }
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++) {
        scanf("%s", sky[i]);
    }

    for (int i = 0; i < K; i++) {
        int ok = false;              //这个bug找了一天。。。。不能初始为true（空白星空）
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < M; k++) {
                if (sky[j][k] == '#') {
                    ok = isMatch(i, j, k);
                    if (ok) break;
                }
            }
            if (ok) break;
        }
        if (ok) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}

//大神的代码
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
using namespace std;

vector< pair<int, int> > cta[21];
char sky[1002][1002];
bool have[21];
int n, m, k;

bool inMap(int x, int y) {
    return (1 <= x && x <= n && 1 <= y && y <= m);
}

int main()
{
    char line[ 1002 ];
    //freopen("constellation.in", "r", stdin);
    scanf("%d", &k);
    for (int t = 0; t < k; ++t) {
        int h, w;
        scanf("%d %d", &h, &w);
        for (int i = 1; i <= h; ++i) {
            scanf("%s", line + 1);
            for (int j = 1; j <= w; ++j)
            if (line[j] == '#') {
                if (cta[t].size() == 0)
                    cta[t].push_back( make_pair(i, j) );
                else cta[t].push_back( make_pair(i - cta[t][0].first, j - cta[t][0].second) );
            }
        }

        cta[t][0] = make_pair(0, 0);
    }
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; ++i)
        scanf("%s", sky[i] + 1);

    memset(have, 0, sizeof(have));
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            if (sky[i][j] == '#')
                for (int t = 0; t < k; ++t) {
                    if (have[t]) continue;
                    bool flag = true;
                    for (int p = 0; p != (int) cta[t].size(); ++p)
                        if (!inMap(i + cta[t][p].first, j + cta[t][p].second) || sky[i + cta[t][p].first][j + cta[t][p].second] != '#')
                            flag = false;
                    have[t] = flag;
                }
    for (int i = 0; i < k; ++i)
        if (have[i]) printf("Yes\n");
        else printf("No\n");
    //fclose(stdin);
    return 0;
}

