//http://hihocoder.com/problemset/problem/1570?sid=1169529

//暴力，但这代码不忍直视啊。。。。
#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
const double eps = 1E-6;
const int MAXN = 110;

struct Point{
    double x;
    double y;
};

struct TriAngle{
    Point A;
    Point B;
    Point C;
};

Point p[360010];

double calArea(Point p1, Point p2, Point p3) {
    double ret = p1.x*p3.y + p2.x*p1.y + p3.x*p2.y - p1.x*p2.y - p2.x*p3.y - p3.x*p1.y;
    return ret > 0 ? ret : -ret;
}

Point calzhong(Point p1, Point p2, Point p3) {
    double x = (p1.x+p2.x+p3.x) /3;
    double y = (p1.y+p2.y+p3.y) /3;
    Point p;
    p.x = x;
    p.y = y;
    return p;
}

int main()
{
    //freopen("test.txt", "r", stdin);
    int T;
    scanf("%d", &T);
    while (T--) {
        int N, U;
        scanf("%d %d", &N, &U);
        for (int i = 0; i<N;i++) {
            double x, y;
            scanf("%lf %lf", &x, &y);
            p[i].x = x;
            p[i].y = y;
        }
        double bigArea = -1;
        double smallArea = INF;
        TriAngle big, small;
        for (int i = 0; i < N; i++) {
            for (int j = i+1; j < N; j++) {
                for (int k = j+1; k < N; k++) {
                    double area = calArea(p[i], p[j], p[k]);

                    if (area < smallArea && area > 0) {
                        small.A = p[i];
                        small.B = p[j];
                        small.C = p[k];
                        smallArea = area;
                    }
                    if (area == smallArea) {
                        Point zhong = calzhong(p[i], p[j], p[k]);
                        Point s = calzhong(small.A, small.B, small.C);
                        if (zhong.x < s.x || ((zhong.x == s.x) && (zhong.y < s.y))) {
                            small.A = p[i];
                            small.B = p[j];
                            small.C = p[k];
                            smallArea = area;
                        }

                    }
                    if (area > bigArea) {
                        big.A = p[i];
                        big.B = p[j];
                        big.C = p[k];
                        bigArea = area;
                    }
                    if (area == bigArea) {
                        Point zhong = calzhong(p[i], p[j], p[k]);
                        Point b = calzhong(big.A, big.B, big.C);
                        if (zhong.x > b.x || ((zhong.x == b.x) && (zhong.y > b.y))) {
                            big.A = p[i];
                            big.B = p[j];
                            big.C = p[k];
                            bigArea = area;
                        }

                    }
                }
            }
        }
        Point hi, ho;
        hi.x = (big.A.x + big.B.x + big.C.x) / 3;
        //printf("hi=%lf  %lf  %lf", big.A.x, big.B.x, big.C.x);
        hi.y = (big.A.y + big.B.y + big.C.y) / 3;
        ho.x = (small.A.x + small.B.x + small.C.x) / 3;
        ho.y = (small.A.y + small.B.y + small.C.y) / 3;
        double dict = sqrt((hi.x-ho.x) * (hi.x-ho.x) + (hi.y-ho.y) * (hi.y-ho.y));
        double t = dict / U / 2;   //比赛时忘记/2了。。。。。
        printf("%.2lf\n", t);
    }
    return 0;
}


//大神的代码，还是要学习一下啊
#include <bits/stdc++.h>
using namespace std;

int t, n, u;
int x[55], y[55];

void chooseMin(int &a, int &b, int &c, const int &i, const int &j, const int &k) {
  if (x[a] + x[b] + x[c] > x[i] + x[j] + x[k]) {
    a = i, b = j, c = k;
    return ;
  }
  if (x[a] + x[b] + x[c] == x[i] + x[j] + x[k])
    if (y[a] + y[b] + y[c] > y[i] + y[j] + y[k])
      a = i, b = j, c = k;
}

void chooseMax(int &a, int &b, int &c, const int &i, const int &j, const int &k) {
  if (x[a] + x[b] + x[c] < x[i] + x[j] + x[k]) {
    a = i, b = j, c = k;
    return ;
  }
  if (x[a] + x[b] + x[c] == x[i] + x[j] + x[k])
    if (y[a] + y[b] + y[c] < y[i] + y[j] + y[k])
      a = i, b = j, c = k;
}

int area(const int &i, const int &j, const int &k) {
  return abs(x[i] * y[j] + x[j] * y[k] + x[k] * y[i] - x[i] * y[k] - x[j] * y[i] - x[k] * y[j]);
}

double solve() {
  int sa, sb, sc, ba, bb, bc, minS = (int)1e9, maxS = 0;
  for (int i = 0; i < n; ++i)
    for (int j = i + 1; j < n; ++j)
      for (int k = j + 1; k < n; ++k) {
        int s = area(i, j, k);
        if (s == 0)
          continue;
        if (s < minS)
          sa = i, sb = j, sc = k, minS = s;
        else if (s == minS)
          chooseMin(sa, sb, sc, i, j, k);
        if (s > maxS)
          ba = i, bb = j, bc = k, maxS = s;
        else if (s == maxS)
          chooseMax(ba, bb, bc, i, j, k);
      }
  double xs = x[sa] + x[sb] + x[sc];
  xs /= 3;
  double ys = y[sa] + y[sb] + y[sc];
  ys /= 3;
  double xb = x[ba] + x[bb] + x[bc];
  xb /= 3;
  double yb = y[ba] + y[bb] + y[bc];
  yb /= 3;
  return sqrt((xs - xb) * (xs - xb) + (ys - yb) * (ys - yb)) / u / 2;
}

int main()
{
  scanf("%d", &t);
  while (t--) {
    scanf("%d %d", &n, &u);
    for (int i = 0; i < n; ++i)
      scanf("%d %d", &x[i], &y[i]);
    printf("%.2lf\n", solve());
  }
  return 0;
}

