//http://hihocoder.com/contest/hiho98/problem/1


//搜索，利用这6种运算，可以将所有可能的计算过程归结为2类
#include<bits/stdc++.h>
using namespace std;
const int MAXN = 60;
const double EPS = 1e-6;

char op[] = "+-*/#$";
const double aim = 24;


double cal(double a, double b, char o) {
    if (o == '+') return a+b;
    if (o == '-') return a-b;
    if (o == '*') return a*b;
    if (o == '/' && b != 0) return a/b;
    if (o == '#') return b-a;
    if (o == '$' && a != 0) return b/a;
    return -10000;
}

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t;
    vector<double> nums(4);
    scanf("%d", &t);
    for (int i = 0; i < t; i++) {
        scanf("%lf %lf %lf %lf", &nums[0], &nums[1], &nums[2], &nums[3]);
        //printf("%d %d %d %d\n", nums[0], nums[1], nums[2], nums[3]);
        bool ok = false;
        sort(nums.begin(), nums.end());
        do {
            if (ok) break;
            //printf("%d %d %d %d\n", nums[0], nums[1], nums[2], nums[3]);
            for (int x = 0; x < 6; x++){
                if (ok) break;
                for (int y = 0; y < 6; y++) {
                    if (ok) break;
                    for (int z = 0; z < 6; z++) {
                        double ans = 0;
                        ans = cal(nums[0], nums[1], op[x]);
                        ans = cal(ans, nums[2], op[y]);
                        ans = cal(ans, nums[3], op[z]);
                        //printf("%d\n", ans);
                        //printf("%c %c %c\n", op[x], op[y], op[z]);
                        //printf("%d %d %d %d\n", nums[0], nums[1], nums[2], nums[3]);
                        if (abs(ans-aim)<EPS) {printf("Yes\n"); ok = true; break;}

                        ans = cal(nums[0], nums[1], op[x]);
                        double temp = cal(nums[2], nums[3], op[z]);
                        ans = cal(ans, temp, op[y]);
                        if (abs(ans-aim)<EPS) {printf("Yes\n"); ok = true; break;}
                        //printf("%d\n", ans);
                    }
                }
            }
        } while(next_permutation(nums.begin(), nums.end()));
        if (!ok) printf("No\n");
    }
    return 0;
}
