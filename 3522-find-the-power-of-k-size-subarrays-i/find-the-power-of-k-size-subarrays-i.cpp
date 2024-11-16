class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> sol(n - k + 1, - 1);
        int j = 0;
        for(int i = 0; i < n; i++){
            if(i != 0 && nums[i] != nums[i - 1] + 1){
                j = i;
            }
            if(i - j + 1 == k){
                sol[i - k + 1] = nums[i];
                j++;
            }
        }   


        return sol; 
    }
};