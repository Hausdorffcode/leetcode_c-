//https://leetcode.com/problems/palindrome-number/description/

//
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        int mod = 1;
        while (x / mod >= 10) {
            mod *= 10;
        }
        bool ret = true;
        while (mod != 0 && mod != 1) {
            int tail = x % 10;
            int head = x / mod;
            if (head != tail) {ret =  false; break;}
            x %= mod;
            x /= 10;
            mod /= 100;
        }
        return ret;
    }
};