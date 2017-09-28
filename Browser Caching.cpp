//http://hihocoder.com/problemset/problem/1086?sid=1173113

//使用hash（大伪）+双向链表
#include<bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
const double eps = 1E-6;
const int MAXN = 10010;

struct URL{
    string url;
    URL* next;
    URL* prev;
    URL(string url) : url(url), next(this), prev(this) {}
};

URL* dummy = new URL("");

void insertToTail(URL* temp) {
    dummy->prev->next = temp;
    temp->prev = dummy->prev;
    dummy->prev = temp;
    temp->next = dummy;
}

void deleteFromCache(URL* temp) {
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
}

void deleteHead() {
    deleteFromCache(dummy->next);
}

int main()
{
    freopen("test.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int N, M;
    cin >> N >> M;
    map<string, URL*> cache;

    while (N--) {
        string s;
        cin >> s;
        map<string, URL*> :: iterator itor = cache.find(s);
        if (itor == cache.end()) {
            URL* newURL = new URL(s);
            if (cache.size() >= M) {
                cache.erase(cache.find(dummy->next->url));
                deleteHead();
            }
            insertToTail(newURL);
            cache[s] = newURL;
            cout << "Internet" << endl;
        }
        else {
            URL* temp = cache[s];
            deleteFromCache(temp);
            insertToTail(temp);
            cout << "Cache" << endl;
        }
    }

    return 0;
}

//仅使用map，十分巧妙
#include<bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
const double eps = 1E-6;
const int MAXN = 20010;

int N, M;
map<string, int> timeStamp;
int cnt = 0;
string urls[MAXN];

int main() {
    //freopen("test.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> N >> M;
    string url;
    int s = 1;
    for (int i = 1; i <= N; i++) {
        cin >> url;
        urls[i] = url;
        int index = 0;
        if (timeStamp.count(url) > 0) {
            index = timeStamp[url];
        }
        timeStamp[url] = i;
        if (index >= s) {
            printf("Cache\n");
        }
        else {
            printf("Internet\n");
            cnt++;
            if (cnt > M) {
                s++;
                //cnt--;
            }
        }
        while (timeStamp[urls[s]] != s) s++;   //这句要放在else外面，s位置代表了最早的访问记录，如果某次又访问了，则这条s将变成最新的记录，所以也要更新s
    }
    return 0;
}

