class Solution {
public:
    

    int partitionString(string s) {
        int n = s.size();
        int j = 0;
        int sol = 1;
        unordered_set<char> mp;
        for(int i = 0; i < n; i++){
            if(mp.find(s[i]) != mp.end()){
                sol++;
                mp.clear();
            }
            mp.insert(s[i]);
        }


        return sol;
    }
};