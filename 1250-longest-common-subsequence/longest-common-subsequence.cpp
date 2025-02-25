class Solution {
public:
    int solve(int i, int j, string &text1, string &text2, vector<vector<int>> &dp){
        int n = text1.size();
        int m = text2.size();
        if(i == n || j == m) return 0;
        if(dp[i][j] != -1) return dp[i][j]; 
        int take = 0;
        if(text1[i] == text2[j]){
            take = 1 + solve(i + 1,j + 1,text1,text2,dp);
        }
        int notTake = max(solve(i + 1,j,text1,text2,dp),solve(i,j + 1,text1,text2,dp));


        return dp[i][j] = max(take,notTake);
    }
    
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        vector<vector<int>> dp(n + 1,vector<int>(m + 1,0));
        
        for(int i = n - 1; i >= 0; i--){
            for(int j = m - 1; j >= 0; j--){
                int take = 0;
                if(text1[i] == text2[j]){
                    take = 1 + dp[i + 1][j + 1];
                }
                int notTake = max(dp[i + 1][j],dp[i][j + 1]);
                dp[i][j] = max(take,notTake);
            }   
        }

        return dp[0][0];
    }
};