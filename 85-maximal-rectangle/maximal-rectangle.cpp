class Solution {
public:
    vector<int> calcRightMin(vector<int>& arr){
        int n = arr.size();
        stack<int> st;
        vector<int> temp(n);
        for(int i = n - 1; i >= 0; i--){
            while(!st.empty() && arr[st.top()] >= arr[i]){
                st.pop();
            }
            if(st.empty()){
                temp[i] = n - i - 1;
            }
            else{
                temp[i] = st.top() - i - 1;
            }

            st.push(i);

        }

        return temp;
    }

    vector<int> calcLeftMin(vector<int>& arr){
        int n = arr.size();
        stack<int> st;
        vector<int> temp(n);
        for(int i = 0; i < n; i++){
            while(!st.empty() && arr[st.top()] >= arr[i]){
                st.pop();
            }
            if(st.empty()){
                temp[i] = i;
            }
            else{
                temp[i] = i - st.top() - 1;
            }

            st.push(i);

        }

        return temp;
    }
    
    
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> temp(m);
        int sol = 0;
        vector<int> last(m,0); 
        for(int i = 0; i < n; i++){
            vector<int> curr(m,0);
            for(int j = 0; j < m; j++){
                if(matrix[i][j] == '1'){
                    curr[j] = last[j] + 1;
                }
                else{
                    curr[j] = 0;
                }
            }
            vector<int> left_arr = calcLeftMin(curr);
            vector<int> right_arr = calcRightMin(curr);

            for(int j = 0; j < m; j++){
                sol = max(sol,(curr[j] * (left_arr[j] + right_arr[j] + 1)));
            }

            for(int j = 0; j < m; j++){
                last[j] = curr[j];
            }
        }

        return sol;    
    }   
};  