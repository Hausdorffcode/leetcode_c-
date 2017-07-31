//https://leetcode.com/problems/longest-palindromic-substring/description/

//time O(n^2), space O(n)
//暴力
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if (n == 0) return NULL;
        string helper;
        for (int i = 0; i < n; i++) {
            helper.push_back('#');
            helper.push_back(s[i]);
        }
        helper.push_back('#');
        int lt = 0, hi = 0;
        int maxLen = 1;
        int maxlt = 0;
        int maxhi = 0;
        for (int i = 0; i < 2*n+1; i++) {
            lt = i;
            hi = i;
            while (lt >= 0 && hi <= 2*n && helper[lt] == helper[hi]) {
                lt--;
                hi++;
            }
            if (maxLen < hi-lt-1) {maxLen = hi-lt-1; maxlt = lt; maxhi = hi;}
        }
        return s.substr((maxlt+1)/2, maxLen/2);
    }
};


//dp
//time O(n^2), space O(n^2)
//f为[i, j]之间是否为回文
//coding style .....................return...........
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if (n == 0) return NULL;
        bool f[n][n];
        memset(f, 0, sizeof(f));
        for (int len = 0; len <= n-1; len++) {
            for (int i = 0; i + len < n; i++) {
                int j = i + len;
                if (i == j) f[i][j] = true;
                else if (i == j-1) f[i][j] = (s[i] == s[j]);
                else f[i][j] = (s[i] == s[j] && f[i+1][j-1]);
            }
        }
        for (int len = n-1; len >= 0; len--) {
            for (int i = 0; i + len < n; i++) {
                int j = i+len;
                if (f[i][j]) return s.substr(i, len+1);
            }
        }
        
    }
};

//dp
//good coding style
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if (n == 0) return "";
        bool f[n][n];
        memset(f, 0, sizeof(f));
        
        int maxLen = 1;
        int start = 0;
        for (int j = 0; j < n; j++) {
            f[j][j] = true;
            for (int i = 0; i < j; i++) {
                if (i == j-1) f[i][j] = (s[i] == s[j]);
                else f[i][j] = (s[i] == s[j]) && f[i+1][j-1];
                
                if (f[i][j] && maxLen < (j-i+1)) {
                    maxLen = j-i+1;
                    start = i;
                }
            }
        }
        return s.substr(start, maxLen);
    }
};