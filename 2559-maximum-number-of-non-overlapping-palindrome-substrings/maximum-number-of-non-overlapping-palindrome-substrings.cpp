class Solution {
public:
    
    // Helper function to precompute all palindromic substrings
    void precomputePalindromes(string &s, vector<vector<int>> &checkPalindrome) {
        int n = s.size();
        
        // Single-character palindromic substrings
        for (int i = 0; i < n; ++i) {
            checkPalindrome[i][i] = 1;
        }

        // Two-character palindromic substrings
        for (int i = 0; i < n - 1; ++i) {
            if (s[i] == s[i + 1]) {
                checkPalindrome[i][i + 1] = 1;
            }
        }

        // Palindromic substrings of length > 2
        for (int len = 3; len <= n; ++len) {
            for (int i = 0; i <= n - len; ++i) {
                int j = i + len - 1;
                if (s[i] == s[j] && checkPalindrome[i + 1][j - 1]) {
                    checkPalindrome[i][j] = 1;
                }
            }
        }
    }

    // Recursive function with memoization to find the max number of palindromic substrings
    int solve(int i, int k, string &s, vector<int> &dp, vector<vector<int>> &checkPalindrome) {
        int n = s.size();
        if (i >= n) return 0;
        if (dp[i] != INT_MAX) return dp[i];
        
        int maxPalindromes = 0;
        for (int j = i; j < n; ++j) {
            // Check if substring s[i:j+1] is a palindrome and of sufficient length
            if (j - i + 1 >= k && checkPalindrome[i][j]) {
                maxPalindromes = max(maxPalindromes, 1 + solve(j + 1, k, s, dp, checkPalindrome));
                break;  // Move to the next starting index after finding a valid substring
            }
        }

        // Update dp with the best result for index i
        dp[i] = max(maxPalindromes, solve(i + 1, k, s, dp, checkPalindrome));
        return dp[i];
    }
    
    int maxPalindromes(string s, int k) {
        int n = s.size();
        vector<int> dp(n, INT_MAX);
        vector<vector<int>> checkPalindrome(n, vector<int>(n, 0));

        // Precompute all palindromic substrings
        precomputePalindromes(s, checkPalindrome);

        // Solve the problem using precomputed palindromic table and memoization
        return solve(0, k, s, dp, checkPalindrome);
    }
};
