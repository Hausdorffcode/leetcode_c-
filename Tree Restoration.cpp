//http://hihocoder.com/contest/mstest2017march/problem/2

//模拟
#include<bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
const double eps = 1E-6;
const int MAXN = 110;

int N, M, K;
int cnt_nodes[MAXN]; //每层的结点个数
int tree[MAXN][MAXN]; //整个树的骨架
int leaves[MAXN];     //叶子结点
bool isLeave[MAXN];    //用来判断是否是叶子结点，索引当成结点序号
int dist[MAXN][MAXN];  //记录结点之间的距离

int parent[MAXN];     //记录结点的父结点，索引当成结点

int main() {
    freopen("test.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    memset(parent, 0, sizeof(parent));
    memset(isLeave, 0, sizeof(isLeave));
    memset(dist, 0, sizeof(dist));   //初始化必须的

    scanf("%d %d %d", &N, &M, &K);
    for (int i =0; i < M; i++) {
        scanf("%d", &cnt_nodes[i]);
    }
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < cnt_nodes[i]; j++) {
            scanf("%d", &tree[i][j]);
        }
    }
    for (int i = 0; i < K; i++) {
        scanf("%d", &leaves[i]);
        isLeave[leaves[i]] = true;    //加入判断是否是叶节点
    }
    for (int i = 0; i < K; i++) {
        for (int j =0; j < K; j++) {
            scanf("%d", &dist[leaves[i]][leaves[j]]);
        }
    }
    for (int i = M-1; i > 0; i--) {
        int upper_node = 0;
        for (int j = 0; j < cnt_nodes[i]; j++) {
            while (isLeave[tree[i-1][upper_node]]) {   //找到第一个不是叶子结点的结点
                upper_node++;
            }
            int son = tree[i][j];
            if (j != 0 && dist[tree[i][j-1]][son] != 2) {  //如果不是一行的第一个结点，后者与前一个结点的距离大于2，找下一个不是叶子结点的结点作为父结点
                do {
                    upper_node++;
                } while (isLeave[tree[i-1][upper_node]]);
            }
            int father = tree[i-1][upper_node];
            parent[son] = father;
            for (int i = 1; i <= N; i++) {
				//找到父结点后，给父结点到其它已知结点之间的距离赋值，这样遍历上一层时，就可以将他们当作叶子结点一样判断距离了
                if (dist[son][i] != 0) {   //这个判断是必须的，一个结点有很多子结点，不同的顺序可能会覆盖了真正的距离值
                    dist[father][i] = dist[son][i]-1;
                    dist[i][father] = dist[i][son]-1;
                }

            }
        }
    }
//    for (int i = 1; i <= N; i++) {
//        for (int j = 1; j < N; j++) {
//            printf("%d ", dist[i][j]);
//        }
//        printf("\n");
//    }

	// 打印父结点
    for (int i = 1; i <= N; i++) {
        printf("%d", parent[i]);
        if (i != N) printf(" ");
    }
    printf("\n");
    return 0;
}

