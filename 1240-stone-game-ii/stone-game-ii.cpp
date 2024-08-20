class Solution {
public:
    int solve(int ind, int m, int cond,vector<int> &piles, vector<vector<vector<int>>> &dp){
        int n = piles.size();
        if(dp[ind][m][cond] != -1) return dp[ind][m][cond]; 
        if(ind == n) return dp[ind][m][cond] =  0;
        if(ind == n - 1){
            if(cond == 1){
                return 0;
            }
            else{
                return piles[ind];
            }
        }

        int sum = 0;
        int take = INT_MAX;
        if(cond == 0) take = 0;
        for(int i = ind; i < min(n,ind + (2 * m)); i++){
            sum+=piles[i];
            if(cond == 0){
                take = max(take,sum + solve(i + 1,max(m,i - ind + 1),1,piles,dp));
            }
            else{
                take = min(take,solve(i + 1,max(m,i - ind + 1),0,piles,dp));
            }
        }


        return dp[ind][m][cond] = take;
    }
    
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        vector<int> sum;
        int total = 0;
        int sol = 0;
        vector<vector<vector<int>>> dp(n + 1,vector<vector<int>>(n + 1,vector<int>(2,-1)));
        return solve(0,1,0,piles,dp);
    }
};