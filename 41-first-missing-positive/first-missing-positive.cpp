class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int sol = 1;
        int j = 0;
        int n = nums.size();

        for(int i = 0; i < n; i++){
            int temp = nums[i];
            while(temp >= 1 && temp <= n && nums[temp - 1] != temp){
                int temp2 = nums[temp - 1];
                nums[temp - 1] = temp;
                temp = -1;
                if(temp2 >= 1 && temp2 <= n){
                    temp = temp2;
                }
            }

            while(sol <= n && nums[sol - 1] == sol){
                sol++;
            }
        }   

        return sol; 
    }
};