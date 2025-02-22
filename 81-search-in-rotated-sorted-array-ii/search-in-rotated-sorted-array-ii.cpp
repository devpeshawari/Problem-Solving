class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int lower = 0;
        int n = nums.size();
        for(int i = 1; i < n; i++){
            if(nums[i] < nums[i - 1]){
                lower = i;
            }
        }
        int higher = lower + n - 1;

        while(lower <= higher){
            int mid = (lower + higher)/2;
            int index = mid%n;
            if(nums[index] == target){
                return true;
            }
            else if(nums[index] > target){
                higher = mid - 1;
            }
            else{
                lower = mid + 1;
            }
        }


        return false;
    }
};