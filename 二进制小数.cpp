//http://hihocoder.com/contest/hiho157/problem/1

//“高精度”算法
#include<bits/stdc++.h>
using namespace std;
const int MAXN = 60;
const double EPS = 1e-6;


int cal(string& s, int cur) {
    int carry = 0;
    for (int i = cur; i >= 2; i--) {
        int temp = carry + 2 * (s[i]-'0');
        s[i] = '0'+temp % 10;
        carry = temp / 10;
    }
    return carry;
}

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    string str;
    string ret;
    while (t--) {
        cin >> str;
        //cout << str << endl;
        int cur = str.size()-1;
        //printf("cur=%d\n", cur);
        bool ok = true;
        ret = "0.";
        while (cur > 1) {
            if (str[cur] != '5') { cout << "NO" <<endl; ok = false; break;}
            int c = cal(str, cur);
            //cout << str << endl;
            ret.push_back('0'+c);
            cur--;
        }
        if (ok) cout << ret << endl;
    }
    return 0;
}