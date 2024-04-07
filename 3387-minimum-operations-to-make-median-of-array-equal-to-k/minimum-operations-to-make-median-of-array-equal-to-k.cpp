class Solution {
public:
    long long minOperationsToMakeMedianK(vector<int>& nums, int k) {
        int n = nums.size();
        int med =  n/2;
        long long sol = 0;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < n; i++){
            if(i < med){
                if(nums[i] > k){
                    sol+= nums[i] - k;
                }
            }
            if(i == med){
                sol+= abs(nums[i] - k);
            }
            if(i > med){
                if(nums[i] < k){
                    sol+= k - nums[i];
                }
            }
        }


        return sol;
    }
};