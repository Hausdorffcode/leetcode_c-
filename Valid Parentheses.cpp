//https://leetcode.com/problems/valid-parentheses/#/description

//用map与string形成了一一映射
//time O(n), space O(1)
class Solution {
public:
    bool isValid(string s) {
        stack<char> op;
        const string ss = "{[()]}";
        map<char, int> ms;
        for (int i = 0; i < ss.size(); i++) {
            ms[ss[i]] = i;
        }
        for (int i = 0 ; i < s.size(); i++) {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[')  {
                op.push(s[i]);
            }
            else {
                if (op.empty()) return false;    //注意"]"这种情形
                char oo = op.top(); op.pop();
                if (oo != ss[5-ms[s[i]]]) return false;
            }
        }
        return op.empty(); //注意“["这种情形
    }
};

//两个string配find
class Solution {
public:
    bool isValid(string s) {
        string left = "{[(";
        string right = "}])";
        stack<int> op;
        
        for (int i = 0; i < s.size(); i++) {
            if (left.find(s[i]) != string::npos) {
                op.push(s[i]);
            }
            else {
                if (op.empty() || op.top() != left[right.find(s[i])]) return false;
                op.pop();
            }
        }
        return op.empty();
    }
};