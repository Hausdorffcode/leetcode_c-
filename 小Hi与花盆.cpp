//http://hihocoder.com/problemset/problem/1572?sid=1169647

//set的使用，set是有序集 upper_bound(x) 返回大于x的元素指针， lower_bound返回大于等于
//每插入一个元素，找到边上相邻的两个元素计算
#include<bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
const int eps = 1E-6;
const int MAXN = 100010;

int main()
{
    freopen("test.txt", "r", stdin);
    int N, K;
    set<int> s;
    scanf("%d %d", &N, &K);
    int ret = -1;
    s.insert(0);
    s.insert(N+1);
    for (int i = 1; i <= N; i++) {
        int y;
        scanf("%d", &y);
        set<int>::iterator it = s.upper_bound(y);
		//set<int>::iterator it = upper_bound(s.begin(), s.end(),y);
		//这句不可以，超时了， 容器成员函数优先于同名算法，成员函数速度快
        int z = *it;
        int x = *(--it);
        if (z-y-1 == K || y-x-1== K) {
            ret = i;
            break;
        }
        s.insert(y);
    }
    printf("%d\n", ret);
    return 0;
}

//可以使用并查集做，将0作为集合，倒过来看是0合并的过程，正难则反
#include<bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
const int eps = 1E-6;
const int MAXN = 100010;

int a[MAXN];

int id[MAXN];    //父链接数组（由触点索引）
int sz[MAXN];    //各结点所对应的分量的大小
int my_find(int s)
{
    return id[s]==s?s:id[s]=my_find(id[s]);
}
int my_union(int x,int y)
{
    int rx=my_find(x);
    int ry=my_find(y);
    id[rx]=ry;
    sz[ry]+=sz[rx];
}

int main()
{
    freopen("test.txt", "r", stdin);
    int n,k;
    scanf("%d%d",&n,&k);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    for(int i=1;i<=n;i++)
        { id[i]=i;sz[i]=0; }

    int ans=-1;
    int cnt = 0;
    for(int i=n-1;i>-1;i--)
    {
        int x=a[i];
        sz[x]=1;
        if(x+1<=n && sz[x+1] > 0)
        {
            if (sz[my_find(x+1)] == k) cnt--; //顺序不能错
            my_union(x,x+1);
        }
        if(x-1>=1 && sz[x-1] > 0)
        {
            if (sz[my_find(x-1)] == k) cnt--; //顺序不能错
            my_union(x,x-1);
        }
        if (sz[my_find(x)] == k) cnt++;
        int rx=my_find(x);
        if (cnt > 0) ans = i;                 //注意这里要取的是“最后”的i（直到最后的合法群被破坏的i）
		
        //下面一段是错误的，eg：1 4 7 6 5 3 2
//        if(sz[rx]==k)
//        {
//            ans=i;
//            printf("ans=%d\n", ans);
//        }
    }
    printf("%d\n",ans);
    return 0;
}



