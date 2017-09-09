//http://hihocoder.com/contest/mstest2016april1/problem/2

//把ip转化为整数比较，可是超时了，另外取值的时候也非常耗时啊。。
#include<bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
const double eps = 1E-6;
const int MAXN = 100010;

int N, M;
int ip[MAXN];
int mask[MAXN];
bool rule[MAXN];

int readIP(string& s, int m) {
    int ret = 0;
    //if (s.size() == 0 || m < 0 || m > 32) return -1;
    int p = 0;
    while (!isdigit(s[p])) {
        p++;
    }
    int num = 0;
    while (p < s.size()) {
        if (isdigit(s[p])) {
            num = num * 10 + s[p]-'0';
        }
        else {
            //printf("num=%d\n", num);
            ret = ret << 8;
            ret += num;
            //printf("ret= %d\n", ret);
            if (s[p] == '/') break;
            else num = 0;
        }
        p++;
    }
    if (p == s.size()) {
        ret = ret << 8;
        ret += num;
        //printf("num=%d\n", num);
    }
    if (m > 0 && m < 32)  {
        ret = ret >> (32-m);
        ret = ret << (32-m);
    }
    return ret;
}

int readMask(string& s) {
    //if (s.size() == 0) return -1;
    int ret = 32;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '/') {
            i++;
            ret = 0;
            while (i < s.size()) {
                ret = ret*10 + s[i]-'0';
                i++;
            }
        }
    }
    return ret;
}

int main()
{
    freopen("test.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> N >> M;
    getchar();
    for (int i = 0; i < N; i++) {
        string line;
        getline(cin, line);

        if (line[0] == 'a') { rule[i] = true;}
        else { rule[i] = false;}
        mask[i] = readMask(line);
        //printf("mask=%d\n", mask[i]);
        ip[i] = readIP(line, mask[i]);
        //printf("ip=%d\n", ip[i]);
    }

    for (int i = 0; i < M; i++) {
        string line;
        getline(cin, line);
        bool ok = true;
        int val = readIP(line, 32);
        //printf("val= %d\n", val);
        for (int j = 0; j < N; j++) {
            if (mask[j] == 0) {
                ok = rule[j];
                break;
            }
            else if (mask[j] == 32) {
                if (val == ip[j]) {
                    ok = rule[j];
                    break;
                }
            }
            else {
                int temp = val;
                temp = val >> (32-mask[j]);
                temp = temp << (32-mask[j]);
                if (temp == ip[j]) {
                    ok = rule[j];
                    break;
                }
            }
        }
        if (ok) printf("YES\n");
        else printf("NO\n");
    }

    return 0;
}

//可以学习以下struct和map的用法
#include<bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
const double eps = 1E-6;
const int MAXN = 100010;

struct node {
    int index;
    bool rule;
    node(){}    //虽然不知道为什么要这句，但就是要
    node(int index, bool rule) : index(index), rule(rule) {}
};

struct pnode {
    int ip;
    int mask;
    pnode(){}    //虽然不知道为什么要这句，但就是要
    pnode(int ip, int mask) : ip(ip), mask(mask) {}
    bool operator < (const pnode& b)const {
        if (ip != b.ip) return ip < b.ip;
        return mask < b.mask;
    }
};

int N, M;
map<pnode, node> middleware;
char order[35];

int main()
{
    freopen("test.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d %d", &N, &M);
    getchar();
    int x1, x2, x3, x4;
    int mask;
    for (int i = 0; i < N; i++) {
        scanf("%s", order);
        bool ok = false;
        if (order[0] == 'a') { ok = true;}
        scanf("%d.%d.%d.%d", &x1, &x2, &x3, &x4);
        char temp = getchar();
        if (temp == '/') {
            scanf("%d", &mask);
        }
        else {
            mask = 32;
        }
        int ip = (x1<<24) + (x2<<16) + (x3<<8) + x4;
        ip = ip >> (32-mask);
        ip = ip << (32-mask);
        if (mask == 0) ip = 0;
        node n = node(i, ok);
        pnode p = pnode(ip, mask);
		if (middleware.find(p) == middleware.end()) {     //要加这一句啊，各种规则之间会有重复。。。汗，WA了好久
			middleware[p] = n;
		}
    }

    for (int i = 0; i < M; i++) {
        scanf("%d.%d.%d.%d", &x1, &x2, &x3, &x4);
        int ip = (x1<<24) + (x2<<16) + (x3<<8) + x4;
        bool ok = true;
        int index = N;
        for (int k = 0; k <= 32; k++) {
            int val = ip >> k;
            val = val << k;
            if (k == 32) {
                val = 0;
            }
            pnode p = pnode(val, 32-k);
            map<pnode ,node >::iterator itor;
            itor = middleware.find(p);
            if (itor != middleware.end() && middleware[p].index < index) {
                ok = middleware[p].rule;
                index = middleware[p].index;
            }
        }
        if (ok) printf("YES\n");
        else printf("NO\n");
    }

    return 0;
}


//01字典树，建树的时候要记录输入的顺序且对于IP相同但前缀不同的CIDR只取最早出现的，每次查询沿着字典树一直走，
//取路径上最早输入的匹配状态为答案，还要记录是否有前缀，插入时据此来决定插入的位数，比如0.0.0.0和0.0.0.0/0是不同的
#include <cstdio>
#include <cstring>
#define ll long long
int const MAX = 4e6;
char ch, tp[10];
int n, m, num, a1, a2, a3, a4;
bool flag;

struct Trie  
{  
    int root, tot, next[MAX][2], end[MAX], id[MAX];  
    inline int Newnode()  
    {  
        memset(next[tot], -1, sizeof(next[tot]));  
        return tot ++;  
    }  
  
    inline void Init()  
    {  
    	memset(id, 0, sizeof(id));
        tot = 0;  
        root = Newnode();  
    }  
  
    inline void Insert(ll x, int no)  
    {  
        int p = root, tmp = flag ? 31 - num : -1;  
        for(int i = 31; i > tmp; i--)  
        {  
            int idx = ((1ll << i) & x) ? 1 : 0;  
            if(next[p][idx] == -1)  
                next[p][idx] = Newnode();  
            p = next[p][idx];  
        }  
        if(!id[p]) 
        {
        	id[p] = no;
        	end[p] = (strcmp(tp, "allow") == 0);
        }
    }  
  
    inline int Search(ll x)  
    {  	
    	bool ans = true;
    	int p = root, curid = 1000000;
    	if(id[p])
    	{
    		curid = id[p];
    		ans = end[p];
    	}
    	for(int i = 31; i >= 0; i--)
    	{
    		int idx = ((1ll << i) & x) ? 1 : 0;
    		if(next[p][idx] == -1)
    			return ans;
    		p = next[p][idx];
    		if(id[p] && id[p] < curid)
    		{
    			curid = id[p];
    			ans = end[p];	
    		}
    	}	
    	return ans;
    }  
}tr;

int main()
{
	tr.Init();
	ll b;
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; i++)
	{
		scanf("%s %d.%d.%d.%d", tp, &a1, &a2, &a3, &a4);
		scanf("%c", &ch);
		flag = (ch == '/');
		if(flag)
			scanf("%d", &num);
		b = (a1 << 24) + (a2 << 16) + (a3 << 8) + a4;
		tr.Insert(b, i + 1);
	}
	while(m --)
	{
		scanf("%d.%d.%d.%d", &a1, &a2, &a3, &a4);
		b = (a1 << 24) + (a2 << 16) + (a3 << 8) + a4;
		printf("%s\n", tr.Search(b) ? "YES" : "NO");
	}
}