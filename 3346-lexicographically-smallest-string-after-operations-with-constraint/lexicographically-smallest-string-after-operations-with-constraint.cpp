class Solution {
public:
    string getSmallestString(string s, int k) {
        int n = s.size();
        string sol = "";
        for(int i = 0; i < n; i++){
            int num = s[i] - 'a';
            int round1 = s[i] - 'a';
            int round2 = 26 - (s[i] - 'a');
            if(round2 <= k || round1 <=k){
                sol+='a';
                k-=min(round1,round2);
            }
            else{
                sol+= char(s[i] - k);
                k = 0;
            }
        }

        return sol;
    }
};