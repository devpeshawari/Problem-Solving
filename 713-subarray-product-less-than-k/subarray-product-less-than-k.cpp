class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size();
        long long product = 1;
        int j = 0;
        int sol = 0;
        if(k == 0){
            return 0;
        }
        for(int i = 0; i < n; i++){
            product*= nums[i];
            while(product >= k && j <= i){
                product= product / nums[j];
                j++;
            }
            if(j <= i){
                sol +=(sol,i - j + 1);
            }
        }   


        return max(sol,0);  
    }
};