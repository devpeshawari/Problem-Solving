class Solution {
public:
    int appendCharacters(string s, string t) {
        int n = s.size();
        int n1 = t.size();
        int j = 0;

        for(int i = 0; i < n; i++){
            if(j == n1){
                return 0;
            }
            if(s[i] == t[j]){
                j++;
            }
        }


        return n1 - j;
    }
};