class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> sol;
        sort(nums.begin(),nums.end());
        for(int i = 0; i < n; i++){
            if(i > 0 && nums[i] == nums[i - 1]) continue;
            int j = i + 1;
            int k = n - 1;
            while(j < k){
                if(nums[i] + nums[j] + nums[k] == 0){
                    sol.push_back({nums[i],nums[j],nums[k]});
                    j++;
                    while(j < k && nums[j] == nums[j - 1]){
                        j++;
                    }
                }
                else if(nums[i] + nums[j] + nums[k] > 0){
                    k--;
                    while(j < k && nums[k] == nums[k + 1]){
                        k--;
                    }
                }
                else{
                    j++;
                    while(j < k && nums[j] == nums[j - 1]){
                        j++;
                    }
                }
            }
        }



        return sol;    
    }
};