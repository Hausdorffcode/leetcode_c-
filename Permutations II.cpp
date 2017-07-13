//https://leetcode.com/problems/permutations-ii/#/description

//同样可以
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int> > ret;
        sort(nums.begin(), nums.end());  //很重要，必须的
        do {
            ret.push_back(nums);
        } while(next_permutation(nums.begin(), nums.end()));
        return ret;
    }
};

//time O(2^n), space O(n)
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int> > ret;
        vector<int> path;
        sort(nums.begin(), nums.end());
        f(ret, path, nums, 0, n);
        return ret;
    }
    
private:
    void f(vector<vector<int> >& ret, vector<int>& path, vector<int>& nums, int cur, int n) {
        if (cur == n) {
            ret.push_back(path);
            return;
        }
        for(int i = 0; i < n; i++) {
            if (!i || nums[i] != nums[i-1]) {
                int c1 = 0, c2 = 0;
                for (int j = 0; j < n; j++) if (nums[i] == nums[j]) c1++;
                for (int j = 0; j < path.size(); j++) if (path[j] == nums[i]) c2++;
                if (c1>c2) {
                    path.push_back(nums[i]);
                    f(ret, path, nums, cur+1, n);
                    path.pop_back();
                }
            }
        }
    }
};