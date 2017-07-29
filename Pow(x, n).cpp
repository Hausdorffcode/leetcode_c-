//https://leetcode.com/problems/powx-n/description/

//timeo O(logn), space O(1)
//d$c，注意int最小值
class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0) return 1;
        if (n == 1) return x;
        if (n == -1) return 1/x;
        double temp = myPow(x, n/2);
        if (n%2 == 0) {
            return temp*temp;
        } 
        else {
            return n>0 ? temp*temp*x : temp*temp/x;
        }
    }
};