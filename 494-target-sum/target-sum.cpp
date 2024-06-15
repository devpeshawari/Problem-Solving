class Solution {
public:
    int solve(int i, int target, vector<int> & nums,vector<vector<int>> &dpPos, vector<vector<int>> &dpNeg){
        if(target >= 0){
            if(dpPos[i][target] != -1){
                return dpPos[i][target];
            }
        }
        else{
            if(dpNeg[i][-target] != -1){
                return dpNeg[i][-target];
            }
        }
        if(i == 0){
            if((target - nums[i] == 0)  && (target + nums[i] == 0)){
                return 2;
            }
            if((target - nums[i] == 0)  || (target + nums[i] == 0)){
                return 1;
            }
            else{
                return 0;
            }
        }
        int pos = solve(i - 1,target - nums[i], nums, dpPos, dpNeg);
        int neg = solve(i - 1,target + nums[i], nums, dpPos, dpNeg);
        if(target >= 0){
            return dpPos[i][target] = pos + neg;
        }
        else{
            return dpNeg[i][-target] = pos + neg;
        }
        
    }
    
    
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int sum = 0;
        int total = 0;
        for(int i = 0; i < n; i++){
            sum+=nums[i];
        }
        vector<vector<int>> dpPos;
        vector<vector<int>> dpNeg;
        if(target + sum >= 0){
            dpPos.resize(n,vector<int>(target + sum + 1,-1));      
        }
        if(target - sum < 0){
            dpNeg.resize(n,vector<int>(abs(target - sum - 1),-1));      
        }
        
        return solve(n - 1, target, nums, dpPos, dpNeg);
    }
};