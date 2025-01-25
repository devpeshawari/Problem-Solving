class Solution {
public:
    bool solve(int i, int j, string &s, string &p){
        int n = s.size();
        int m = p.size();
        
        if(j < 0) return false;
        if(j == 1 && p[j] == '*' && i == -1) {
            return true;
        }
        
        if(i == 0 && j == 0){   
            if(p[0] == '.' || p[0] == s[0]) return true;
            else return false;    
        };

        if(i < 0 && p[j] != '*') return false;
        
        
        if(p[j] == '.'){
            if(solve(i - 1,j - 1,s,p)) return true;
        }
        else if(p[j] == '*'){
            cout << j << " ";
            if(solve(i,j-2,s,p)) return true;
            if(i >= 0 && (p[j - 1] == s[i] || p[j - 1] == '.')){
                if(solve(i - 1,j,s,p)) return true;
            }
        }
        else{
            if(p[j] == s[i]){
                if(solve(i - 1,j - 1,s,p)) return true;
            } 
        }
        
        return false;
    }
    
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        string pattern = ""; 
        int j = 0;
        while(j < m){
            if(j == '*'){
                while(j < m && p[j] == '*') j++;
                pattern.push_back('*');
            }
            else{
                pattern.push_back(p[j]);
                j++;
            }
        }
        // cout << pattern;
        bool sol = solve(n - 1,m - 1,s,p);
        return sol;
         
    }
};