class Solution {
public:
    int solve(int i, int amount, vector<int> &coins, vector<vector<int>> &dp){
        if(amount == 0){
            return 0;
        }
        if(i == 0){
            if(amount%coins[0] == 0){
                return amount/coins[0];
            }
            else{
                return INT_MAX;
            }
        }
        int take = INT_MAX;
        int notTake = solve(i - 1, amount, coins, dp);
        if(amount >= coins[i]){
            take = 1 + solve(i, amount - coins[i], coins, dp);
        }

        return min(take, notTake);
    }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<long long>> dp(n,vector<long long> (amount + 1, INT_MAX));
        
        for(int i = 0; i < n; i++){
            dp[i][0] = 0;
        }
        
        for(int i = 0; i <= amount; i++){
            if(i%coins[0] == 0){
                dp[0][i] = i/coins[0];
            }
        }

        for(int i  = 1; i < n; i++){
            for(int j = 0; j <= amount; j++){
                long long take = INT_MAX;
                long long notTake = dp[i - 1][j];
                if(j >= coins[i]){
                    take = 1 + dp[i][j - coins[i]];
                }
                dp[i][j] = min(take,notTake);
            }
        }

        int sol = dp[n - 1][amount];

        if(sol == INT_MAX){
            return -1;
        }
        return sol;
    }
};