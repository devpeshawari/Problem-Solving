class Solution {
public:
    int help(int i, int cond, int count, vector<int> &prices, int k, vector<vector<vector<int>>> &dp){
        int n = prices.size();
        if(dp[i][cond][count] != -1){
            return dp[i][cond][count];
        }
        if(count == k){
            return dp[i][cond][count] = 0;
        }
        if(i == n - 1){
            if(cond == 1){
                return dp[i][cond][count] = 0;
            }
            else{
                return dp[i][cond][count] = prices[i];
            }
        }
        int purchase = INT_MIN; 
        int sell = INT_MIN;
        if(cond == 1){
            int take = -prices[i] + help(i + 1,0,count,prices,k,dp); 
            int notTake = help(i + 1,1,count,prices,k,dp); 

            return dp[i][cond][count] = max(take,notTake);
        }
        
        int take = prices[i] + help(i + 1,1,count + 1,prices,k,dp); 
        int notTake = help(i + 1,0,count,prices,k,dp); 
        return dp[i][cond][count] = max(take,notTake);
        
    }


    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int>(k + 1,-1)));
        return help(0,1,0,prices,k,dp);    
    }
};