https://leetcode.com/problems/largest-rectangle-in-histogram/#/description

//暴力，超时
//time O(n^2), time O(1)
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        if (n <= 0) return 0;
        int area = 0;
        for (int i = 0; i < n; i++) {
            int q = i;
            while (q < n && heights[i] <= heights[q]) {
                q++;
            }
            int p = i;
            while (p >=0 && heights[i] <= heights[p]) {
                p--;
            }
            area = max(area, heights[i]*(q-p-1));
        }
        return area;
    }
};

//用栈来找左右pq
//time O(n), space O(n)
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        heights.push_back(0);   //很重要
        int n = heights.size();
        stack<int> s;
        int ret = 0;
        for (int i = 0; i < n;) {
            if (s.empty() || heights[i] > heights[s.top()]) {
                s.push(i++);
            }
            else {
                int temp = s.top(); s.pop();
                int rightIndex = i;
                int leftIndex = s.empty() ? -1 : s.top();
                ret = max(ret, heights[temp] * (rightIndex-leftIndex-1));
            }
        }
        return ret;
    }
};