//http://hihocoder.com/contest/mstest2017april/problem/1

//分别统计数行，列，两对角的元素和，再组合计算即可
//这代码惨不忍睹
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cctype>
#include <string>
#include <sstream>
#include <cmath>
#include <queue>
#include <stack>
#include <vector>
#include <set>
#include <map>
using namespace std;

const int INF = 0x3f3f3f3f;
const double eps = 1E-6;
const int MAXN = 100010;

int N;
int R[MAXN];
int C[MAXN];
map<int, int> row;
map<int, int> col;
map<int, int> yx;
map<int, int> xy;

int main()
{
    freopen("test.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &N);
    for (int i = 0; i<N; i++){
        scanf("%d %d", &R[i], &C[i]);
    }

    for (int i = 0; i < N; i++) {
        if (row.count(R[i]) == 0) {
            row[R[i]] = 1;
        }
        else {
            row[R[i]]++;
        }
        if (col.count(C[i]) == 0) {
            col[C[i]] = 1;
        }
        else {
            col[C[i]]++;
        }
        if (xy.count(R[i]+C[i]) == 0) {
            xy[R[i]+C[i]] = 1;
        }
        else {
            xy[R[i]+C[i]]++;
        }
        if (yx.count(R[i]-C[i]) == 0) {
            yx[R[i]-C[i]] = 1;
        }
        else {
            yx[R[i]-C[i]]++;
        }
    }

    int sum = 0;
    for (map<int, int> :: iterator iter = row.begin(); iter != row.end(); iter++) {
        int n = (*iter).second;
        if (n > 1) {
            sum += n*(n-1)/2;
        }
    }
    for (map<int, int> :: iterator iter = col.begin(); iter != col.end(); iter++) {
        int n = (*iter).second;
        if (n > 1) {
            sum += n*(n-1)/2;
        }
    }
    for (map<int, int> :: iterator iter = xy.begin(); iter != xy.end(); iter++) {
        int n = (*iter).second;
        if (n > 1) {
            sum += n*(n-1)/2;
        }
    }
    for (map<int, int> :: iterator iter = yx.begin(); iter != yx.end(); iter++) {
        int n = (*iter).second;
        if (n > 1) {
            sum += n*(n-1)/2;
        }
    }
    printf("%d\n", sum);
    return 0;
}


//网上大神的代码
#include<bits/stdc++.h>  
using namespace std;  
  
map<int ,int > m1;  
map<int ,int > m2;  
map<int ,int > m3;  
map<int ,int > m4;  
typedef long long LL;  
int main()  
{  
    int n;  
    LL ans=0;  
    scanf("%d",&n);  
    for(int i=0; i<n; i++)  
    {  
        int a,b;  
        scanf("%d%d",&a,&b);  
        ans+=m1[a];  
        m1[a]++;  
        ans+=m2[b];  
        m2[b]++;  
        ans+=m3[a+b];  
        m3[a+b]++;  
        ans+=m4[b-a];  
        m4[b-a]++;  
    }  
    cout<<ans<<endl;  
    return 0;  
}  


