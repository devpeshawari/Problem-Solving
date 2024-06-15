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
        // vector<vector<ll>> dp(n, vector<ll> (amount + 1,INT_MAX));
        // int sol =  solve(n - 1,amount,coins,dp);
        // if(sol == INT_MAX){
        //     return -1;
        // }
        // return sol;
        vector<ll> last(amount + 1, INT_MAX), curr(amount + 1, INT_MAX);

        for(int i = 0; i <= amount; i++){
            if(i%coins[0] == 0){
                last[i] = i/coins[0]; 
            }
        }

        for(int i = 1; i < n; i++){
            for(int j = 0; j <= amount; j++){
                ll take = INT_MAX;
                ll notTake = last[j];
                if(j >= coins[i]){
                    take = 1 + curr[j - coins[i]];
                }
                curr[j] = min(take,notTake);
            }
            last = curr;
        }
        if(last[amount] == INT_MAX){
            return -1;
        }

        return last[amount];


    }
};