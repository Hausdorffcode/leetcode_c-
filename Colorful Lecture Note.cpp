//http://hihocoder.com/problemset/problem/1103?sid=1196530

//栈，字符串，看清题意
//本题需要注意两点：一是字符串可能包含空格，二是可能存在字符没有被任何标签包裹住。
#include<bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
const double eps = 1E-6;
const int MAXN = 1010;

char text[MAXN];

int main() {
    freopen("test.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //scanf("%s", text);  //不行，文本中有空格
    cin.getline(text, MAXN);
    stack<int> color; //0:red, 1:yellow, 2:blue
    int i = 0;
    int cnt[3];
    memset(cnt, 0, sizeof(cnt)); //0:red, 1:yellow, 2:blue
    while (text[i]) {
        if (text[i] == '<') {
            i++;
            if (text[i] == '/') {
                int x = color.top(); color.pop();  //题目保证了输入正确
            }
            else if (text[i] == 'r') {
                color.push(0);
            }
            else if (text[i] == 'y') {
                color.push(1);
            }
            else {
                color.push(2);
            }
            while (text[i] != '>') i++;
        }
        else if (text[i] == ' ') {  //这种代码看了想笑
        }
        else {
            if (!color.empty()) cnt[color.top()]++;
        }
        i++;
    }
    printf("%d %d %d\n", cnt[0], cnt[1], cnt[2]);
    return 0;
}
