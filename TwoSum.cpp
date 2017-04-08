/**Two Sum
Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:
Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
*/

/**用hash表存入每个元素的下标，遍历寻找
时间O(n)，空间O(n)*/
//两次遍历
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mapping;
        vector<int> ret;
        for (int i = 0; i < nums.size(); i++) {
            mapping[nums[i]] = i;
        }
        for (int i= 0; i < nums.size(); i++) {
            const int gap = target - nums[i];
            if (mapping.find(gap) != mapping.end() && mapping[gap] > i) {
                ret.push_back(i);
                ret.push_back(mapping[gap]);
                break;
            }
        }
        return ret;
    }
};

//一次遍历
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> um;
        vector<int> ret(2);
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (um.find(target - nums[i]) != um.end()) {
                ret[0] = um[target-nums[i]];
                ret[1] = i;
                break;
            } else {
                um[nums[i]] = i;
            }
        }
        return ret;
    }
};