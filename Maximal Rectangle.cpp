//https://leetcode.com/problems/maximal-rectangle/#/description

//思路来源于https://leetcode.com/problems/largest-rectangle-in-histogram/#/description
//可以合并，边构建H，边计算
//time O(n*m), space O(m)
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        if (n <= 0) return 0;
        int m = matrix[0].size();
        if (m <= 0) return 0;
        
        int maxone = 0;
        int H[m+1];
        memset(H, 0, sizeof(H));
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == '1') {H[j]++;}
                else H[j] = 0;
            }
            maxone = max(maxone, area(H, m+1));
        }
        return maxone;
    }
    
private:
    int area(int* H, int n) {
        int maxone = 0;
        stack<int> s;
        for (int i = 0; i < n;) {
            if (s.empty() || H[i] > H[s.top()]) {
                s.push(i++);
            }
            else {
                int temp = s.top(); s.pop();
                int rightIndex = i;
                int leftIndex = s.empty() ? -1 : s.top();
                maxone = max(maxone, H[temp]*(rightIndex - leftIndex -1));
            }
        }
        return maxone;
    }
};

//dp
//time O(n*m), space O(n)
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size();
        if (m <= 0) return 0;
        int n = matrix[0].size();
        if (n <= 0) return 0;
        
        vector<int> lt(n, 0);
        vector<int> hi(n, n);
        vector<int> height(n, 0);
        int ret = 0;
        
        for (int i = 0; i < m; i++) {
            int cur_left = 0, cur_right = n;
            
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == '1') height[j]++;
                else height[j] = 0;
            }
            
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == '1') {
                    lt[j] = max(lt[j], cur_left);
                }
                else {
                    lt[j] = 0;
                    cur_left = j+1;
                }
            }
            
            for (int j = n-1; j >= 0; j--) {
                if (matrix[i][j] == '1') {
                    hi[j] = min(hi[j], cur_right);
                }
                else {
                    hi[j] = n;
                    cur_right = j;
                }
            }
            
            for (int j = 0; j < n; j++) {
                ret = max(ret, (hi[j]-lt[j])*height[j]);
            }
        }
        return ret;
    }
};