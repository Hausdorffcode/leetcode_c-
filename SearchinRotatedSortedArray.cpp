//https://leetcode.com/problems/search-in-rotated-sorted-array/#/description

//关键在于定边界
//time O(lgn), space O(1)
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int p = 0, q = nums.size() - 1;
        int mid;
        while (p <= q) {
            mid = p + (q-p)/2;
            if (target == nums[mid]) return mid;
            else if (target > nums[mid]) {
                if (nums[mid] > nums[q] || (nums[mid] < nums[q] && nums[q] >= target)) {
                    p = mid+1;
                } else {
                    q = mid-1;
                }
            } else {
                if (nums[mid] < nums[p] || (nums[mid] > nums[p] && nums[p] <= target)) {
                    q = mid-1;
                } else {
                    p = mid+1;
                }
            }
        }
        return -1;
    }
};

//换了判断条件，思路更清晰
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int p = 0, q = nums.size()-1;
        int mid;
        while (p <= q) {
            mid = p+(q-p)/2;
            if (nums[mid] == target) return mid;
            else if(nums[mid] >= nums[p]) {
                if (nums[p] <= target && target < nums[mid]) {
                    q = mid-1;
                } else {
                    p = mid+1;
                }
            } else {
                if (nums[mid] < target && target <= nums[q]) {
                    p = mid+1;
                } else {
                    q = mid-1;
                }
            }
        }
        return -1;
    }
};

//还可以用二分先找到偏移量，在二分
class Solution {
public:
    int search(int A[], int n, int target) {
        int lo=0,hi=n-1;
        // find the index of the smallest value using binary search.
        // Loop will terminate since mid < hi, and lo or hi will shrink by at least 1.
        // Proof by contradiction that mid < hi: if mid==hi, then lo==hi and loop would have been terminated.
        while(lo<hi){
            int mid=(lo+hi)/2;
            if(A[mid]>A[hi]) lo=mid+1;
            else hi=mid;
        }
        // lo==hi is the index of the smallest value and also the number of places rotated.
        int rot=lo;
        lo=0;hi=n-1;
        // The usual binary search and accounting for rotation.
        while(lo<=hi){
            int mid=(lo+hi)/2;
            int realmid=(mid+rot)%n;
            if(A[realmid]==target)return realmid;
            if(A[realmid]<target)lo=mid+1;
            else hi=mid-1;
        }
        return -1;
    }
};