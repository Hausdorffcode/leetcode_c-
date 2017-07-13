//https://leetcode.com/problems/permutations/#/description

//time O(2^n), space O(n)
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int> > ret;
        vector<int> path;
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
            bool ok = true;
            for (int j = 0; j < path.size(); j++) {
                if (path[j] == nums[i]) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                path.push_back(nums[i]);
                f(ret, path, nums, cur+1, n);
                path.pop_back();   //注意！！！
            }
        }
    }
};

//直接调用next_permutation
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int> > ret;
        sort(nums.begin(), nums.end());  //很重要，必须的
        do {
            ret.push_back(nums);
        } while(next_permutation(nums.begin(), nums.end()));
        return ret;
    }
};