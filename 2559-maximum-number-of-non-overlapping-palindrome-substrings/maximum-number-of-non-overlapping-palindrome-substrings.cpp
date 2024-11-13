class Solution {
public:
    
    bool isPalindrome(string &s, int start, int end){
        int n = s.size();

        for(int i = start; i <= end; i++){
            if(s[i] != s[end -  (i - start)]) return false;
        }

        return true;
    }

    int solve(int i, int k, string &s, vector<int> &dp, vector<vector<int>> &checkPalindrome){
        int n = s.size();
        if(i + k > n) return 0;
        if(dp[i] != INT_MAX) return dp[i];
        int temp = 0;
        for(int j = i; j < n; j++){
            if(j - i + 1 >= k && checkPalindrome[i][j]){
                temp = max(temp,1 + solve(j + 1,k,s,dp,checkPalindrome));
            }
            temp = max(temp,solve(j + 1,k,s,dp,checkPalindrome));

        }

        return dp[i] = temp;
    }
    
    int maxPalindromes(string s, int k) {
        int n = s.size();
        int sol = 0;
        vector<int> dp(n,INT_MAX);
        vector<vector<int>> checkPalindrome(n,vector<int>(n,0));
        for(int i = 0; i < n; i++){
            checkPalindrome[i][i] = 1;
        }
        for (int j = 2; j <= n; j++) {
            for (int i = 0; i <= n - j; i++) {
                int k = i + j - 1;
                if(j == 2){
                    if (s[i] == s[k]) {
                        checkPalindrome[i][k] = 1;
                    }
                }
                if (s[i] == s[k] && checkPalindrome[i + 1][k - 1]) {
                    checkPalindrome[i][k] = 1;
                }
            }
        }
        sol = solve(0,k,s,dp,checkPalindrome);
        

        return sol;
    }
};