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

