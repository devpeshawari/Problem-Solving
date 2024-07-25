class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        // a b c a
        int n = s.size();
        int sol = 0;
        int j = 0;
        unordered_set<char> mp;
        for(int i = 0; i < n; i++){
            if(mp.find(s[i]) != mp.end()){
                while(s[j] != s[i]){
                    mp.erase(s[j]);
                    j++;
                }
                j++;
            }
            mp.insert(s[i]);
            sol = max(sol,i - j +  1);
        }

        return sol;

    }
};