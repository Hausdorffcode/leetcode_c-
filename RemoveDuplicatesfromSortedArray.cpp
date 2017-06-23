//数组
//https://leetcode.com/problems/remove-duplicates-from-sorted-array/#/description
//由于是有序的，只要用两个指针，一个遍历，一个记录已读过不同元素的数组的下标，每次
//读到不同的元素，可以直接替换
//time O(n), space O(1)

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        } 
        int index = 0;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[index] != nums[i]) {
                index++;
                nums[index] = nums[i];
            }
        }
        return index+1;
    }
};