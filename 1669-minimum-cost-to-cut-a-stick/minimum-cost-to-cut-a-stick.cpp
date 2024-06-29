class Solution {
public:
    int solve(int n, int i, int j, vector<int> &cuts, vector<vector<int>> &dp){
        int m = cuts.size();
        int start = 0;
        int end = n;
        if(i > j){
            return 0;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        if(i > 0){
            start = cuts[i - 1];
        }
        if(j < m - 1){
            end = cuts[j + 1];
        }
        int temp = 1e9 + 7;
        int length = end - start;
        for(int k = i; k <= j; k++){
            temp = min(temp, length + solve(n,i,k - 1,cuts, dp) + solve(n,k + 1,j,cuts,dp));
        }


        return dp[i][j] = temp;
    }
    
    int minCost(int n, vector<int>& cuts) {
        int m = cuts.size();
        vector<vector<int>> dp(m,vector<int>(m, - 1));
        sort(cuts.begin(), cuts.end());
        return solve(n,0,m - 1,cuts, dp);
    }
};