//https://leetcode.com/problems/single-number-ii/tabs/description

//time O(n), space O(n)
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> p;
        for (int  i = 0; i < n; i++) {
            if (p.find(nums[i]) != p.end()) {
                p[nums[i]]++;
            }
            else {
                p[nums[i]] = 1;
            }
        }
        for (auto it = p.begin(); it != p.end(); it++) {
            if ((*it).second != 3) return (*it).first;
        }
        return 1;        
    }
};

//time O(n), space O(1)
//Î»ÔËËã
