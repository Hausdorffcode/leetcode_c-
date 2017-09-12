//http://hihocoder.com/contest/mstest2015jan1/problem/2

//O(nlgn)
#include<bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
const double eps = 1E-6;
const int MAXN = 100010;

int disk[MAXN];

int main()
{
    freopen("test.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n, m, h, r;
    scanf("%d %d %d %d", &n, &m, &h, &r);
    for (int i = 0; i < n; i++) {
        scanf("%d", &disk[i]);
    }
    sort(disk, disk+n);
    int s = 0;
    int ret = 0;
    for (int i = 0; i < n; i++) {
        if (i != 0 && disk[i]-disk[i-1] > m) {
            s = 0;
        }
        if (r+s < disk[i]) break;
        s++;
        ret++;
    }
    printf("%d\n", min(ret, h));
    return 0;
}

