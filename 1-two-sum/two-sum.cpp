class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> arr;
        for(int i = 0; i < n; i++){
            arr.push_back({nums[i],i});
        } 
        sort(arr.begin(), arr.end());
        int j = n - 1;
        int i = 0;
        while(i < j){
            int diff = target - arr[i][0] - arr[j][0];
            if(diff == 0){
                return{arr[i][1],arr[j][1]};
            }
            if(diff > 0){
                i++;
            }
            else{
                j--;
            }
        }

        return {-1,-1};
    }
};