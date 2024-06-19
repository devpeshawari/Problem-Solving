class Solution {
public:
    int solve(int i, int sum, int target, int total, vector<int> &nums, vector<vector<int>> &dp){
        if(sum >= 0){
            if(dp[i][sum] != -1){
                return dp[i][sum];
            }
        }
        else{
             if(dp[i][total + abs(sum)] != -1){
                return dp[i][total + abs(sum)];
             }
        }
        if(i == 0){
            if(sum - nums[0] == target && sum + nums[0] == target){
                return 2;
            }
            else if(sum - nums[0] == target || sum + nums[0] == target){
                return 1;
            }
            else{
                return 0;
            }
        }

        int plus = solve(i - 1, sum + nums[i], target, total, nums, dp);
        int minus = solve(i - 1, sum - nums[i], target, total, nums, dp);

        if(sum >= 0){
            dp[i][sum] = plus + minus;
        }
        else{
            dp[i][total + abs(sum)] = plus + minus;
        }
        return plus + minus;

    }
    
    
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int total = 0;
        
        for(int i = 0; i < n; i++){
            total+= nums[i];
        }

        vector<vector<int>> dp(n,vector<int>((total * 2) + 2, -1));

        


        return solve(n - 1,0, target, total, nums, dp);
    }
};