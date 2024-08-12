class Solution {
public:
    // [1 2 3 4 5] k = 2
    // [4 5 1 2 3]
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> first;
        vector<int> second;
        k = k%n;
        if(k == 0){
            return;
        }
        for(int i = n - k; i < n; i++){
            first.push_back(nums[i]);
        }

        for(int i = 0; i < n - k + 1; i++){
            second.push_back(nums[i]);
        }
        
        for(int i = 0; i < k; i++){
            nums[i] = first[i];
        }
        for(int i = k; i < n; i++){
            nums[i] =  second[i - k];
        }
    }
};