class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sol = INT_MIN;
        int sum = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            sum+=nums[i];
            sol = max(sum,sol);
            sum = max(sum,0);
        }

        return sol;


        return sol;     
    }
};