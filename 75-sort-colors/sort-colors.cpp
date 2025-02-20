class Solution {
public:

    void sortColors(vector<int>& nums) {
        int zeroCount = 0;
        int oneCount = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            if(nums[i] == 0) zeroCount++;
            if(nums[i] == 1) oneCount++;
        }   

        for(int i = 0; i < n; i++){
            if(zeroCount){
                nums[i] = 0;
                zeroCount--;
            }
            else if(oneCount){
                nums[i] = 1;
                oneCount--;
            }
            else{
                nums[i] = 2;
            }
        }
    }
};