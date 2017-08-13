//https://leetcode.com/problems/reverse-integer/description/

//time O(n), space O(1)
class Solution {
public:
    int reverse(int x) {
        long tempx = x;
        bool sign = true;
        if (tempx < 0) {
            sign = false;
            tempx = -tempx;
        }
        long ret = 0;
        while (tempx > 0) {
            int digit = tempx % 10;
            tempx /= 10;
            ret = ret * 10 + digit;
        }
        long y = 1; //这个很重要，直接1<<31会溢出
        long border = y <<31;
        if (sign && ret > border-1) ret = 0;
        else if (!sign && ret > border) ret  = 0;
        if (!sign) ret = -ret;
        return (int) ret;
    }
};