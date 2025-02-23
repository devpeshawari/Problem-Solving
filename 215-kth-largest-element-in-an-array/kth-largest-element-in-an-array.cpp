class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<int,vector<int>,greater<int>> pq;
        int sol = 0;
        for(int i = 0; i < n; i++){
            pq.push(nums[i]);
            if(pq.size() > k) pq.pop();
        }    
        sol = pq.top();
        
        return sol;
    }
};