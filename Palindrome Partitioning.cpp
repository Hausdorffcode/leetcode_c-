//https://leetcode.com/problems/palindrome-partitioning/#/description

//dfs
//time O(2^n), space O(n)
class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ret;
        vector<string> path;
        dfs(ret, path, s, 0, 1);
        return ret;
    }
    
private:
    void dfs(vector<vector<string>> &ret, vector<string> &path, string &s, int prev, int cur) {
        if (cur == s.size()) {
            if (isP(s, prev, cur-1)) {
                path.push_back(s.substr(prev, cur-prev));
                ret.push_back(path);
                path.pop_back();   //重要！
            }
            return;
        }
        
        if (isP(s, prev, cur-1)) {
            path.push_back(s.substr(prev, cur-prev));
            dfs(ret, path, s, cur, cur+1);
            path.pop_back();
        }
        dfs(ret, path, s, prev, cur+1);
    }
    
    bool isP(string s, int start, int end) {
        while (start < end) {
            if (s[start] != s[end]) {
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
};