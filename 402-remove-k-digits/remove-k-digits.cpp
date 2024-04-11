class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size();
        stack<int> st;
        if(k == n){
            return "0";
        }

        for(int i = 0; i < n; i++){
            while(!st.empty() && num[st.top()] > num[i] && k > 0){
                st.pop();
                k--;
            }

            st.push(i);            
        }

        while(!st.empty() && k){
            st.pop();
            k--;
        }
        string sol = "";
        vector<int> temp;
        while(!st.empty()){
            temp.push_back(st.top());
            st.pop();
        }
        for(int i = temp.size() - 1; i >= 0; i--){
            sol+=num[temp[i]];
        }

        while(sol.size() > 0 && sol[0] == '0'){
            sol.erase(sol.begin());
        }

        if(sol.size() == 0){
            return "0";
        }


        return sol;
    }
};