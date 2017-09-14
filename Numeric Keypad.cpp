//http://hihocoder.com/problemset/problem/1153

//比较丑陋
#include<bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
const double eps = 1E-6;
const int MAXN = 10;

int trans[10][10] = {{1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                     {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
                     {1, 0, 1, 1, 0, 1, 1, 0, 1, 1},
                     {0, 0, 0, 1, 0, 0, 1, 0, 0, 1},
                     {1, 0, 0, 0, 1, 1, 1, 1, 1, 1},
                     {1, 0, 0, 0, 0, 1, 1, 0, 1, 1},
                     {0, 0, 0, 0, 0, 0, 1, 0, 0, 1},
                     {1, 0, 0, 0, 0, 0, 0, 1, 1, 1},
                     {1, 0, 0, 0, 0, 0, 0, 0, 1, 1},
                     {0, 0, 0, 0, 0, 0, 0, 0, 0, 1}};
string k;
vector<int> ret;

bool dfs(int last, int below) {
    if (ret.size() >= k.size()) {
        for (int i = 0; i < ret.size(); i++) {
            cout << ret[i];
        }
        cout<<endl;
        return true;
    }
    if (below) {
        int digit = -1;
        for (int j = 0; j < 10; j++) {
            if (trans[last][j] && digit < j) {
                digit = j;
            }
        }
        for (int i = 0; i < ret.size(); i++) {
            cout << ret[i];
        }
        for (int i = 0; i < k.size()-ret.size(); i++) {   //不可能比原来少一位
            cout << digit;
        }
        cout<<endl;
        return true;
    }
    for (int i = 9; i >= 0; i--) {
        if (trans[last][i] && i <= k[ret.size()]-'0') {
            ret.push_back(i);
            if (dfs(i, i < k[ret.size()-1]-'0')) return true;
            ret.pop_back();
        }
    }
    return false;
}

int main()
{
    freopen("test.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int T;
    cin >> T;
    while (T--) {
        ret.clear();
        cin >> k;
        dfs(1, false);
    }
    return 0;
}

//大神的代码
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

bool islink(int a, int b)
{
	a -= '0', b -= '0';
	return a == 0 ? a == b : (b == 0 ? a % 3 != 0 : (a <= b && (a - 1) % 3 <= (b - 1) % 3));
}

int main()
{
	int t;
	string k, ans;

	cin >> t;
	while (t--) {
		cin >> k;
		//reverse(k.begin(), k.end());
		//while (k.size() > 1 && *k.rbegin() == '0')k.pop_back();
		//reverse(k.begin(), k.end());

		ans.clear();
		bool  isfollow = true;
		int lastdigit = k[0];
		for (int i = 1; i < k.size(); i++) {
			int nowdigit = k[i];

			ans.push_back(lastdigit);
			if (islink(lastdigit, nowdigit) && isfollow) {
				lastdigit = nowdigit;
			}
			else {
				int filldigit = (isfollow ? nowdigit : '9');
				while (!islink(lastdigit, filldigit) && filldigit >= '0')filldigit--;
				if (filldigit < '0') {
					bool is_ok = false;
					i--, ans.pop_back();
					while (i >= 1 && !is_ok) {
						for (int mm = 1; !is_ok&& k[i] - mm >= '0'; mm++) {
							if (islink(k[i - 1], k[i] - mm)) {
								lastdigit = k[i] - mm;
								is_ok = true;
							}
						}
						if (!is_ok) {
							i--, ans.pop_back();
						}
					}
					if (!is_ok) {
						lastdigit = k[i] - 1;
					}
				}
				else {
					lastdigit = filldigit;
				}
				isfollow = false;
			}
		}
		if (ans.size() < k.size()) {
			ans.push_back(lastdigit);
		}
		cout << ans << endl;
	}
	//system("pause");
	return 0;
}

