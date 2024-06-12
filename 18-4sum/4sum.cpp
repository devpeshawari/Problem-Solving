class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> sol;
        int n = nums.size();
        if(n < 4){
            return {};
        }
        int last = INT_MAX;
        for(int i = 0; i < n; i++){
            if(nums[i] == last) continue;
            int l = i + 1;
            if(l >= n) continue;
            while(l < n){
                 int last1 = nums[l];
                 int j = l + 1; 
                 int k = n - 1;
                while(j < k){
                    long long sum = (long long)(nums[i]) + (long long)(nums[l]) + (long long)(nums[j]) + (long long)(nums[k]);
                    if(sum == target){
                        sol.push_back({nums[i],nums[l],nums[j],nums[k]});
                        j++;
                        while(j < n && nums[j] == nums[j -1]){
                            j++;
                        }
                        k--;
                        while(k >= 0 && nums[k] == nums[k + 1]){
                            k--;
                        }
                    }
                    else if(sum < target){
                        j++;
                        while(j < n && nums[j] == nums[j -1]){
                            j++;
                        }
                    }
                    else{
                        k--;
                        while(k >= 0 && nums[k] == nums[k + 1]){
                            k--;
                        }
                    }
                    
                }
                l++;
                while(l < n && nums[l] == last1){
                    nums[l] = last1;
                    l++; 
                }

                
            }

            last = nums[i];
        }
        return sol;
    }
};