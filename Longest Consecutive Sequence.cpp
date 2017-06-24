//https://leetcode.com/problems/longest-consecutive-sequence/#/description

//暴力，先排序
//time O(nlgn), space O(1)
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int cnt = 0;
        int maxc = 0;
        int lastOne;
        for (int i = 0; i < nums.size(); i++) {
            if (!i || nums[i] == nums[i-1]+1) cnt++;
            else if (nums[i] != nums[i-1]) {
                maxc = max(cnt, maxc);
                cnt = 1;
            }
        }
        return max(maxc, cnt);
    }
};

//用哈希表存储,ump表示在组建序列时此元素是否用过
//time O(n), space O(n)
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, bool> ump;
        int longest = 0;
        for (int i = 0; i < nums.size(); i++) {
            ump[nums[i]] = false;
        }
        for (int i = 0; i < nums.size(); i++) {
            int len = 1;
            if (ump[nums[i]]) continue;
        for (int k = nums[i]+1; ump.find(k) != ump.end(); k++) { //look right
            ump[k] = true;
            len++;
        }
        for (int k = nums[i]-1; ump.find(k) != ump.end(); k--) { //look left
            ump[k] = true;
            len++;
        }
        longest = max(len, longest);
        }
        return longest;
    }
};

