//http://hihocoder.com/contest/mstest2015oct/problem/2

//用栈模拟，注意细节
#include<bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
const double eps = 1E-6;
const int MAXN = 110;

struct proc {
    int index;
    char functionName[256];
    int timeStamp;
    proc(char* func, int timeStamp, int index) : timeStamp(timeStamp), index(index) {
        strcpy(functionName, func);
    }
    bool operator < (const proc& b) const{
        return index < b.index;
    }
};

stack<proc> st;
char name[256];
char action[50];
int h, m, s;
set<proc> logResult;
int lastTime = -1;

int calTime(int h, int m, int s) {
    return h*3600+m*60+ s;
}

void printTime(proc p) {
    int timec = p.timeStamp;
    int h = timec / 3600;
    timec -= h* 3600;
    int m = timec / 60;
    timec -= m*60;
    int s = timec;
    printf("%s %02d:%02d:%02d\n", p.functionName, h, m, s);
}

int main() {
    freopen("test.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int N;
    scanf("%d", &N);
    bool ok = true;
    for (int i =  0; i < N; i++) {
        getchar();
        scanf("%s %d:%d:%d %s", name, &h, &m, &s, action);
        int t = calTime(h, m, s);
        if (t < lastTime) {ok  = false; break;}    //允许等于。。。。。。
        else {lastTime = t;}
        proc p = proc(name, t, i);
        //也可以写成proc p(name, t, i);
        if (strcmp("START", action) == 0) {
            st.push(p);
        }
        else if (strcmp("END", action) == 0) {
            if (st.empty()) { ok = false; break;}
            else {
                proc startp = st.top(); st.pop();
                if (strcmp(startp.functionName, name) != 0 || startp.timeStamp > p.timeStamp) {  //不允许开始结束同时
                    ok = false;
                    break;
                }
                else {
                    startp.timeStamp = p.timeStamp - startp.timeStamp;
                    logResult.insert(startp);
                }
            }
        }
        else {
            ok = false;
            break;
        }
    }
    if (ok && st.empty()) {  //判断此时栈是否为空
        for (set<proc> :: iterator itor = logResult.begin(); itor != logResult.end(); itor++) {
            printTime((*itor));
        }
    }
    else printf("Incorrect performance log\n");
    return 0;
}
