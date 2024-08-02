class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int k = 0;
        int n = nums.size();
        int sol = 0;
        int j = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] == 1){
                k++;
            }
        }
        if(k == 1 || k == 0){
            return 0;
        }
        int maxNum = 0;
        int cnt = 0;
        for(int i = 0; i < n + k; i++){
            cnt+= nums[i%n];
            if(i >= k){
                cnt-=nums[j];
                j = (j + 1)%n;
            }
            maxNum = max(cnt,maxNum);
        }   


        return k - maxNum;

    }
};