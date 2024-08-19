class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int last = nums[0];
        int ptr = 1;
        for(int i = 1; i < n; i++){
            if(last != nums[i]){
                nums[ptr] = nums[i];
                ptr++;
            }
            last = nums[i];
        }

        return ptr;
    }
};