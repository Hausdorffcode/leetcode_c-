//http://hihocoder.com/contest/hiho158/problem/1

//dp 缺啥补啥
const int p = 1e9+7;
long long f[101];
long long g[101];
long long h[101];

int main()
{
    //freopen("test.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n;
    scanf("%d", &n);
    f[1] = 0;
    g[1] = 1;
    h[1] = 1;
    long long factor = 2;
    for (int i = 2; i <= n; i++) {
        factor *= 2;
        factor %= p;
        f[i] = (f[i-1] * 2 + g[i-1]) % p;
        g[i] = h[i-1];
        h[i] = factor - f[i] - g[i];
        while (h[i] < 0) {
            h[i] += p;
        }
    }
    printf("%d\n", f[n]);
    return 0;
}