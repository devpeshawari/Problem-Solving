class Solution {
public:
    bool divideArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> mp(501,0);

        for(int i = 0; i < n; i++){
            mp[nums[i]]++;
        }   

        for(auto it: mp){
            if(it%2 == 1) return false;
        }

        return true; 
    }
};