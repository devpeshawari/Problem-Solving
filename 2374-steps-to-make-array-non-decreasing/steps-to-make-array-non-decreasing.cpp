class Solution {
public:
    int totalSteps(vector<int>& nums) {
        int n = nums.size();
        stack<pair<int,int>> st;
        int sol = 0;
        for(int i = n - 1; i >= 0; i--){
            int temp = 0;
            while(!st.empty() && st.top().first < nums[i]){
                temp = max(temp + 1,st.top().second);
                st.pop();
            }
            sol = max(temp,sol);
            st.push({nums[i],temp});
        }

        return sol;
    }
};