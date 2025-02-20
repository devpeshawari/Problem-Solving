class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> rows(n,0);
        vector<int> columns(m,0);

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(matrix[i][j] == 0){
                    rows[i] = 1;
                    columns[j] = 1;
                }
            }
        }    

        for(int i = 0; i < n; i++){
            if(rows[i] == 1){
                for(int j = 0; j < m; j++){
                    matrix[i][j] = 0;
                }
            }
        }
        for(int j = 0; j < m; j++){
            if(columns[j] == 1){
                for(int i = 0; i < n; i++){
                    matrix[i][j] = 0;
                }
            }
        }
    }
};