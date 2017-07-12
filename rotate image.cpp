//https://leetcode.com/problems/rotate-image/#/description

//����ת��Ϊ��ˮƽ���߷�ת���ضԽ��߷�ת
//time O(n^2), space O(1)
void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n/2; j++) {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[i][n-j-1];
                matrix[i][n-j-1] = temp;
            }
        }
}

//ֱ��ʹ����ת����
//time O(n^2), space O(1)

