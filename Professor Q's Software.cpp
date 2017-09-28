//http://hihocoder.com/problemset/problem/1136?sid=1175985

//构建一幅有向无环图，暴力dfs，可惜过不了。。。。
#include<bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
const double eps = 1E-6;
const int MAXN = 100010;

const int magicNum = 142857;

struct module {
    int activeSign;
    vector<int> sendSign;
};

int n, m;
module modules[MAXN];
vector<int> signCanActiveModules[MAXN];
int cntModules[MAXN];

void init() {
    for (int i = 0; i < MAXN; i++) {
        signCanActiveModules[i].clear();
    }
    memset(cntModules, 0, sizeof(cntModules));
}

void dfs(int index) {
    cntModules[index]++;
    cntModules[index] %= magicNum;
    for (int i = 0; i < modules[index].sendSign.size(); i++) {
        int sign = modules[index].sendSign[i];
        for (int j = 0; j < signCanActiveModules[sign].size(); j++) {
            int aimModule = signCanActiveModules[sign][j];
            if (aimModule != 0) {
                dfs(aimModule);
            }
        }
    }
}

int main() {
    //freopen("test.txt", "r", stdin);
    int T;
    scanf("%d", &T);
    while (T--) {
        init();
        scanf("%d %d", &n, &m);
        modules[0].activeSign = -1;
        int msign;
        for (int i = 0; i < m; i++) {
            scanf("%d", &msign);
            modules[0].sendSign.push_back(msign);
        }
        for (int i = 1; i <= n; i++) {
            int k, e;
            scanf("%d %d", &(modules[i].activeSign), &k);
            signCanActiveModules[modules[i].activeSign].push_back(i);
            for (int j = 0; j < k; j++) {
                scanf("%d", &e);
                modules[i].sendSign.push_back(e);
            }
        }
        dfs(0);
        for (int i = 1;  i <= n; i++) {
            if (i == n) printf("%d\n", cntModules[i]);
            else printf("%d ", cntModules[i]);
        }
    }
    return 0;
}

//又过不了。。
#include<bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
const double eps = 1E-6;
const int MAXN = 100010;

const int magic = 142857;

struct module{
    int activeSign;
    vector<int> sendSign;
};

int N, M;
module modules[MAXN];
vector<int> activeSignToModules[MAXN];
int callcnt[MAXN];

int head[MAXN];
int p[MAXN];
int nextModule[MAXN];
int edgecnt;
int deg[MAXN];

void addEdge(int u, int v) {
    ++edgecnt;
    p[edgecnt] = v;
    nextModule[edgecnt] = head[u];
    head[u] = edgecnt;
}

void init() {
    for (int i = 0; i < MAXN; i++) {
        activeSignToModules[i].clear();
    }
    memset(callcnt, 0, sizeof(callcnt));
    memset(head, 0, sizeof(head));
    memset(p, 0, sizeof(p));
    memset(nextModule, 0, sizeof(nextModule));
    edgecnt = 0;
    memset(deg, 0, sizeof(deg));
}

void dfs(int x) {
    callcnt[x]++;
    callcnt[x] %= magic;
    for (int i = head[x]; i; i = nextModule[i]) {
        int v = p[i];
        dfs(v);
    }
}

void toposort() {
    queue<int> q;
    q.push(0);
    callcnt[0] = 1;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int i = head[u]; i; i = nextModule[i]) {
            int v = p[i];
            deg[v] -= 1;
            callcnt[v] += callcnt[u];
            callcnt[v] %= magic;
            if (deg[v] == 0) q.push(v);
        }
    }
}

int main() {
    freopen("test.txt", "r", stdin);
    int T;
    scanf("%d", &T);
    while (T--) {
        init();
        scanf("%d %d", &N, &M);
        modules[0].activeSign = -1;
        int initialSign;
        modules[0].sendSign.clear();
        for (int i = 0; i < M; i++) {
            scanf("%d", &initialSign);
            modules[0].sendSign.push_back(initialSign);
        }
        for (int i = 1; i <= N; i++) {
            int s, k, e;
            scanf("%d %d", &s, &k);
            modules[i].activeSign = s;
            modules[i].sendSign.clear();
            activeSignToModules[s].push_back(i);
            for (int j = 0; j < k; j++) {
                scanf("%d", &e);
                modules[i].sendSign.push_back(e);
            }
        }

        //build picture
        for (int i = 0; i <= N; i++) {
            for (int j = 0; j < modules[i].sendSign.size(); j++) {
                int sign = modules[i].sendSign[j];
                for (int k = 0; k < activeSignToModules[sign].size(); k++) {
                    int m = activeSignToModules[sign][k];
                    addEdge(i, m);
                    deg[m]++;
                }
            }
        }

        toposort();
        //dfs(0);

        for (int i = 1; i <= N; i++) {
            if (i == N) printf("%d\n", callcnt[i]);
            else printf("%d ", callcnt[i]);
        }
    }
    return 0;
}

