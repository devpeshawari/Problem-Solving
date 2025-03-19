class Solution {
public:
    bool check(int index, int k, vector<int> &nums){
        int n = nums.size();
        int threshold = nums[index];
        cout << threshold << "\n";
        cout << index << "\n";
        int count = 0;
        int temp = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] <= threshold){
                temp++;
            }
            else{
                count += (temp/2 + temp%2);
                temp = 0;
            }
        }
        count += (temp/2 + temp%2);
        temp = 0;
        // for(int i = index + 2; i < n; i++){
        //     if(nums[i] <= threshold){
        //         temp++;
        //     }
        //     else{
        //         count += temp/2 + temp%2;
        //         temp = 0;
        //     }
        // }
        // count += temp/2 + temp%2;
        // temp = 0;

        if(count >=k) return true;
        return false;
    }
    
    
    int minCapability(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<int>> sortedArr(n);

        for(int i = 0; i < n; i++){
            sortedArr[i] = {nums[i],i};
        }
        
        sort(sortedArr.begin(),sortedArr.end());
        int l = 0;
        int h = n - 1;
        int sol = sortedArr[h][0];
        while(l <= h){
            int m = (l + h)/2;
            if(check(sortedArr[m][1],k,nums)){
                
                sol = sortedArr[m][0];
                h = m - 1;
            }
            else{
                l = m + 1;
            }
        }
        
        return sol;

    }
};