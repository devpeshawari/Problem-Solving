class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int n = words.size();
        int sol = 0;
        int m = pref.size();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < words[i].size(); j++){
                if(j == m - 1 && pref[j] == words[i][j]){
                    sol++;
                    break;
                }
                if(pref[j] != words[i][j]) break;
            }    
        }   

        return sol; 
    }
};