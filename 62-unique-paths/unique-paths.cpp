class Solution {
public:
    int solve(int x, int y, vector<vector<int>> &dp){
        if(x == 0 && y == 0){
            return 1;
        }
        if(dp[x][y] != -1){
            return dp[x][y];
        }
        int up = 0;
        int left = 0;
        if(x - 1 >= 0){
            up = solve(x - 1,y,dp);
        }
        if(y - 1 >= 0){
            left = solve(x,y - 1,dp);
        }

        return dp[x][y] = left + up;
    }
    
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n,-1));
        vector<int> last(n,0);
        vector<int> curr(n,0);
        last[0] = 1;
        curr[0] = 1;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(i == 0 && j == 0){
                    continue;
                }    
                int up = 0;
                int left = 0;
                if(i - 1 >= 0){
                    up = last[j];
                }
                if(j - 1 >= 0){
                    left = curr[j - 1];
                }

                curr[j] = left + up;
            }
            last = curr;
        }

        return last[n - 1];
    }
};