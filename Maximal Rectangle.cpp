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
