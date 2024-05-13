class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int sol = 0;
        int power = m - 1;
        vector<int> count(m,0);
        for(int i = 0; i < n; i++){
            bool cond = false;
            for(int j = 0; j < m; j++){
                if(j == 0){
                    count[j]++;
                    if(grid[i][j] == 0){
                        cond = true;
                    }
                }
                else{
                    if(grid[i][j] == 1){
                        if(!cond){
                            count[j]++;
                        }
                    }
                    else{
                        if(cond){
                            count[j]++;
                        }
                    }
                }
            }
        }

        for(int i = 0; i < m; i++){
            int mul = max(count[i], n - count[i]);
            sol+= mul * pow(2,power);
            cout << count[i] << " ";
            power--;
        }



        return sol;
    }
};