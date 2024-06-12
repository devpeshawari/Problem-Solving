class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        int i = 0; 
        sort(nums.begin(), nums.end());
        vector<vector<int>> sol;
        for(int i = 0; i < n - 2; i++){
            if(i != 0 && nums[i] == nums[i - 1]){
                continue;
            }
            int j = i + 1;
            int k = n - 1;
            
            while(j < k){
                int sum = nums[i] + nums[j] + nums[k];
                
                if(sum == 0){
                    sol.push_back({nums[i], nums[j], nums[k]});
                }
                
                if(sum >= 0){
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