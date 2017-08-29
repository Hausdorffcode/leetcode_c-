//http://hihocoder.com/contest/hiho164/problem/1

//dp， 可以使用贪心
#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1010;
const double EPS = 1e-6;

int num[MAXN];
int T;
string s;
int f[MAXN];
int g[MAXN];

int main () {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> T;
    getchar();
    while (T--) {
        getline(cin, s);
        memset(g, 0, sizeof(g));
        memset(f, 0, sizeof(f));
        for (int i = 0; i < s.size(); i++){
            if (i == 0) {
                if (s[i] == '0') {
                    g[i] = 1;
                }
                else {
                    f[i] = 1;
                }
            }
            else {
                int temp = min(f[i-1], g[i-1]);
                if (s[i] == '0') {
                    f[i] = f[i-1];
                    g[i] = temp + 1;

                }
                else {
                    f[i] = f[i-1] + 1;
                    g[i] = temp;
                }
            }
        }
        printf("%d\n", min(f[s.size()-1], g[s.size()-1]));
    }
    return 0;
}
