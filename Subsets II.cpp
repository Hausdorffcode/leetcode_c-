//https://leetcode.com/problems/subsets-ii/#/description

//增量构造
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int> > ret;
        vector<int> path;
        sort(nums.begin(), nums.end());
        dfs(ret, path, nums, nums.begin());
        return ret;
    }
    
private:
    void dfs(vector<vector<int>>& ret, vector<int>& path, vector<int>& nums, vector<int>::iterator start){
        ret.push_back(path);
        for (auto i = start; i != nums.end(); i++) {
            if (i == start || *i != *(i-1)) {
                path.push_back(*i);
                dfs(ret, path, nums, i+1);
                path.pop_back();
            }
        }
    }
};

//增量构造
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ret;
        vector<int> path;
        unordered_map<int, int> ump;
        for (int i = 0; i < nums.size(); i++) {
            if (ump.find(nums[i]) != ump.end()) {
                ump[nums[i]]++;
            } else {
                ump[nums[i]] = 1;
            }
        }
        vector<pair<int, int>> elems;
        for (auto i = ump.begin(); i != ump.end(); i++) {
            elems.push_back(*i);
        }
        sort(elems.begin(), elems.end());
        dfs(ret, path, elems, 0);
        return ret;
    }
    
private:
    void dfs(vector<vector<int>>& ret, vector<int>& path, vector<pair<int, int>>& elems, int cur) {
        if (cur == elems.size()) {
            ret.push_back(path);
            return;
        }
        for (int i = 0; i <= elems[cur].second; i++) {
            for (int j = 0; j < i; j++) {
                path.push_back(elems[cur].first);
            }
            dfs(ret, path, elems, cur+1);
            for (int j = 0; j < i; j++) {
                path.pop_back();
            }
        }
    }
};