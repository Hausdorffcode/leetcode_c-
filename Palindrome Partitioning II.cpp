//https://leetcode.com/problems/palindrome-partitioning-ii/#/description

//两个dp
//time O(n^2), space O(n^2)
class Solution {
public:
    int minCut(string s) {
        
        int n = s.size();
        if (n <= 0) return 0;
        bool P[n][n];
        memset(P, 0, sizeof(P));
        
        int f[n+1];
        for (int i = 0; i <= n; i++) {
            f[i] = n-1-i;
        }
        
        for (int i = n-1; i >= 0; i--) {
            for (int j = i; j < n; j++) {
                if (s[i] == s[j] && (j-i < 2 || P[i+1][j-1])) {
                    P[i][j] = 1;
                    f[i] = min(f[i], f[j+1]+1);
                }
            }
        }      
        return f[0];
    }
};