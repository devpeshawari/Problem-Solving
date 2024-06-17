class Solution {
public:
    int solve(int i,int target, vector<int> &nums, vector<vector<int>> &dp){
        
        if(i == 0){
            if(target - nums[0] == 0 || target == 0){
                return 1;
            }
            else{
                return 0;
            }
        }
        if(dp[i][target] != -1){
            return dp[i][target];
        }
        int take = 0;
        int notTake = solve(i - 1, target, nums, dp);
        if(target >= nums[i]) take = solve(i - 1, target - nums[i], nums, dp);
        

        return dp[i][target] = (take || notTake);
    }
    
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int target = 0;
        
        for(int i = 0; i < n; i++){
            target += nums[i];
        }    
        if(target%2 != 0){
            return false;
        }
        target = target/2; 
        vector<vector<int>> dp(n, vector<int>(target + 1, - 1));

        return solve(n - 1, target, nums, dp);
    }
};