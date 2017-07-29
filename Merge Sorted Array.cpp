//https://leetcode.com/problems/merge-sorted-array/description/

//time O(m+n), space O(1)
//注意m, n并不一定正好是个数
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for (int i = n; i < n+m; i++) {
            if (i < nums2.size()) nums2[i] = nums1[i-n];
            else nums2.push_back(nums1[i-n]);
        }
        nums1.clear();
        int p = 0, q = n;
        for (int i = 0; i < m+n; i++) {
            if (p >= n) { nums1.push_back(nums2[q]); q++;}
            else if (q >= m+n) { nums1.push_back(nums2[p]); p++;}
            else if (nums2[p] < nums2[q]) {nums1.push_back(nums2[p]); p++;}
            else {nums1.push_back(nums2[q]); q++;}
        }
        return;
    }
};

//time O(n+m), space O(1)
//从屁股后面开始排, nice
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int p = m-1, q = n-1, cur = m+n-1;
        while (p >= 0 && q >= 0) {
            if (nums1[p] > nums2[q]) { nums1[cur] = nums1[p]; cur--; p--;}
            else { nums1[cur] = nums2[q]; cur--; q--;}
        }
        while (q >= 0) {
            nums1[cur] = nums2[q--];
            cur--;
        }
    }
};