//终于ac了。。。
#include<bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
const double eps = 1E-6;
const int MAXN = 100010;

const int magic = 142857;

struct module{
    int activeSign;
    int sendSignCnt;
    int sendSign[3];
};

int N, M;
module modules[MAXN];
int initSign[MAXN];
vector<int> activeSignToModules[MAXN];
int callcnt[MAXN];

int head[MAXN];
int p[MAXN];
int nextModule[MAXN];
int edgecnt;
int deg[MAXN];

void addEdge(int u, int v) {
    ++edgecnt;
    p[edgecnt] = v;
    nextModule[edgecnt] = head[u];
    head[u] = edgecnt;
}

void init() {
    for (int i = 0; i < MAXN; i++) {
        activeSignToModules[i].clear();
    }
    memset(callcnt, 0, sizeof(callcnt));
    memset(head, 0, sizeof(head));
    memset(p, 0, sizeof(p));
    memset(nextModule, 0, sizeof(nextModule));
    edgecnt = 0;
    memset(deg, 0, sizeof(deg));
}

void dfs(int x) {
    callcnt[x]++;
    callcnt[x] %= magic;
    for (int i = head[x]; i; i = nextModule[i]) {
        int v = p[i];
        dfs(v);
    }
}

void toposort() {
    queue<int> q;
    for (int i = 0; i < M; i++) {
        int sign = initSign[i];
        for (int j = 0; j < activeSignToModules[sign].size(); j++) {
            //q.push(activeSignToModules[sign][j]);
            callcnt[activeSignToModules[sign][j]]++;
        }
    }
    for (int i = 1; i <= N; i++) {
        if (deg[i] == 0) {
            q.push(i);
        }
    }
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int i = head[u]; i; i = nextModule[i]) {
            int v = p[i];
            deg[v] -= 1;
            callcnt[v] += callcnt[u];
            callcnt[v] %= magic;
            if (deg[v] == 0) q.push(v);
        }
    }
}

int main() {
    freopen("test.txt", "r", stdin);
    int T;
    scanf("%d", &T);
    while (T--) {
        init();
        scanf("%d %d", &N, &M);
        for (int i = 0; i < M; i++) {
            scanf("%d", &initSign[i]);
        }
        for (int i = 1; i <= N; i++) {
            int s, k, e;
            scanf("%d %d", &s, &k);
            modules[i].activeSign = s;
            modules[i].sendSignCnt = k;
            activeSignToModules[s].push_back(i);
            for (int j = 0; j < k; j++) {
                scanf("%d", &e);
                modules[i].sendSign[j] = e;
            }
        }

        //build picture
        for (int i = 1; i <= N; i++) {
            for (int j = 0; j < modules[i].sendSignCnt; j++) {
                int sign = modules[i].sendSign[j];
                for (int k = 0; k < activeSignToModules[sign].size(); k++) {
                    int m = activeSignToModules[sign][k];
                    addEdge(i, m);
                    deg[m]++;
                }
            }
        }

        toposort();             //两种方式：拓扑排序，dfs
//        for (int i = 0; i < M; i++) {
//            int sign = initSign[i];
//            for (int j = 0; j < activeSignToModules[sign].size(); j++) {
//                dfs(activeSignToModules[sign][j]);
//            }
//        }

        for (int i = 1; i <= N; i++) {
            if (i == N) printf("%d\n", callcnt[i]);
            else printf("%d ", callcnt[i]);
        }
    }
    return 0;
}

//大神的代码
#include<stdio.h>
#include<stdlib.h>

/*
 * Record signal message in linktable. This is the defination
 * of linktable node. The input signal is the index of array: signals.
 * Parameters:
 *		@value: The value of this signal.
 *		@next: The pointer of the output of this signal.
 * 		@count: The number of calling of this signal.
 */
typedef struct node1 {
	int value;
	struct node1* next;
	int count;
} signal;

// The signals list.
signal signals[100005];

// The module list, the element is the input signal of each module.
int modules[100005];

// The number of modules.
int N;

/*
 * This fuction deals with one test case.
 * Parameters:
 *		None.
 * Return:
 *		None.
 */
void function(void);

/*
 * This function initial the situation for one test case.
 * Parameters:
 *		None.
 * Return:
 * 		None.
 */
void init(void);

/*
 * This function adds one output signal of a signal.
 * Parameters:
 *		@input: The input signal.
 *		@output: The output signal number to add.
 */
