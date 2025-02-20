class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> pascalsTriangle(numRows);
        int n = numRows;
        pascalsTriangle[0].push_back(1);
        if(n != 1){
            for(int i = 1; i < n; i++){
                int numElements = i + 1;
                for(int j = 0; j < numElements; j++){
                    if(j == 0){ 
                        pascalsTriangle[i].push_back(1);
                    }
                    else if(j == numElements - 1){
                        pascalsTriangle[i].push_back(1);
                    }
                    else{
                        pascalsTriangle[i].push_back(pascalsTriangle[i - 1][j - 1] + pascalsTriangle[i - 1][j]);
                    }
                }
            }
        }

        return pascalsTriangle;    
    }
};