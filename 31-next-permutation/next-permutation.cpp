class Solution {
public:
    /*
      stack: [8, 7, 6, 5,]
      p1 = 2;
      p2 = 4;

        curr el < st.top element

      0 1 2 3 4 5 6 7 8
      ________________
      1 2 4 7 6 5 3 2 1 
      1 2 4 1 2 3 5 6 7 
          i
    */
    bool isDesc(vector<int> &nums){
        int n = nums.size();

        for(int i = 1; i < n; i++){
            if(nums[i] > nums[i - 1]) return false;
        }

        return true;
    }
    
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int p1 = -1;
        int p2 = -1;
        if(isDesc(nums)){
            sort(nums.begin(),nums.end());
            return;
        }
        stack<int> st;

        for(int i = n - 1; i >= 0; i--){
            if(!st.empty() && nums[i] < nums[st.top()]){
                p1 = i;
                while(st.size() && nums[i] < nums[st.top()]){
                    p2 = st.top();
                    st.pop();
                }
                break;
            } 
            st.push(i);
        }
        swap(nums[p1],nums[p2]);
        reverse(nums.begin() + p1 + 1, nums.end());
    }
};