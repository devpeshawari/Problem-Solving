class Solution {
public:
    int help(vector<int> &nums, int k){
        int n = nums.size();
        int j = 0;
        int sum = 0;
        int sol = 0;
        if(k < 0){
            return 0;
        }
        for(int i = 0; i < n; i++){
            sum+= nums[i];
            while(sum > k){
                sum-=nums[j];
                j++;
            }
            sol+=(i - j + 1);
        }

        return sol;
    }
    
    
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return help(nums,goal) - help(nums,goal - 1);
    }
};