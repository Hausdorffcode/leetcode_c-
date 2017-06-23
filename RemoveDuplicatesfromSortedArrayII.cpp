//https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/#/description

//思路大致同上一题https://leetcode.com/problems/remove-duplicates-from-sorted-array/#/description
//只要增加一个变量记录下次数
//time O(n), space O(1)
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        int index = 0;
        int count = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != nums[index]) {
                index++;
                nums[index] = nums[i];
                count = 1;
            } else if (count < 2) {
                index++;
                nums[index] = nums[i];
                count++;
            }
        }
        return index+1;
    }
};

