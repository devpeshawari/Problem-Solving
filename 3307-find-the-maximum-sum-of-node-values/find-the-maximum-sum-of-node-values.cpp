#define ll long long 
class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        int n = nums.size();
        ll sol = 0;

        for(int i = 0; i < n; i++){
            sol+= nums[i];
        }
        ll minIncrease = INT_MAX;
        ll minDecrease = INT_MAX;
        ll temp = 0;
        int count = 0;
        for(int i = 0; i < n; i++){
            ll xorDiff = (nums[i]^k) - nums[i];
            if(xorDiff >= 0){
                minIncrease = min(minIncrease,xorDiff);
                temp+=xorDiff;
                count++;
            }
            else{
                minDecrease = min(minDecrease,abs(xorDiff));
            }
        }


        if(!(count & 1)){
            return sol + temp;
        }

        return max(sol + temp - minIncrease,sol + temp - minDecrease);
    }
};