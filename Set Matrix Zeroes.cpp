//https://leetcode.com/problems/set-matrix-zeroes/#/description
//time O(n*m), space O(n+m)
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> row;
        vector<int> col;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 0) {
                    row.push_back(i);
                    col.push_back(j);
                }
            }
        }
        
        for (int i = 0; i < row.size(); i++) {
            for (int j = 0; j < n; j++) {
                matrix[row[i]][j] = 0;
            }
        }
        
        for (int i = 0; i < col.size(); i++) {
            for (int j = 0; j < m; j++) {
                matrix[j][col[i]] = 0;
            }
        }
    }
	
//time O(m*n), space O(1)
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        bool rowHasZero = false;
        bool colHasZero = false;
        for (int i = 0; i < m; i++) {
            if (matrix[i][0] == 0) {colHasZero = true; break;}
        }
        for (int j = 0; j < n; j++) {
            if (matrix[0][j] == 0) {rowHasZero = true; break;}
        }
        
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (matrix[i][j] == 0) {matrix[i][0] = 0; matrix[0][j] = 0;}
            }
        }
        
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) matrix[i][j] = 0;
            }
        }
        
        if (rowHasZero) {
            for (int j = 0; j < n; j++) matrix[0][j] = 0;
        }
        if (colHasZero) {
            for (int i = 0; i < m; i++) matrix[i][0] = 0;
        }
    }