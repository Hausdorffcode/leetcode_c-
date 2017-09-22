//http://hihocoder.com/problemset/problem/1061?sid=1175242

//边遍历边统计字符个数，集齐3个不同的就判断一下
#include<bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
const double eps = 1E-6;
const int MAXN = 110;

char lastchar;
int lastcnt;
vector<int> cnt;

bool check() {
    if (cnt[2] >= cnt[1] && cnt [1] <= cnt[0]) return true;
    return false;
}

int main() {
    freopen("test.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int T;
    cin >> T;
    while (T--) {
        lastcnt = 0;
        lastchar = 'A';
        cnt.clear();
        int n;
        cin >> n;
        string s;
        cin >> s;
        bool ok = false;
        for (int i = 0; i < s.size();) {
            char nowchar = s[i];
            int nowcnt = 0;
            while (s[i] == nowchar) {
                i++;
                nowcnt++;
            }
            if (nowchar-lastchar == 1) {
                cnt.push_back(nowcnt);
                if (cnt.size() == 3) {
                    ok = check();
                    if (ok) { break;}
                    else {
                        cnt.erase(cnt.begin());
                    }
                }
            }
            else {
                cnt.clear();
                cnt.push_back(nowcnt);
            }
            lastchar = nowchar;
            lastcnt = nowcnt;
        }
        if (ok) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
