//http://hihocoder.com/contest/hiho167/problem/1

//思路：每一个数组的排列，会形成很多类似环的小集体，只要求出这些环的周期的最大公倍数即可
#include<bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
const double eps = 1E-6;
const int MAXN = 110;

int n;
int p[MAXN];
bool vis[MAXN];

int gcd(int a, int b) {
    while (b > 0) {
        int temp = a;
        a = b;
        b = temp % b;
    }
    return a;
}

int lco(int a, int b) {
    return (a*b) / gcd(a, b);
}

int main()
{
    freopen("test.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    memset(vis, 0, sizeof(vis));
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &p[i]);
    }
    int ret = 0;   //这里注意细节
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            vis[i] = true;
            int temp = p[i];
            int cnt = 0;
            if (temp != i) {
                do {
                    cnt++;
                    vis[temp] = true;
                    temp = p[temp];
                } while (temp != p[i]);
            }
            if (cnt > 0) {
                if (ret == 0) ret = 1;   //这里注意细节
                ret = lco(ret, cnt);
            }
        }
    }
    printf("%d\n", ret);
    return 0;
}

