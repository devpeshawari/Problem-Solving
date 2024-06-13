class Solution {
public:
    int help(int n, vector<int> &dp){
        if(n < 0){
            return 0;
        }
        if(dp[n] != -1){
            return dp[n];
        }
        if(n == 0){
            return dp[n] = 1;
        }

        int single = help(n - 1,dp);
        int twice = help(n - 2,dp);


        return dp[n] = single + twice;
    }
    
    
    int climbStairs(int n) {
        vector<int> dp(n + 1,-1);
        int sol = help(n, dp);


        return dp[n];
    }
};