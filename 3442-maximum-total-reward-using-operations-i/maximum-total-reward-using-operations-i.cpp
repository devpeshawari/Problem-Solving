class Solution {
public:
    int solve(int i, int W, vector<int> &rewardValues, int total, vector<vector<int>> &dp){
        if(dp[i][W] != -1){
            return dp[i][W];
        }
        
        if(i == 0){
            if(W < rewardValues[i]){
                return dp[i][W] = rewardValues[i];
            }
            else{
                return  dp[i][W] = 0;
            }
        }

        int take = INT_MIN;
        if(W < rewardValues[i]){
            if(W + rewardValues[i] >= total){
                return dp[i][W] = rewardValues[i];
            }
            take = rewardValues[i] + solve(i - 1, W + rewardValues[i], rewardValues,total, dp);    
        }
        int notTake = solve(i - 1, W, rewardValues,total, dp);


        return dp[i][W] = max(take,notTake);
    }
    
   
    int maxTotalReward(vector<int>& rewardValues) {
        sort(rewardValues.begin(),rewardValues.end(),greater<int>());
        int n = rewardValues.size();
        int total = INT_MIN;

        for(int i = 0 ; i < n; i++){
            total = max(total, rewardValues[i]);
        }

        vector<vector<int>> dp(n,vector<int>(total + 1, -1));
        int sol = solve(n - 1,0,rewardValues, total + 1,dp);

        return sol;

    }
};