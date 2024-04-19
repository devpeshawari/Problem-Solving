class Solution {
public:
    void dfs(int x, int y, vector<vector<int>> &vis, vector<vector<char>> &grid){
        vis[x][y] = 1;
        int n = grid.size();
        int m = grid[0].size();
        int dx[4] = {1, -1, 0, 0};
        int dy[4] = {0, 0, -1, 1};

        for(int i = 0; i < 4; i++){
            int newx = x + dx[i];
            int newy = y + dy[i];
            if(newx < n && newy < m && newy >= 0 && newx >= 0 && grid[newx][newy] == '1' && !vis[newx][newy]){
                dfs(newx, newy, vis, grid);
            }
        }

    } 
    
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int sol = 0;
        vector<vector<int>> vis(n, vector<int>(m,0));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(!vis[i][j] && grid[i][j] == '1'){
                    dfs(i,j,vis,grid);
                    sol++;
                }
            }
        }

        return sol;
    }
};