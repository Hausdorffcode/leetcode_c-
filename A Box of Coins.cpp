//http://hihocoder.com/contest/mstest2017april/problem/3

//贪心
#include<bits/stdc++.h>
using namespace std;
const int MAXN = 100010;
const double EPS = 1e-6;

int N;
long long A[MAXN];
long long B[MAXN];

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &N);
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        scanf("%d %d", &A[i], &B[i]);
        cnt += A[i] + B[i];
    }
    long long ret = 0;
    long long per_slot = cnt / (2*N);
    long long topA = 0;
    long long downB = 0;
    for (int i = 0; i < N; i++) {
        A[i] += topA;
        B[i] += downB;
        ret += abs(topA) + abs(downB);
        if (A[i] > per_slot) {
            if (B[i] >= per_slot) {
                topA = A[i] - per_slot;
                downB = B[i] - per_slot;
            }
            else {
                long long movecnt = min(A[i] - per_slot, per_slot - B[i]);
                ret += movecnt;
                topA = A[i] - movecnt - per_slot;
                downB = B[i] + movecnt - per_slot;
            }
        }
        else {
            if (B[i] > per_slot) {
                long long movecnt = min(B[i] - per_slot, per_slot - A[i]);
                ret += movecnt;
                topA = A[i] + movecnt - per_slot;
                downB = B[i] - movecnt - per_slot;
            }
            else {
                topA = A[i] - per_slot;
                downB = B[i] - per_slot;
            }
        }
    }
    printf("%lld\n", ret);
    return 0;
}
