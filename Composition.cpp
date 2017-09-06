//http://hihocoder.com/contest/mstest2016oct/problem/2

//dp
#include<bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
const double eps = 1E-6;
const int MAXN = 100005;

int N, M;
char compsition[MAXN];
bool isInvalid[27][27];
int f[26];

int main()
{
    freopen("test.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &N);
    scanf("%s", compsition);
    scanf("%d", &M);
    memset(isInvalid, 0, sizeof(isInvalid));
    for (int i = 0; i < M; i++) {
        getchar();
        char a = getchar();
        char b = getchar();
        int x = a-'a';
        int y = b-'a';
        isInvalid[x][y] = true;
        isInvalid[y][x] = true;
    }
    memset(f, 0, sizeof(f));
    for (int i = 0; i < N; i++) {
        int k = compsition[i]-'a';
        int temp = 1;
        for (int j = 0; j < 26; j++) {
            if (!isInvalid[k][j]) {
                temp = max(temp, f[j] + 1);
            }
        }
        f[k] = temp;
    }
    int maxLen = 0;
    for (int j = 0; j < 26; j++) {
        maxLen = max(maxLen, f[j]);
    }
    printf("%d\n", N-maxLen);
    return 0;
}
