class Solution {
public:
    int help(int ind, int last, vector<vector<int>> &grid, vector<vector<int>> &dp){
        int n = grid.size();
        int temp = INT_MAX;
        if(dp[ind][last] != -1){
            return dp[ind][last];
        }
        
        if(ind == 0){
            for(int i = 0; i < n; i++){
                if(i == last){
                    continue;
                }
                
                temp = min(temp,grid[ind][i]);
            }

            return dp[ind][last] = temp;
        }
        
        for(int i = 0; i < n; i++){
            if(i == last){
                continue;
            }
            temp = min(temp,grid[ind][i] + help(ind - 1, i, grid,dp));

        }

    
        return dp[ind][last] = temp;

    }


    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> dp(n,vector<int>(n + 1, -1));
        
        return help(n - 1, n, grid, dp);
    }
};