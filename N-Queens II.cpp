//https://leetcode.com/problems/n-queens-ii/description/

//dfs
//time O(n!), space O(n)
class Solution {
public:
    int totalNQueens(int n) {
        int cnt = 0;
        int temp = 2*n;
        bool vis1[2*n];
        bool vis2[2*n];
        bool vis3[2*n];
        memset(vis1, 0, sizeof(vis1));
        memset(vis2, 0, sizeof(vis2));
        memset(vis3, 0, sizeof(vis3));
        dfs(0, cnt, n, vis1, vis2, vis3);
        return cnt;
    }
    
private:
    void dfs(int cur, int& cnt, int n, bool* vis1, bool* vis2, bool* vis3) {
        if (cur == n) {
            cnt++;
            return;
        }
        for (int i = 0; i < n; i++) {
            if (!vis1[i] && !vis2[cur+i] && !vis3[cur-i+n]) {
                vis1[i] = vis2[cur+i] = vis3[cur-i+n] = true;
                dfs(cur+1, cnt, n, vis1, vis2, vis3);
                vis1[i] = vis2[cur+i] = vis3[cur-i+n] = false;
            }
        }
    }
};