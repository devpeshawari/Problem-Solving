class Solution {
public: 
    
    bool canJump(vector<int>& nums) {
        int n = nums.size(); //number of elements
        if(n == 1){
            return true;
        } 
        int maxJumps = nums[0];
        for(int i = 1; i < n; i++){
            maxJumps--;
            if(maxJumps < 0){
                return false;
            }
            maxJumps = max(maxJumps,nums[i]);
        }


        return true;
    }
};