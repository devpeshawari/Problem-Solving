#define ll long long 
class Solution {
public:
    long long solve(int index, vector<int> &nums, int valid, int k, vector<vector<ll>> &dp){
        int n = nums.size();
        if(index >= n){
            if(!valid){
                return 0;
            }
            else{
                return INT_MIN;
            }
        }
        if(dp[index][valid] != -1){
            return dp[index][valid];
        }
        ll take = (nums[index]^k) + solve(index + 1, nums, (valid + 1)%2, k, dp);
        ll not_take = nums[index] + solve(index + 1, nums, valid%2, k, dp);


        return dp[index][valid] = max(take,not_take);

    }

    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        int n = nums.size();
        // ll sol = 0;

        // for(int i = 0; i < n; i++){
        //     sol+= nums[i];
        // }
        // ll minIncrease = INT_MAX;
        // ll minDecrease = INT_MAX;
        // ll temp = 0;
        // int count = 0;
        // for(int i = 0; i < n; i++){
        //     ll xorDiff = (nums[i]^k) - nums[i];
        //     if(xorDiff >= 0){
        //         minIncrease = min(minIncrease,xorDiff);
        //         temp+=xorDiff;
        //         count++;
        //     }
        //     else{
        //         minDecrease = min(minDecrease,abs(xorDiff));
        //     }
        // }


        // if(!(count & 1)){
        //     return sol + temp;
        // }

        // return max(sol + temp - minIncrease,sol + temp - minDecrease);
        vector<vector<ll>> dp(n,vector<ll> (2,-1));
        return solve(0,nums,0,k,dp);
    }
};