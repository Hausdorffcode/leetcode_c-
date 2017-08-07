//https://leetcode.com/problems/combination-sum-ii/description/

//
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ret;
        vector<int> path;
        vector<int> vis(candidates.size(), 0);
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
        int prev = -1;  //È¥ÖØ¹Ø¼ü
        for (int i = cur; i < candidates.size(); i++) {
            if (left < candidates[cur]) {
                return;
            }
            if (candidates[i] == prev) {
                continue;
            }
            path.push_back(candidates[i]);
            prev = candidates[i];
            dfs(ret, path, candidates, i+1, left-candidates[i]);
            path.pop_back();
        }
    }
};