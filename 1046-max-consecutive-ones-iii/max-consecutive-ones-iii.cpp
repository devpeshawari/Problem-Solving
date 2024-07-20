class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();    
        int j = 0;
        int sol = 0;
        int count = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] == 0){
                count++;
            }
            if(count > k){
                while(j < n && nums[j] != nums[i]){
                    j++;
                }
                j++;
                count--;
            }
            sol = max(sol,i - j + 1);
        }


        return sol;
    }
};