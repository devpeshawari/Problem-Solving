class Solution {
public:
     
    void convert(int x, int y, vector<vector<int>> &matrix,vector<vector<int>> &temp){
        int n = matrix.size();
        int m = matrix[0].size();
        int i = x - 1;
        while(i >= 0){
            if(matrix[i][y] != 0){
                temp[i][y] = -1;
            }
            i--;
        }
        i = x + 1;
        while(i < n){
            if(matrix[i][y] != 0){
                temp[i][y] = -1;
            }
            i++;
        }
        int j = y - 1;
        while(j >= 0){
            if(matrix[x][j] != 0){
                temp[x][j] = -1;
            }
            j--;
        }
        j = y + 1;
        while(j < m){
            if(matrix[x][j] != 0){
                temp[x][j] = -1;
            }
            j++;
        }
    } 
    
    
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> temp(n,vector<int>(m,0));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(matrix[i][j] == 0){
                    convert(i,j,matrix,temp);
                }
            }
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(temp[i][j] == -1){
                    matrix[i][j] = 0;
                }
            }
        }
    }
};