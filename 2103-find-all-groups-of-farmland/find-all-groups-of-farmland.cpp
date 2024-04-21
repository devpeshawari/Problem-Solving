class Solution {
public:
    vector<int> dfs(int x, int y, int maxx, int maxy,vector<vector<int>> &vis, vector<vector<int>> &grid){
        int n = grid.size();
        int m = grid[0].size();
        vis[x][y] = 1;
        vector<int> maxi = {max(x,maxx),max(y,maxy)};
        int dx[4] = {1,-1,0,0};
        int dy[4] = {0,0,-1,1};
        
        for(int i = 0; i < 4; i++){
            int newx = x + dx[i];
            int newy = y + dy[i];
            if(newx >= 0 && newy >= 0 && newx < n && newy < m && grid[newx][newy] && !vis[newx][newy]){
                vector<int> temp = dfs(newx,newy,maxx,maxy,vis,grid);
                maxi[0] = max(maxi[0],temp[0]);
                maxi[1] = max(maxi[1],temp[1]);
            }
        }


        return maxi;
    }
    
    
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int n = land.size();
        int m = land[0].size();
        vector<vector<int>> sol;
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(land[i][j] && !vis[i][j]){
                    vector<int> maxi = dfs(i,j,i,j,vis,land);
                    sol.push_back({i,j,maxi[0],maxi[1]});
                }
            }
        }

        return sol;
    }
};