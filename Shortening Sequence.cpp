//http://hihocoder.com/contest/mstest2016oct/problem/1

//math
#include <bits/stdc++.h>
using namespace std;

int main () {
    int n;
    scanf("%d", &n);
    int odd_cnt = 0;
    int even_cnt = 0;
    int num;
    for (int i = 0;i < n; i++) {
        scanf("%d", &num);
        if (num & 0x1) {
            even_cnt++;
        }
        else {
            odd_cnt++;
        }
    }
    printf("%d", abs(even_cnt - odd_cnt));
}