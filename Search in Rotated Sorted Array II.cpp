//比上一题https://leetcode.com/problems/search-in-rotated-sorted-array/#/description
//增加了允许重复元素的条件
//https://leetcode.com/problems/search-in-rotated-sorted-array-ii/#/description

//当nums[mid] == nums[p]时无法判断哪边是顺序，但p一定不是我们要找的
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int p = 0, q = nums.size()-1;
        int mid;
        while (p <= q) {
            mid = p+(q-p)/2;
            if (nums[mid] == target) return true;
            else if(nums[mid] > nums[p]) {
                if (nums[p] <= target && target < nums[mid]) {
                    q = mid-1;
                } else {
                    p = mid+1;
                }
            } else if(nums[mid] == nums[p]) {
                p++;
            } else {
                if (nums[mid] < target && target <= nums[q]) {
                    p = mid+1;
                } else {
                    q = mid-1;
                }
            }
        }
        return false;
    }
};