//https://leetcode.com/problems/median-of-two-sorted-arrays/#/description

//暴力归并
//time O(n+m), space O(n+m)
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len = nums1.size() + nums2.size();
        vector<int> aux(len);
        int p = 0, q = 0;
        for (int i = 0; i < len; i++) {
            if (p >= nums1.size()) aux[i] = nums2[q++];
            else if (q >= nums2.size()) aux[i] = nums1[p++];
            else if (nums1[p] <= nums2[q]) aux[i] = nums1[p++];
            else aux[i] = nums2[q++];
        }
        int left = (len-1)/2;
        int right = (len)/2;
        return (double)(aux[left]+aux[right])/2;
    }
};