class Solution {
public:
    
    // 1 3 2
    // 1 2 3 1
    // 1 2 3 5 6 4
    bool checkNonIncreasing(vector<int> &nums){
        int n = nums.size();
        for(int i = 1; i < n; i++){
            if(nums[i] > nums[i - 1]) return false;
        }

        return true;
    }
    
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        if(checkNonIncreasing(nums) || n == 1){
            reverse(nums.begin(), nums.end()); 
            return;
        }
        int pivot1 = -1;
        int pivot2 = -1;
        stack<int> st;

        st.push(n - 1);

        for(int i = n - 2; i >= 0; i--){
            if(nums[i] < nums[st.top()]){
                pivot1 = i;
                pivot2 = st.top();
                while(!st.empty() && nums[i] < nums[st.top()]){
                    pivot2 = st.top();
                    st.pop();
                }
                break;
            }
            st.push(i);
        }
        cout << pivot1;
        swap(nums[pivot1],nums[pivot2]);
        reverse(nums.begin() + pivot1 + 1,nums.end());
    }   
};