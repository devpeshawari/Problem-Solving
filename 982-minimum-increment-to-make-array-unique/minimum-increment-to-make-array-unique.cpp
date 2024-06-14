class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        int sol = 0;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int maxNum = nums[0];
        for(int i = 1; i < n; i++){
            if(nums[i] <= maxNum){
                maxNum++;
                sol+=(maxNum - nums[i]);
            }
            else{
                maxNum = max(maxNum,nums[i]);
            }
        }
                                                    
        return sol; 
    }
};