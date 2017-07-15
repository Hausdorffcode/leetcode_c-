//https://leetcode.com/problems/n-queens/#/description

//回溯
//time O(2^n), space O(n)
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ret;
        int c[n];
        int vis[3][100];
        memset(vis, 0, sizeof(vis));
        dfs(ret, c, 0, n, vis);
        return ret;
    }

private:
    void dfs(vector<vector<string>>& ret, int* c, int cur, int n, int vis[][100]) {
        if (cur == n) {
            vector<string> solution;
            for (int i = 0; i < n; i++) {
                string s;
                for (int j = 0; j < n; j++) {
                    if (c[i] == j) s.push_back('Q');
                    else s.push_back('.');
                }
                solution.push_back(s);
            }
            ret.push_back(solution);
            return;
        }
        for (int i = 0; i < n; i++) {
            if (!vis[0][i] && !vis[1][cur+i] && !vis[2][cur-i+n]) {
                c[cur] = i;
                vis[0][i] = vis[1][cur+i] = vis[2][cur-i+n] = 1;
                dfs(ret, c, cur+1, n, vis);
                vis[0][i] = vis[1][cur+i] = vis[2][cur-i+n] = 0;
            }
        }
    }
};