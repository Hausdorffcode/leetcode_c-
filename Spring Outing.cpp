//http://hihocoder.com/problemset/problem/1154?sid=1174431

//数学，模拟，博弈，看hint可知从后往前推即可
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1010;

int N, K;
int P;
int f[MAXN][MAXN];

int main()
{
    freopen("test.txt", "r", stdin);
    scanf("%d %d", &N, &K);
    for (int j = 0; j < N; j++) {
        for (int i = 0; i <= K; i++) {
            scanf("%d", &P);
            f[j][P] = i;
        }
    }

    int lastChoose = 0;
    for (int i = K; i > 0; i--) {
        int cnt = 0;
        for (int j = 0; j < N; j++) {
            if (f[j][lastChoose] > f[j][i]) {
                cnt++;
            }
        }
        if (cnt > N/2) lastChoose = i;
    }
    if (lastChoose == 0) printf("otaku\n");
    else printf("%d\n", lastChoose);
    return 0;
}
