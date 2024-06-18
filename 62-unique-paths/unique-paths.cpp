class Solution {
public:
    int solve(int x, int y, vector<vector<int>> &dp){
        if(x == 0 && y == 0){
            return 1;
        }
        if(dp[x][y] != -1){
            return dp[x][y];
        }
        int up = 0;
        int left = 0;
        if(x - 1 >= 0){
            up = solve(x - 1,y,dp);
        }
        if(y - 1 >= 0){
            left = solve(x,y - 1,dp);
        }

        return dp[x][y] = left + up;
    }
    
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n,-1));

        return solve(m - 1,n - 1,dp);
    }
};