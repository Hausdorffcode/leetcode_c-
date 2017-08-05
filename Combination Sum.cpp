//https://leetcode.com/problems/combination-sum/description/

//
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ret;
        vector<int> path;
        sort(candidates.begin(), candidates.end());
        dfs(ret, path, candidates, 0, target);
        return ret;
    }
    
private:
    void dfs(vector<vector<int>>& ret, vector<int>& path, vector<int>& candidates, int cur, int left) {
        if (left == 0) {
            ret.push_back(path);
            return;
        }
        
        for (int i = cur; i < candidates.size(); i++) {
            if (left < candidates[i]) return;
            path.push_back(candidates[i]);
            dfs(ret, path, candidates, i, left-candidates[i]);
            path.pop_back();
        }
    }
};