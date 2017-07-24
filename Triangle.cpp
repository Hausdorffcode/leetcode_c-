//https://leetcode.com/problems/triangle/#/description

//dp
//time O(n^2), space O(n);
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        int f[n][n];
        for (int i = 0; i < n; i++) {
            f[n-1][i] = triangle[n-1][i];
        }
        for (int i = n-2; i >= 0; i--) {
            for (int j = 0; j <= i; j++) {
                f[i][j] = triangle[i][j] + min(f[i+1][j], f[i+1][j+1]);
            }
        }
        return f[0][0];
    }
};


//可以做到space O(1)