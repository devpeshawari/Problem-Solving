class Solution {
public:
    bool cond(int m, int k, vector<int> &nums){
        int n = nums.size();
        int split = 1;
        int total = 0;
        for(int i = 0; i < n; i++){
            total+=nums[i];
            if(total > m){
                total = nums[i];
                split++;
            }
        }
        if(split <= k){
            return true;
        }

        return false;
    }
    
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        int total = 0;
        for(int i = 0; i < n; i++){
            total+=nums[i];
        }
        int l = *max_element(nums.begin(), nums.end());
        int h = total;
        int sol = h;
        while(l <= h){
            int m = (l + h)/2;
            if(cond(m,k,nums)){
                sol = m;
                h = m - 1;
            } 
            else{
                l = m + 1;
            }
        }

        return sol;
    }
};