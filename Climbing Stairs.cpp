//https://leetcode.com/problems/climbing-stairs/#/description
//斐波那契数f(n) = f(n-1) + f(n-2)
//time O(n), space O(1)
    int climbStairs(int n) {
        int a = 1;
        int b = 1;
        for (int i = 0; i < n; i++) {
            int temp = b;
            b = a+b;
            a = temp;
        }
        return a;
    }