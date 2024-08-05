class Solution {
public:
    void dfs(int i,vector<int> &vis, vector<vector<int>> &isConnected){
        int n = isConnected.size();
        vis[i] = 1;
        for(int j = 0; j < n; j++){
            if(vis[j] == 0 && isConnected[i][j] == 1){
                dfs(j,vis,isConnected);
                vis[j] = 1;
            }
        }
    }
    
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> vis(n,0);
        int sol = 0;
        for(int i = 0; i < n; i++){
            if(vis[i] == 0){
                sol++;
                dfs(i,vis,isConnected);
            }
        }

        return sol;
    }
};