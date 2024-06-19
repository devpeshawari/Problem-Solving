class Solution {
public:
    int solve(int i, int amount, vector<int> & coins, vector<vector<int>> &dp){
        if(dp[i][amount] != -1){
            return dp[i][amount];
        }
        if(i == 0){
            if(amount%coins[i] == 0){
                return 1;
            }
            else{
                return 0;
            }
        }

        int take = 0;
        int notTake = solve(i - 1, amount, coins, dp);
        if(amount>= coins[i]){
            take = solve(i, amount - coins[i], coins, dp);
        }


        return dp[i][amount] = take + notTake;

    }
    
    
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n,vector<int> (amount + 1, - 1));


        return solve(n - 1, amount, coins, dp);
    }
};