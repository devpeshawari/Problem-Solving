class Solution {
public:
    int solve(int i, int j, vector<int> &nums, vector<vector<int>> &dp){
        if(i > j){
            return 0;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int temp = INT_MIN;
        for(int k = i; k <= j; k++){
            int score = nums[k]  * nums[i - 1] * nums[j + 1];
            temp = max(temp,score + solve(i,k - 1,nums,dp) + solve(k + 1,j,nums,dp));
        }

        return dp[i][j] = temp;
    }
    
    
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n + 1,vector<int>(n+ 1,-1));
        vector<int> arr = {};
        arr.push_back(1);
        for(int i = 0; i < n; i++){
            arr.push_back(nums[i]);
        }
        arr.push_back(1);
        return solve(1,n,arr,dp);
    }
};