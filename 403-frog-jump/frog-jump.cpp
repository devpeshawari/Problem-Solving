class Solution {
public:
    bool solve(int i, int k, int final, unordered_map<int,int> &mp,unordered_map<int,unordered_map<int,int>> &dp){
        if(i == final) return dp[i][k] = true;
        
        if(dp.count(i) && dp[i].count(k)) return dp[i][k];
        
        if(k == 0){
            if(mp.find(i + k + 1) != mp.end()){
                if(solve(i + k + 1, k + 1, final, mp,dp)) return true;
            }
        }
        else{
            if(mp.find(i + k - 1) != mp.end()){
                if(solve(i + k - 1, k - 1, final, mp,dp)) return dp[i][k] = true;
            }

            if(mp.find(i + k) != mp.end()){
                if(solve(i + k, k, final, mp,dp)) return dp[i][k] = true;
            }

            if(mp.find(i + k + 1) != mp.end()){
                if(solve(i + k + 1, k + 1, final, mp,dp)) return dp[i][k] = true;
            }
        }

        return dp[i][k] = false;
    }
    
    
    bool canCross(vector<int>& stones) {
        int n = stones.size();
        unordered_map<int,unordered_map<int,int>> dp;
        unordered_map<int,int> mp;
        int final = stones[n - 1];
        for(int i = 0; i < n; i++){
            mp[stones[i]] = 1;
        }

        return solve(stones[0],0,final,mp,dp);
    }
};