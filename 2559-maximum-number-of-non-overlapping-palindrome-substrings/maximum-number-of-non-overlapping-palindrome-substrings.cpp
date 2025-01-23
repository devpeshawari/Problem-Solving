class Solution {
public:
    int solve(int i, string &s, int k, vector<vector<int>> &isPalindrome,vector<int> &dp){
        int n = s.size();
        int sol = 0;
        int temp = 0;
        if(i > n - k){
            return 0;
        }
        if(dp[i] != INT_MAX) return dp[i];
        if(i == n - k){
            if(isPalindrome[i][n - 1]){
                return 1;
            }
            else{
                return 0;
            }
        }

        for(int ind = i; ind < n; ind++){
            if((ind - i + 1 >= k) && isPalindrome[i][ind]){
                temp = max(temp,1 + solve(ind + 1,s,k,isPalindrome,dp));    
            }
            temp = max(temp,solve(ind + 1,s,k,isPalindrome,dp));
            
            
        }
        
        return dp[i] = temp;

    }
    
    
    int maxPalindromes(string s, int k) {
        int n = s.size();
        vector<vector<int>> dp(n,vector<int>(n,0));
        vector<int> dp2(n,INT_MAX);
        for(int i = 0; i < n; i++){
            dp[i][i] = 1;
        }

        for(int i = 0; i < n - 1; i++){
            if(s[i] == s[i + 1])dp[i][i + 1] = 1;
        }
        
        for(int len = 3; len <= n; len++){
            for(int i = 0; i <= n - len; i++){
                if(s[i] == s[i + len - 1] && dp[i + 1][i + len - 2] == 1) dp[i][i + len - 1] = 1;
            }
        }
        
        int sol = solve(0,s,k,dp,dp2);
        
        return sol;
    }
};