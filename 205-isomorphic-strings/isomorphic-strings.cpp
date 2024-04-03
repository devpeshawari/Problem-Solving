class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n = s.size();
        unordered_map<char,char> mp;
        unordered_set<char> st;
        for(int i = 0; i < n; i++){
            if(st.find(t[i]) == st.end()){
                if(mp.find(s[i]) == mp.end()){
                    mp[s[i]] = t[i];
                    st.insert(t[i]);
                }
                else{
                    return false;
                }
            }
            else{
                if(mp.find(s[i]) == mp.end()){
                    return false;
                }
                else if(mp[s[i]] != t[i]){
                    return false;
                }
            }
        }


        return true;
    }
};