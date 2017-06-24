//https://leetcode.com/problems/3sum/#/description

//先排序，然后左右夹逼
//time O(n^2), space O(1);
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        //if (nums.size()<3) return ans;
        sort(nums.begin(), nums.end());
        int boundd = nums.size()-2; //注意这里，不能直接写在for里，size返回的是unsignInt
        for(int i = 0; i < boundd; i++) {
            if (i && nums[i] == nums[i-1]) continue;
            int target = 0-nums[i];
            int p = i+1, q = nums.size()-1;
            while (p < q) {
                int temp = nums[p]+nums[q];
                if (temp == target) {
                    vector<int> x;
                    x.push_back(nums[i]);
                    x.push_back(nums[p]);
                    x.push_back(nums[q]);
                    ans.push_back(x);
                    p++;
                    q--;
                    while (nums[p] == nums[p-1]) {p++;}
                    while (nums[q] == nums[q+1]) {q--;}
                } else if (temp > target) q--;
                else p++;
            }
        }
        return ans;
    }
};