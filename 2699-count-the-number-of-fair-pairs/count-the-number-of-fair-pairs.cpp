#define ll long long 
class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        ll sol = 0;
        for(int i = 0; i < n; i++){
            ll l = i + 1;
            ll h = n - 1;
            ll small = -1;
            ll large = -1;
            while(l <= h){
                ll m = (l + h)/2;
                if(nums[i] + nums[m] < lower){
                    l = m + 1;
                }
                else{
                    small = m;
                    h = m - 1;
                }
            }
            l = i + 1;
            h = n - 1;
            while(l <= h){
                ll m = (l + h)/2;
                if(nums[i] + nums[m] > upper){
                    h = m - 1;
                }
                else{
                    large = m;
                    l = m + 1;
                }
            }
            if(small != -1 && large != -1) sol+= (large - small + 1);
        }


        return sol;
    }
};