//https://leetcode.com/problems/best-time-to-buy-and-sell-stock/#/description

//dp
//time O(n), space O(n)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n <= 1) return 0;
        int ret  = 0;
        int trans[n-1];
        for (int i = 0; i < n-1; i++) {
            trans[i] = prices[i+1] - prices[i];
        }
        int f[n-1];
        memset(f, 0, sizeof(f));
        
        f[0] = trans[0];
        ret = max(ret, f[0]);
        for (int i = 1; i < n-1; i++) {
            if (f[i-1] > 0) f[i] = f[i-1] + trans[i];
            else f[i] = trans[i];
            ret = max(ret, f[i]);
        }
        return ret;
    }
};

//Ì°ÐÄ
//time O(n), space O(1)