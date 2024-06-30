class Solution {
public:

    
    int maximumLength(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(k,1));
        if(n == 2){
            return 2;
        }
        for(int i = 0; i < k; i++){
            dp[0][i] = 1;
        }        

        for(int i = 1; i < n; i++){
            for(int j = 0; j < i; j++){
                int rem = (nums[i] + nums[j])%k;
                dp[i][rem] = max(1 + dp[j][rem],dp[i][rem]);
            }
        }
        int sol = 2;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < k; j++){
                sol = max(sol,dp[i][j]);
            }
        }

        return sol;
    }
};