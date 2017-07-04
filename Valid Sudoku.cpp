//https://leetcode.com/problems/valid-sudoku/#/description

//time O(n^2), space O(n)
class Solution {
public:
    bool isValid(vector<char> nums) {
        bool ok = true;
        int len = nums.size();
        for (int i = 0; i < len; i++) {
            if (i && nums[i] == nums[i-1]) {ok = false; break;}
        }
        return ok;
    }
    
    bool isValidSudoku(vector<vector<char>>& board) {
        int len = board.size();
        if (len != 9) return false;
        vector<char> nums1;
        vector<char> nums2;
        vector<char> nums3;
        
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j]!='.') nums1.push_back(board[i][j]);
                if (board[j][i]!='.') nums2.push_back(board[j][i]);
            }
            sort(nums1.begin(), nums1.end()); //行
            sort(nums2.begin(), nums2.end()); //列
            if (!isValid(nums1)) {return false;}
            if (!isValid(nums2)) return false;
            nums1.clear();
            nums2.clear();
        }
        
        
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                for (int k = i*3; k < i*3+3; k++) {
                    for (int c = j*3; c <j*3+3; c++) {
                        if (board[k][c]!='.') nums3.push_back(board[k][c]);  //小格子
                    }
                }
                sort(nums3.begin(), nums3.end());
                if (!isValid(nums3)) return false;
                nums3.clear();
            }
            
        }
        
        return true;
        
    }
};

//稍微快一点
class Solution {
public:
    bool check(char ch, bool* used) {
        if (ch == '.') return true;
        if (used[ch-'1']) return false;
        used[ch-'1'] = true;
        return true;
    }
    
    bool isValidSudoku(vector<vector<char>>& board) {
        int len = board.size();
        if (len != 9) return false;
        bool used[9];
        
        for (int i = 0; i < 9; i++) {
            memset(used, 0, sizeof(used));
            for (int j = 0; j < 9; j++) {
                if (!check(board[i][j], used)) return false;
            }
        }
        
        for (int i = 0; i < 9; i++) {
            memset(used, 0, sizeof(used));
            for (int j = 0; j < 9; j++) {
                if (!check(board[j][i], used)) return false;
            }
        }
        
        for (int r = 0; r < 3; r++) {
            for (int c = 0; c < 3; c++) {
                memset(used, 0, sizeof(used));
                for (int i = 3*r; i < 3*r+3; i++) {
                    for (int j = 3*c; j < 3*c+3; j++) {
                        if (!check(board[i][j], used)) return false;
                    }
                }
            }
        }
        return true;
    }
};