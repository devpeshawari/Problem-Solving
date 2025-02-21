class Solution {
public:
    bool solve(int i, int j, string &s, string &p, vector<vector<int>> &dp){
        if(i < 0 && j >= 0 && p[j] == '*'){
            for(int k = j; k >= 0; k--){
                if(p[k] != '*') return false;
            }
            return true;
        }
        if(i < 0) return false;
        if(j < 0) return false;
        if(dp[i][j] != -1) return dp[i][j];
        if(i == 0 && j == 0){
            if(p[j] == '?' || p[j] == '*' || s[i] == p[j]){
                return true;
            }
            else{
                return false;
            }
        }
        bool cond1 = false;
        bool cond2 = false;
        if(p[j] == s[i] || p[j] == '?'){
            cond1 = solve(i - 1, j - 1,s,p,dp);
        }
        if(p[j] == '*'){
            cond1 = solve(i - 1, j - 1,s,p,dp);
            cond2 = (solve(i - 1, j,s,p,dp) || solve(i, j - 1,s,p,dp));
        }

        return dp[i][j] = (cond1 || cond2);
    }
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();    
        if(n == 0 && m == 0) return true;  
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return solve(n - 1,m - 1,s,p,dp);    
    }
};