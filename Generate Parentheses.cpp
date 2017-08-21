//https://leetcode.com/problems/generate-parentheses/description/

//dfs
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ret;
        string path;
        dfs(ret, path, n, n);
        return ret;
    }
    
private:
    void dfs(vector<string>& ret, string& path, int left_left, int right_left) {
        if (left_left == 0 && right_left == 0) {
            ret.push_back(path);
            return;
        }
        if (left_left < right_left) {
            path.push_back(')');
            dfs(ret, path, left_left, right_left-1);
            path.pop_back();
        }
        if (left_left > 0) {
            path.push_back('(');
            dfs(ret, path, left_left-1, right_left);
            path.pop_back();
        }
    }
};