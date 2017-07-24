//https://leetcode.com/problems/maximum-subarray/#/description

//dp
//time O(n), space O(n)
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        if (n <= 0) return 0;
        int f[n];
        
        f[0] = nums[0];
        int maxone = f[0];
        
        for (int i = 1; i < n; i++) {
            if (f[i-1] >= 0) {
                f[i] = f[i-1] + nums[i];
            } else {
                f[i] = nums[i];
            }
            maxone = max(maxone, f[i]);
        }
        return maxone;
    }
};

//可以做到space O(1)

//可以用分治