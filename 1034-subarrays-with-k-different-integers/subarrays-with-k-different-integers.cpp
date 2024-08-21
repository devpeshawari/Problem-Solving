class Solution {
public:
    
    int solve(vector<int> &nums, int k){
        int n = nums.size();
        unordered_map<int,int> mp;
        int j = 0;
        int sol = 0;
        for(int i = 0; i < n; i++){
            mp[nums[i]]++;
            
            while(mp.size() > k){
               mp[nums[j]]--;
               if(mp[nums[j]] == 0){
                    mp.erase(nums[j]);
               }
               j++;
            }

            sol+=(i - j + 1);
            
        }



        return sol;
    }
    
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        
        return solve(nums,k) - solve(nums,k - 1);
    }
};