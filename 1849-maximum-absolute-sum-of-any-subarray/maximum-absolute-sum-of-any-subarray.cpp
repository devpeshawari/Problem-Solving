class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int n = nums.size();
        int currSum = 0;
        int maxPositive = 0;
        int maxNegative = 0;
        int sol = 0;
        for(int i = 0; i < n; i++){
            currSum+=nums[i];
            if(currSum > 0){
                sol = max(sol,abs(currSum) + maxNegative);
                maxPositive = max(maxPositive,currSum);
            } 
            else{
                sol = max(sol,abs(currSum) + maxPositive);
                maxNegative = max(maxNegative,abs(currSum));
            }
        }

        return sol;
    }
};