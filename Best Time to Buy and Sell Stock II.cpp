//https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/#/description

//Ì°ÐÄ
//time O(n), space O(1)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ret = 0;
        int n = prices.size();
        for (int i = 0; i < n-1; i++) {
            int del = prices[i+1] - prices[i];
            if (del > 0) ret += del; 
        }
        return ret;
    }
};