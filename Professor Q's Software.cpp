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
