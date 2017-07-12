//https://leetcode.com/problems/trapping-rain-water/#/description

//每一点找左右最大值
//time O(n^2), space O(1)
int trap(vector<int>& height) {
        int len = height.size();
        if (len <=2) return 0;
        
        int total = 0;
        for (int i = 1; i < len-1; i++) {
            int leftPeek = height[0];
        int rightPeek = height[len-1];
            for (int j = i-1; j >= 0; j--) {
                if (leftPeek < height[j]) leftPeek = height[j];
            }
            for (int j = i+1; j < len; j++) {
                if (rightPeek < height[j]) rightPeek = height[j];
            }
            int peek = min(leftPeek, rightPeek);
            int del = max(0, peek-height[i]);
            total += del;
        }
        return total;
}

//用两个数组记录左右峰值
//time O(n), space O(n)
int trap(vector<int>& height) {
        int n = height.size();
        int *leftPeek = new int[n]();
        int *rightPeek = new int[n]();
        for (int i = 1; i < n-1; i++) {
            if (height[i-1] > leftPeek[i-1]) leftPeek[i] = height[i-1];
            else leftPeek[i] = leftPeek[i-1];
            
            rightPeek[n-i-1] = max(rightPeek[n-i], height[n-i]);
        }
        
        int total = 0;
        for (int i = 1; i < n-1; i++) {
            total += max(0, min(leftPeek[i], rightPeek[i])-height[i]);
        }
        return total;
    }

//找到最大值，分左右两部分遍历一遍
//time O(n), space O(1)
int trap(vector<int>& height) {
        int n = height.size();
        int indexOfMax = 0;
        for (int i = 0; i < n; i++) {
            if (height[indexOfMax] < height[i]) indexOfMax = i;
        }
        int total = 0;
        for (int i = 0, peek = 0; i < indexOfMax; i++) {
            if (peek < height[i]) peek = height[i];
            else total += peek - height[i];
        }
        for (int i = n-1, peek = 0; i >indexOfMax; i--) {
            if (peek < height[i]) peek = height[i];
            else total += peek - height[i];
        }
        return total;
    }