//https://leetcode.com/problems/subsets/#/description

//time O(2^n), spaceO(n)
//增量构造法：每个元素都有两种选择
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int> > ret;
        vector<int> path;
        f(ret, path, nums, 0);
        return ret;
    }
    
private:
    void f(vector<vector<int> >& ret, vector<int>& path, vector<int>& nums, int cur) {
        if (cur == nums.size()) {
            ret.push_back(path);
            return;
        }
        f(ret, path, nums, cur+1);
        path.push_back(nums[cur]);
        f(ret, path, nums, cur+1);
        path.pop_back();       //重要
    }
};

//位向量法
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int> > ret;
        vector<int> path;
        vector<bool> B(nums.size(), false);
        f(ret, path, nums, 0, B);
        return ret;
    }
    
private:
    void f(vector<vector<int> >& ret, vector<int>& path, vector<int>& nums, int cur, vector<bool>& B) {
        if (cur == nums.size()) {
            path.clear();
            for (int i = 0; i < B.size(); i++) {
                if (B[i]) path.push_back(nums[i]);
            }
            ret.push_back(path);
            return;
        }
        B[cur] = false;
        f(ret, path, nums, cur+1, B);
        B[cur] = true;
        f(ret, path, nums, cur+1, B);   
    }
};

//二进制法
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int> > ret;
        vector<int> path;
        for (int i = 0; i < (1<<nums.size()); i++){  
            f(ret, path, nums, i);
        }
        return ret;
    }
    
private:
    void f(vector<vector<int> >& ret, vector<int>& path, vector<int>& nums, int s) {
        path.clear();
        for (int i = 0 ; i < nums.size(); i++) {
            if (s&(1<<i)) path.push_back(nums[i]);
        }
        ret.push_back(path);
    }
};

//二进制法
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int> > ret;
        vector<int> path;
        for (int i = 0; i < (1<<nums.size()); i++){  
            path.clear();
            for (int j = 0 ; j < nums.size(); j++) {
                if (i&(1<<j)) path.push_back(nums[j]);
            }
            ret.push_back(path);
        }
        return ret;
    }
};