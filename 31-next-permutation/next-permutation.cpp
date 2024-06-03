class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int p = -1;
        int p2 = -1;
        if(n == 1){
            return;
        }
        stack<int> st; 
        for(int i = n - 1; i >= 0; i--){
            if(!st.empty() && nums[i] < nums[st.top()]){
                p = i;
                while(!st.empty() && nums[i] < nums[st.top()]){
                    p2 = st.top();
                    st.pop();
                }
                break;
            }
            st.push(i);
        }
        while(st.size()){
            cout << 1 << " ";
            st.pop();
        }
        if(p != -1){
        swap(nums[p], nums[p2]);
        reverse(nums.begin() + p + 1, nums.end());
        }


        if(p == -1){
            reverse(nums.begin(),nums.end());
        }
    }
};