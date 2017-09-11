//http://hihocoder.com/contest/mstest2016april1/problem/3

//dp O(NM)
//代码过于丑陋
//解析https://hihocoder.com/discuss/question/4529
//但隐隐觉得下边的状态定义才靠谱
#include<bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
const double eps = 1E-6;
const int MAXN = 110;

int N, M;
char maze[MAXN][MAXN];
int f[MAXN][MAXN][2];  //0 -> 右, 1 -> 下

int main()
{
    freopen("test.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d %d", &N, &M);
    memset(f, 0x3f, sizeof(f));
    for(int i = 1;  i <= N; i++) {
        scanf("%s", maze[i]+1);    //注意细节啊
    }
    for (int j  = 0; j <= M+1; j++) {
        maze[0][j] = 'b';
        maze[N+1][j] = 'b';
    }
    for (int i = 0; i <= N+1; i++) {
        maze[i][0] = 'b';
        maze[i][M+1] = 'b';
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            if (i == 1 && j == 1) {
                if (maze[i][j] == 'b') f[i][j][0] = 1;
                else f[i][j][0] = 0;
            }
            else if (i == 1) {
                int val[2];
                //right
                val[0] = f[i][j-1][0];
                if (maze[i][j] == 'b') val[0]++;

                val[1] = f[i][j-1][1];
                if (maze[i][j] == 'b') val[1]++;
                if (maze[i+1][j-1] != 'b') val[1]++;

                for (int k = 0; k < 2; k++) {
                    f[i][j][0] = min(f[i][j][0], val[k]);
                }

                //down
                val[0] = f[i][j-1][0];
                if (maze[i][j] == 'b') val[0]++;
                if (maze[i][j+1] != 'b') val[0]++;

                val[1] = f[i][j-1][1];
                if (maze[i][j] == 'b') val[1]++;
                if (maze[i+1][j-1] != 'b') val[1]++;
                if (maze[i][j+1] != 'b') val[1]++;

                for (int k = 0; k < 2; k++) {
                    f[i][j][1] = min(f[i][j][1], val[k]);
                }
            }
            else if (j == 1) {
                int val[2];
                //right
                val[0] = f[i-1][j][0];
                if (maze[i-1][j+1] != 'b') val[0]++;
                if (maze[i+1][j] != 'b') val[0]++;
                if (maze[i][j] == 'b') val[0]++;

                val[1] = f[i-1][j][1];
                if (maze[i][j] == 'b') val[1]++;
                if (maze[i+1][j] != 'b') val[1]++;

                for (int k = 0; k < 2; k++) {
                    f[i][j][0] = min(f[i][j][0], val[k]);
                }

                //down
                val[0] = f[i-1][j][0];
                if (maze[i-1][j+1] != 'b') val[0]++;
                if (maze[i][j] == 'b') val[0]++;

                val[1] = f[i-1][j][1];
                if (maze[i][j] == 'b') val[1]++;

                for (int k = 0; k < 2; k++) {
                    f[i][j][1] = min(f[i][j][1], val[k]);
                }
            }
            else {
                int val[4];
                //right
                val[0] = f[i-1][j][0];
                if (maze[i-1][j+1] != 'b') val[0]++;
                if (maze[i+1][j] != 'b') val[0]++;
                if (maze[i][j] == 'b') val[0]++;

                val[1] = f[i-1][j][1];
                if (maze[i][j] == 'b') val[1]++;
                if (maze[i+1][j] != 'b') val[1]++;

                val[2] = f[i][j-1][0];
                if (maze[i][j] == 'b') val[2]++;

                val[3] = f[i][j-1][1];
                if (maze[i][j] == 'b') val[3]++;
                if (maze[i+1][j-1] != 'b') val[3]++;

                for (int k = 0; k < 4; k++) {
                    f[i][j][0] = min(f[i][j][0], val[k]);
                }

                //down
                val[0] = f[i-1][j][0];
                if (maze[i-1][j+1] != 'b') val[0]++;
                if (maze[i][j] == 'b') val[0]++;

                val[1] = f[i-1][j][1];
                if (maze[i][j] == 'b') val[1]++;

                val[2] = f[i][j-1][0];
                if (maze[i][j] == 'b') val[2]++;
                if (maze[i][j+1] != 'b') val[2]++;

                val[3] = f[i][j-1][1];
                if (maze[i][j] == 'b') val[3]++;
                if (maze[i+1][j-1] != 'b') val[3]++;
                if (maze[i][j+1] != 'b') val[3]++;

                for (int k = 0; k < 4; k++) {
                    f[i][j][1] = min(f[i][j][1], val[k]);
                }
            }
        }
    }
    printf("%d\n", min(f[N][M][0], f[N][M][1]));
    return 0;
}


//简介，表示状态含义略微有些不同
#include<bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
const double eps = 1E-6;
const int MAXN = 110;

int n, m;
int dp[MAXN][MAXN][2]; //0 -> 右, 1 -> 下
char s[MAXN][MAXN];

int main()
{
    freopen("test.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++)
        scanf("%s", s[i] + 1);
    memset(dp, 0x3f, sizeof(dp));
    dp[1][1][0] = 0;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            if(i == 1 && j == 1)
                continue;

            dp[i][j][1] = dp[i - 1][j][1];
            if(s[i - 1][j + 1] == 'b' || j == m)
                dp[i][j][1] = min(dp[i][j][1], dp[i - 1][j][0]);
            else
                dp[i][j][1] = min(dp[i][j][1], dp[i - 1][j][0] + 1);

            dp[i][j][0] = dp[i][j - 1][0];
            if(s[i + 1][j - 1] == 'b' || i == n)
                dp[i][j][0] = min(dp[i][j][0], dp[i][j - 1][1]);
            else
                dp[i][j][0] = min(dp[i][j][0], dp[i][j - 1][1] + 1);

            if(s[i][j] == 'b')
            {
                dp[i][j][0] ++;
                dp[i][j][1] ++;
            }
        }
    }
    printf("%d\n", min(dp[n][m][0], dp[n][m][1]));
    return 0;
}



