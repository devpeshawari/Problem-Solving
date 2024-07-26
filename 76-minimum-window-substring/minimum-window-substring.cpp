class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        int m = t.size();
        unordered_map<char,int> mp;
        string sol = "";
        int j = 0;
        for(int i = 0; i < m; i++){
            mp[t[i]]++;
        }    
        int a = -1;
        int len = n;
        int count = mp.size();
        for(int i = 0; i < n; i++){
            if(mp.find(s[i]) != mp.end()){
                mp[s[i]]--;
                if(mp[s[i]] == 0){
                    count--;
                }
            }
            if(count == 0){
                while(true){
                    if(a == -1){
                        len = i - j + 1;
                        a = j;
                    }
                    else{
                        if(i - j + 1 < len){
                            a = j;
                            len = i - j + 1;     
                        }
                    }
                    if(mp.find(s[j]) != mp.end()){
                        mp[s[j]]++;
                        if(mp[s[j]] == 1){
                            count++;
                            j++;
                            break;
                        }
                    }
                    j++;
                }
            }
        }
        if(a == -1){
            return "";
        }
        sol = s.substr(a,len);
        return sol;
    }
};