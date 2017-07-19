//https://leetcode.com/problems/unique-paths/#/description

//超时，dfs
//time O(m*n^2), space O(1)
class Solution {
public:
    int uniquePaths(int m, int n) {
        if (m < 1 || n < 1) return 0;     //终止条件
        if (m == 1 && n == 1) return 1;  //收敛条件
        return uniquePaths(m, n-1) + uniquePaths(m-1, n);
    }
};

//dfs+缓存=备忘录法
//time O(m*n), space O(m*n)
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int> > f;
        f = vector<vector<int> >(m, vector<int>(n, 0));
        dfs(f, m-1, n-1);
        return f[m-1][n-1];
    }
    
private:
    int dfs(vector<vector<int>> &f, int m, int n) {
        if (m < 0 || n < 0) return 0;
        if (m == 0 && n == 0) { f[m][n] = 1; return 1;}
        if (f[m][n] != 0) return f[m][n];
        else return f[m][n] = dfs(f, m-1, n) + dfs(f, m, n-1);
    }
};