void add_output_signal(int input, int output);

/*
 * This function calculates the number of each module calling.
 * Parameters:
 *		@input: The input signal.
 * Return:
 * 		None.
 */
void calculate(int input);

/*
 * This function print the result of one test case.
 * Parameters:
 *		None.
 * Return:
 *		None.
 */
void print_result(void);

/*
 * The main program.
 */
int main(void) {
    freopen("test.txt", "r", stdin);
	int T;
	scanf("%d", &T);

	for(int i = 0; i < T; i++) {
		function();
	}

	return 0;
}

/*
 * This fuction deals with one test case.
 * Parameters:
 *		None.
 * Return:
 *		None.
 */
void function(void) {
	init();
	int M;
	scanf("%d %d", &N, &M);

	int s;
	for(int i = 0; i < M; i++) {
		scanf("%d", &s);
		add_output_signal(100001, s);
	}

	int S, K, E;
	for(int i = 0; i < N; i++) {
		scanf("%d %d", &S, &K);
		modules[i] = S;
		for(int j = 0; j < K; j++) {
			scanf("%d", &E);
			add_output_signal(S, E);
		}
	}

	signal* p = signals[100001].next;
	while(p != NULL) {
		calculate(p->value);
		p = p->next;
	}

	print_result();
}

/*
 * This function initial the situation for one test case.
 * Parameters:
 *		None.
 * Return:
 * 		None.
 */
void init(void) {
	for(int i = 0; i < 100005; i++) {
		signals[i].value = i;
		signals[i].count = 0;
		signals[i].next = NULL;
		modules[i] = 0;
	}

	N = 0;
}

/*
 * This function adds one output signal of a signal.
 * Parameters:
 *		@input: The input signal.
 *		@output: The output signal number to add.
 */
void add_output_signal(int input, int output) {
	signal* s = (signal*) malloc(sizeof(signal));
	s->value = output;

	s->next = signals[input].next;
	signals[input].next = s;
}

/*
 * This function calculates the number of each module calling.
 * Parameters:
 *		@input: The input signal.
 * Return:
 * 		None.
 */
void calculate(int input) {
	signals[input].count++;
	if(signals[input].count == 142859) {
		signals[input].count = 0;
	}
	signal* p = signals[input].next;
	while(p != NULL) {
		calculate(p->value);
		p = p->next;
	}
}

/*
 * This function print the result of one test case.
 * Parameters:
 *		None.
 * Return:
 *		None.
 */
void print_result(void) {
	for(int i = 0; i < N; i++) {
		printf("%d ", signals[modules[i]].count);
	}
	printf("\n");
}


//又一个大神的代码
#include<cstdio>
#include<cstring>
using namespace std;

const int maxn = 1e5+5;
struct SOFTWARE
{
	int start;  //module的进入sign
	int num;    //module发出的sign的个数
	int E[5];   //module发出的sign
}sft[maxn];

struct VERTEX
{
	int startE;
	int first;
}ver[maxn];

struct Node
{
	int id;
	int next;
}list[maxn];

int n,m；
int sign[maxn];  //初始的m个sign
int cnt,vis[maxn];

//e是idth模块的进入sign
void add(int e,int id)
{
	ver[e].startE = e;
	list[cnt].id = id;
	if(ver[e].first == -1) ver[e].first = cnt++;
	else
	{
		list[cnt].next = ver[e].first;
		ver[e].first = cnt++;
	}
}

void init()
{
	memset(vis,0,sizeof(vis));
	memset(list,-1,sizeof(list));
	memset(ver,-1,sizeof(ver));
	cnt = 0;
}

void dfs(int cur,int e)
{
	if(ver[e].first == -1) return;
	for(int i = ver[e].first; i != -1; i = list[i].next)
	{
		int k = list[i].id;
		vis[k]++;
		for(int j = 1; j <= sft[k].num; j++)
			dfs(k,sft[k].E[j]);
	}
}

int main()
{
    freopen("test.txt", "r", stdin);
	int t;
	scanf("%d",&t);
	while(t--)
	{
		init();
		scanf("%d%d",&n,&m);
		for(int i = 1; i <= m; i++)
			scanf("%d",&sign[i]);
		for(int i = 1; i <= n; i++)
		{
			scanf("%d%d",&sft[i].start,&sft[i].num);
			add(sft[i].start,i);
			for(int j = 1; j <= sft[i].num; j++)
				scanf("%d",&sft[i].E[j]);
		}
		for(int i = 1; i <= m; i++)
			dfs(0,sign[i]);
		for(int i = 1; i <= n; i++)
			printf("%d ",vis[i]);
		printf("\n");
	}
	return 0;
}


