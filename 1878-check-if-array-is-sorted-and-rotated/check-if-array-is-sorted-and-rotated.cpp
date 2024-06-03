class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        int pivot = 0; 
        for(int i = 1; i < n; i++){
            if(nums[i] < nums[i - 1]){
                pivot = i;
            }
        }

        for(int i = 1; i < n; i++){
            if(nums[(pivot + i)%n] < nums[(pivot + i - 1)%n] ){
                return false;
            }
        }


        return true;
    }
};