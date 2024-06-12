# define ll long long
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>> sol;
        for(int i = 0; i < n - 3; i++){
            if((i != 0) && (nums[i] == nums[i - 1])){
                continue;
            }
            for(int j = i + 1; j < n; j++){
                if((j != i + 1) && (nums[j] == nums[j - 1])){
                    continue;
                }
                int k = j + 1;
                int l = n - 1;

                while(k < l){
                    long long diff = target - (ll)(nums[i]) - (ll)(nums[j]) - (ll)(nums[k]) - (ll)(nums[l]);
                    
                    if(diff == 0){
                        sol.push_back({nums[i], nums[j], nums[k], nums[l]});
                    }

                    if(diff > 0){
                        k++;
                        while(k < l && nums[k] == nums[k - 1]){
                            k++;
                        }
                    }
                    else{
                        l--;
                        while(k < l && nums[l] == nums[l + 1]){
                            l--;
                        }
                    }
                }
            }
        }

        return sol;
    }
};