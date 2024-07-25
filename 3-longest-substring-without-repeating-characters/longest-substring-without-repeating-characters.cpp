class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        //sol = 3
        //temp = 0
        //i = 1
        //j = 1 
        //[]
        
        int sol = 0;
        int n = s.size();
        for(int i = 0; i < n; i++){
            unordered_set<char> mp;
            for(int j = i; j < n; j++){
                if(mp.find(s[j]) != mp.end()){
                    break;
                }
                sol = max(sol, j - i + 1);
                mp.insert(s[j]);
            }
        }

        return sol;

    }
};