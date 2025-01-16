class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        unordered_set<int> mp;
        vector<int> sol;
        int n = nums.size();
        
        for(int i = 0; i < n; i++){
            int absVal = abs(nums[i]);
            if(nums[absVal - 1] < 0){
                mp.insert(absVal);
            }
            nums[absVal - 1] = -nums[absVal - 1];
        }

        for(auto it: mp){
            sol.push_back(it);
        }
        return sol;
    }
};