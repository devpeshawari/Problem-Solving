class Solution {
public:
    int numberOfSubstrings(string s) {
        int a = -1;
        int b = -1;
        int c = -1;
        int sol  = 0;
        int n = s.size();
        for(int i = 0; i < n; i++){
            if(s[i] == 'a'){
                a = i;
            }
            if(s[i] == 'b'){
                b = i;
            }
            if(s[i] == 'c'){
                c = i;
            }
            int temp = min(a,b);
            temp = min(temp,c);
            sol += temp + 1;
        }


        return sol;
    }
};