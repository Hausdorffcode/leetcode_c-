//http://hihocoder.com/problemset/problem/1237?sid=1197993

//计算几何，有选择地枚举，浮点精度
#include<bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
const double eps = 1E-6;
const int MAXN = 100010;

double x, y, r;
double far = 0;

double calSDistpower(double i, double j) {
    return i*i + j*j;
}

int main() {
    freopen("test.txt", "r", stdin);
    cin >> x >> y >> r;
    int retx = x, rety = y;
    int rhsx = floor(x+r);
    int lhsx = ceil(x-r);
    for (int i = lhsx; i <= rhsx; i++) {
        double d = sqrt(r*r-(i-x)*(i-x));
        int uhsy = floor(y+d);
        double power = calSDistpower(i-x, uhsy-y);
        double det = far - power;
        if (det < -eps || (abs(det) < eps && (i > retx || i == retx && uhsy > rety))) {
            retx = i;
            rety = uhsy;
            far = power;
        }
        int dhsy = ceil(y-d);
        power = calSDistpower(i-x, dhsy-y);
        det = far - power;
        if (det < -eps || (abs(det) < eps && (i > retx || i == retx && dhsy > rety))) {
            retx = i;
            rety = dhsy;
            far = power;
        }
    }
    printf("%d %d\n", retx, rety);
    return 0;
}
