class Solution {
public:
    int help(int i, int j, vector<int> &cuts, vector<vector<int>> &dp){
        if(i > j){
            return 0;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int sol = INT_MAX;
        int length = cuts[j + 1] - cuts[i - 1];
        for(int k = i; k <= j; k++){    
            int temp = length + help(i,k - 1,cuts,dp) + help(k + 1,j,cuts, dp); 
            sol = min(temp,sol);
        }


        return dp[i][j] = sol;
    }
    
    
    int minCost(int n, vector<int>& cuts) {
        int m = cuts.size();
        vector<vector<int>> dp(m + 1,vector<int>(m + 1, - 1));
        sort(cuts.begin(), cuts.end());
        cuts.insert(cuts.begin(),0);
        cuts.push_back(n);
        return help(1,m,cuts,dp);
    }
};