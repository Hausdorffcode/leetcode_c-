
//神一样的代码
#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
struct node
{
    int next[26];     //结点本身最多有26个儿子，而每条边代表的字符就体现在数组下标中，相当于字符在边上，不在结点上
    int cnt;
    void init()
    {
        cnt=0;
        memset(next,-1,sizeof(next));
    }
}T[1000000];       //预先就分配了所有可能用到的结点最大数，可以说是结点池
int le;            //用于指向一个新的， 未被分配的结点
void insert(char *s)
{
    int i=0,p=0;
    while(s[i])
    {
        int x=s[i]-'a';
        if(T[p].next[x]==-1)
        {
            T[le].init();     //分配一个新结点，le相当于指针
            T[p].next[x]=le++;
        }
        p=T[p].next[x];
        T[p].cnt++;       //计数
        i++;
    }
}
void query(char *s)
{
    int i=0,p=0;
    while(s[i])
    {
        int x=s[i]-'a';
        if(T[p].next[x]==-1)
        {
            puts("0");
            return ;
        }
        p=T[p].next[x];
        i++;
    }
    printf("%d\n",T[p].cnt);
}
int main()
{
    int n,m;
    char str[20];
    while(~scanf("%d",&n))
    {
        le=1;
        T[0].init();
        while(n--)
        {
        scanf("%s",str);
        insert(str);
        }
        scanf("%d",&m);
        while(m--)
        {
        scanf("%s",str);
        query(str);
        }
    }
}

//正常人的代码
#include<bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
const double eps = 1E-6;
const int MAXN = 10;

struct Trie    //树结点，有计数，有表示字符，有指针
{
	char c;
	int cnt;
	struct Trie* next[26];
};

int main()
{
    freopen("test.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
	Trie* root = new Trie();
	for (unsigned i(0); i < 26; ++i)
		root->next[i] = NULL;
	int n, m;
	string s;
	cin >> n;
	while (n--)
	{
		cin >> s;
		Trie* p = root;
		for (unsigned i(0); i < s.size(); ++i)
		{
			unsigned j = s[i] - 'a';
			if (p->next[j])
			{
				++p->next[j]->cnt;
			}
			else
			{
				Trie* q = new Trie;
				q->c = s[i];
				q->cnt = 1;
				for (unsigned k(0); k < 26; ++k)
					q->next[k] = NULL;
				p->next[j] = q;
			}
			p = p->next[j];
		}
	}
	cin >> m;
	while (m--)
	{
		cin >> s;
		bool flag = false;
		Trie* p = root;
		for (unsigned i(0); i < s.size(); ++i)
		{
			unsigned j = s[i] - 'a';
			if (!p->next[j])
			{
				flag = true;
				break;
			}
			p = p->next[j];
		}
		if (flag) cout << '0' << endl;
		else cout << p->cnt << endl;
	}
	return 0;
}

