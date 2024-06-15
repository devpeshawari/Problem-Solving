#define ll long long
class Solution {
public:
    ll solve(int i, int amount, vector<int> &coins, vector<vector<int>> &dp){
        int n = coins.size();
        if(i >= n || amount < 0){
            return INT_MAX;
        }
        if(dp[i][amount] != -1){
            return dp[i][amount];
        }
        if(amount == 0){
            return 0;
        }
        
        ll take = 1 + solve(i,amount - coins[i], coins, dp);
        ll notTake = solve(i + 1,amount,coins,dp);

        

        return dp[i][amount] = min(take,notTake);
;        
    }
    
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int> (amount + 1,-1));

        int sol =  solve(0,amount,coins,dp);
        if(sol == INT_MAX){
            return -1;
        }
        return sol;
    }
};