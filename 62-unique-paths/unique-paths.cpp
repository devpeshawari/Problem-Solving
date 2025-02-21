class Solution {
public:
    int solve(int m, int n, vector<vector<int>> &dp){
        if(m == 0 && n == 0){
            return 1;
        }
        int left = 0;
        int right = 0;
        if(dp[m][n] != -1) return dp[m][n];
        if(m > 0){
            left = solve(m - 1,n,dp);
        }
        if(n > 0){
            right = solve(m,n - 1,dp);
        }

        return dp[m][n] = left + right;
    }
    
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n,-1));    
        
        dp[0][0] = 1;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(i == 0 && j == 0) continue;
                int left = 0;
                int right = 0;
                if(i > 0){
                    left = dp[i - 1][j];
                }
                if(j > 0){
                    right = dp[i][j - 1];
                }
                dp[i][j] = left + right;
            }
        }
        
        return dp[m - 1][n - 1];
    }
};