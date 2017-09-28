//http://hihocoder.com/problemset/problem/1102?sid=1196390

f'(y) = 
    3500 + y / 0.03 (y ≤ 45)
    5000 + (y - 45) / 0.1 (45 < y ≤ 345)
    8000 + (y - 345) / 0.2 (345 < y ≤ 1245)
    12500 + (y - 1245) / 0.25 (1245 < y ≤ 7745)
    38500 + (y - 7745) / 0.3 (7745 < y ≤ 13745)
    58500 + (y - 13745) / 0.35 (13745 < y ≤ 22495)
    83500 + (y - 22495) / 0.45 (22495 < y)
	
	
//数学
#include<bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
const double eps = 1E-6;
const int MAXN = 100010;


int main() {
    //freopen("test.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    double y;
    scanf("%lf", &y);
    int ret =0;
    if (y<=45) ret = 3500 + y/0.03;
    else if (y<= 345) ret = 3500+(y-45)/0.1;
    else if (y<=1245) ret = 8000+(y-345)/0.2;
    else if (y<=7745) ret = 12500+(y-1245)/0.25;
    else if (y<=13745) ret = 38500+(y-7745)/0.3;
    else if (y<=22495) ret = 58500+(y-13745)/0.35;
    else ret = 83500+(y-22495)/0.45;
    printf("%d\n", ret);
    return 0;
}
