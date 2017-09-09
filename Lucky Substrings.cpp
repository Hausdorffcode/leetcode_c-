//http://hihocoder.com/contest/mstest2015april2/problem/1

//粗暴，另外set中的元素是有序的，有很多可改进的地方 O(n^3)
#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
const double eps = 1E-6;
const int MAXN = 110;

int cnt(string s) {
    int c = 0;
    sort(s.begin(), s.end());
    for (int i = 0; i < s.size(); i++) {
        if (i == 0 || s[i] != s[i-1]) {
            c++;
        }
    }
    return c;
}

void generatefib(set<int>& s) {
    int a = 1;
    int b = 1;
    while (a <= 30) {
        int temp = a;
        a = b;
        b = temp + b;
        s.insert(a);
    }
}

int main()
{
    freopen("test.txt", "r", stdin);
    string s;
    cin >> s;
    set<string> ret;
    set<int> fib;
    generatefib(fib);
    for (int i  = 0; i < s.size(); i++) {
        for (int j = i; j < s.size(); j++) {
            string temp = s.substr(i, j-i+1);
            int c = cnt(temp);
            if (fib.count(c)) {
                ret.insert(temp);
            }
        }
    }
    for (set<string>::iterator it = ret.begin(); it != ret.end(); it++) {
        cout << *it << endl;
    }
    return 0;
}


//O(n^2)
#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
const double eps = 1E-6;
const int MAXN = 110;

bool alphabet[26];
int cnt;
set<int> fib;

void generatefib(set<int>& s) {
    int a = 1;
    int b = 1;
    while (a <= 30) {
        int temp = a;
        a = b;
        b = temp + b;
        s.insert(a);
    }
}

bool isLucky(char c) {
    if (!alphabet[c-'a']) {
        alphabet[c-'a'] = true;
        cnt++;
    }
    return fib.count(cnt) > 0;
}

int main()
{
    freopen("test.txt", "r", stdin);
    generatefib(fib);
    string s;
    vector<string> ret;
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
        memset(alphabet, 0, sizeof(alphabet));
        cnt = 0;
        for (int j = i; j < s.size(); j++) {
            if (isLucky(s[j])) {
                ret.push_back(s.substr(i, j-i+1));
            }
        }
    }
    sort(ret.begin(), ret.end());
    for (int i = 0; i < ret.size(); i++) {
        if (i == 0 || ret[i] != ret[i-1]) {
            cout << ret[i] << endl;
        }
    }
    return 0;
}



