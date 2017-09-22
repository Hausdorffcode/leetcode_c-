//http://hihocoder.com/problemset/problem/1094?sid=1176755

//枚举中心点
#include<bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
const double eps = 1E-6;
const int MAXN = 210;

int N, M;
char maze[MAXN][MAXN];
char surrounding[4][4];

vector<pair<int, int> > ret;

bool isok(int x, int y) {
    bool ok = true;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (surrounding[2+i][2+j] != maze[x+i][y+j]) {ok = false; break;}
        }
    }
    if (ok) return ok;
    ok = true;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (surrounding[2+i][2+j] != maze[x+j][y-i]) {ok = false; break;}
        }
    }
    if (ok) return ok;
    ok = true;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (surrounding[2+i][2+j] != maze[x-i][y-j]) {ok = false; break;}
        }
    }
    if (ok) return ok;
    ok = true;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (surrounding[2+i][2+j] != maze[x-j][y+i]) {ok = false; break;}
        }
    }
    if (ok) return ok;
    return false;
}

int main() {
    freopen("test.txt", "r", stdin);
    scanf("%d %d", &N, &M);
    for (int i = 1; i <= N; i++) {
        scanf("%s", maze[i]+1);
    }
//    for (int i = 1; i <= N; i++) {
//        for (int j = 1; j<= M; j++) {
//            printf("%c", maze[i][j]);
//        }
//        printf("\n");
//    }
    for (int i = 1; i <= 3; i++) {
        scanf("%s", surrounding[i]+1);
    }
    for (int i = 2; i < N; i++) {
        for (int j = 2; j < M; j++) {
            if (maze[i][j] == surrounding[2][2] && isok(i, j)) {
                ret.push_back(make_pair(i, j));
            }
        }
    }

    for (int i = 0; i < ret.size(); i++) {
        printf("%d %d\n", ret[i].first, ret[i].second);
    }
    return 0;

}
