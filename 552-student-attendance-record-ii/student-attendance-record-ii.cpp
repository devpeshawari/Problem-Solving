long long M = 1e9 + 7;
class Solution {
public:
    long long solve(long long i, long long lateCount, long long absentCount, vector<vector<vector<long long>>> &dp){
        if(dp[i][lateCount][absentCount] != -1){
            return dp[i][lateCount][absentCount];
        }
        if(absentCount >= 2){
            return 0;
        }
        if(lateCount >= 3){
            return 0;
        }
        if(i == 0){
            long long temp = 1;
            if(absentCount <= 0){
                temp++;
            }
            if(lateCount <= 1){
                temp++;
            }
            return temp;
        }
        long long present = solve(i - 1, 0,absentCount,dp)%M;
        long long absent = solve(i - 1, 0,absentCount + 1,dp)%M;
        long long late = solve(i - 1, lateCount + 1,absentCount,dp)%M;

        return dp[i][lateCount][absentCount] = (present%M + late%M + absent%M)%M;
    }
    
    
    int checkRecord(int n) {
        vector<vector<vector<long long>>> dp(n,vector<vector<long long>>(4,vector<long long>(3,-1))); 
        return solve(n - 1,0,0,dp);
    }
};