//https://leetcode.com/problems/valid-palindrome/#/description

//time O(n), space O(1)
class Solution {
public:
    bool isPalindrome(string s) {
        if (s.size() == 0) return true;
        //transform(s.begin(), s.end(), s.begin(), ::tolower);
        int len = s.size();
        int p = 0, q = len-1;
        while (p < q) {
            if (!isalnum(s[p])) {p++; continue;}
            if (!isalnum(s[q])) {q--; continue;}
            if (tolower(s[p]) != tolower(s[q])) return false;
            p++;
            q--;
        }
        return true;
    }
};