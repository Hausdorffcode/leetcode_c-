//http://hihocoder.com/contest/mstest2015april/problem/1

//模拟
#include<bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
const double eps = 1E-6;
const int MAXN = 20010;

int x, y, z;
vector<int> cha;
int cr, cy, cb;
int cr_cy, cr_cb, cy_cb;
char RYB[MAXN];

bool equals() {
    vector<int> ccha;
    ccha.push_back(cr_cb);
    ccha.push_back(cr_cy);
    ccha.push_back(cy_cb);
    sort(ccha.begin(), ccha.end());
    bool ok = true;
    for (int i = 0;  i< 3; i++) {
        if (cha[i] != ccha[i]) {
            ok = false;
            break;
        }
    }
    return ok;
}

int main() {
    freopen("test.txt", "r", stdin);
    scanf("%d %d %d", &x, &y, &z);
    cha.push_back(x);
    cha.push_back(y);
    cha.push_back(z);
    sort(cha.begin(), cha.end());
    scanf("%s", RYB);
    int p = 0;
    int maxBalls = 0;
    while (RYB[p]) {
        if (RYB[p] == 'R') {
            cr++;
            cr_cb = abs(cr-cb);
            cr_cy = abs(cr-cy);
        }
        else if (RYB[p] == 'Y') {
            cy++;
            cr_cy = abs(cr-cy);
            cy_cb = abs(cy-cb);
        }
        else {
            cb++;
            cr_cb = abs(cr-cb);
            cy_cb = abs(cy-cb);
        }
        if (equals()) {
            maxBalls = max(maxBalls, cr+cb+cy);
            cr = 0;
            cb = 0;
            cy = 0;
        }
        p++;
    }
    maxBalls = max(maxBalls, cr+cb+cy);
    printf("%d\n", maxBalls);
    return 0;

}
