#define ll long long
class Solution {
public:
    ll solve(int i, int amount, vector<int> &coins, vector<vector<int>> &dp){
        int n = coins.size();
        if(i == 0){
            if(amount%coins[i] == 0){
                return amount/coins[i];
            }
            else{
                return INT_MAX;
            }
        }
        if(amount == 0){
            return 0;
        }
        if(dp[i][amount] != -1){
            return dp[i][amount];
        }
        
        
        ll take = INT_MAX;
        if(amount >= coins[i]){
            take = 1 + solve(i,amount - coins[i], coins, dp);
        }
        ll notTake = solve(i - 1,amount,coins,dp);

        

        return dp[i][amount] = min(take,notTake);
;        
    }
    
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int> (amount + 1,-1));

        int sol =  solve(n - 1,amount,coins,dp);
        if(sol == INT_MAX){
            return -1;
        }
        return sol;



    }
};