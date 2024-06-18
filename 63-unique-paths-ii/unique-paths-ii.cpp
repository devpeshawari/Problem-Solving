class Solution {
public:
    int solve(int i, int j, vector<vector<int>> &obstacleGrid, vector<vector<int>> &dp){
        if(obstacleGrid[i][j] == 1){
            return 0;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        if(i == 0 && j == 0){
            return 1;
        }
        int up = 0;
        int left = 0;

        if(i - 1 >= 0 && !obstacleGrid[i - 1][j]){
            up = solve(i - 1, j, obstacleGrid, dp);
        }
        if(j - 1 >= 0 && !obstacleGrid[i][j - 1]){
            left = solve(i, j - 1, obstacleGrid, dp);
        }

        return dp[i][j] = up + left;
    }
    
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {    
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));

        return solve(n - 1, m - 1, obstacleGrid, dp);

    }
};