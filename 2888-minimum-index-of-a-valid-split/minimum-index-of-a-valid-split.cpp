class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int n = nums.size();
        int num = nums[0];
        int count = 1;
        for(int i = 1; i < n; i++){
            if(nums[i] == num) count++;
            else count--;
            if(count < 0){
                num = nums[i];
                count = 1;
            }
        }
        int total = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] == num) total++;
        }
        count = 0;
        cout << num;
        for(int i = 0; i < n - 1; i++){
            if(nums[i] == num) count++;
            int remaining = total - count;
            int size1 = i + 1;
            int size2 = n - i - 1;
            if(count > size1/2 && remaining > size2/2) return i; 
        }


        return -1;
    }
};