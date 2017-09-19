//http://hihocoder.com/contest/mstest2016oct/problem/3

//模拟题，优先队列
#include<bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
const double eps = 1E-6;
const int MAXN = 10010;

int N, M, K;
int S[MAXN], T[MAXN], P[MAXN];
int Q[MAXN][MAXN];
int W[MAXN][MAXN];

int officeEndTime[MAXN];   //office开始空闲时间

struct studentState{
    int id;            //代表学生
    int studentNum;    //学号
    int arriveTime;    //到达office时间
    int officeIndex;        //代表下一个将要去的office的下标

    bool operator < (const studentState& s) const {
        if (arriveTime == s.arriveTime) return studentNum > s.studentNum;
        return arriveTime > s.arriveTime;
    }
};

int main()
{
    freopen("test.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    priority_queue<studentState> pq;
    memset(officeEndTime, 0, sizeof(officeEndTime));
    scanf("%d %d %d", &N, &M, &K);
    vector<int> ret(N, 0);
    for (int i = 0; i < N; i++) {
        scanf("%d %d %d", &S[i], &T[i], &P[i]);
        //printf("%d %d %d\n", S[i], T[i], P[i]);
        for (int j = 0; j < P[i]; j++) {
            scanf("%d %d", &Q[i][j], &W[i][j]);
        }
        studentState ss;
        ss.id = i;
        ss.studentNum = S[i];
        ss.arriveTime = T[i]+K;
        ss.officeIndex = 0;       //这里由于学生至少去一个office
        pq.push(ss);
    }
    while (!pq.empty()) {
        studentState ss = pq.top(); pq.pop();
        int id = ss.id;
        int office = Q[id][ss.officeIndex];
        int spendTime = W[id][ss.officeIndex];
        if (ss.arriveTime >= officeEndTime[office]) {
            officeEndTime[office] = ss.arriveTime + spendTime;
            ss.arriveTime += spendTime + K;
        }
        else {
            officeEndTime[office] += spendTime;
            ss.arriveTime = officeEndTime[office] + K;
        }
        ss.officeIndex++;
        if (ss.officeIndex >= P[id]) {
            ret[id] = ss.arriveTime-K;
        }
        else {
            pq.push(ss);
        }
    }
    for (int i = 0; i < N; i++) {
        printf("%d\n", ret[i]);
    }
    return 0;
}

