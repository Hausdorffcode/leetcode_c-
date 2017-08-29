//https://leetcode.com/problems/unique-binary-search-trees/description/

//dp
class Solution {
public:
    int numTrees(int n) {
        vector<int> f(n+1, 0);
        f[0] = 1;
        f[1] = 1;
        for (int i = 2 ; i <= n; i++) {
            int temp = 0;
            for (int j = 1; j <= i; j++) {
                temp += f[j-1] * f[i-j];
            }
            f[i] = temp;
        }
        return f[n];
    }
};