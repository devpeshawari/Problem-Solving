class Solution {
public:
    void solve(int x,int y, vector<vector<char>> &grid, vector<vector<int>> &vis){
        int n = grid.size();
        int m = grid[0].size();
        vis[x][y] = 1;
        int dx[4] = {0,-1,0,1};
        int dy[4] = {-1,0,1,0};

        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(ny >= 0 && nx >= 0 && ny < m && nx < n && grid[nx][ny] == '1' && !vis[nx][ny]){
                solve(nx,ny,grid,vis);
            }
        }

    }
    
    
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int sol = 0;
        vector<vector<int>> vis(n,vector<int>(m,0));

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(!vis[i][j] && grid[i][j] == '1'){
                    solve(i,j,grid,vis);
                    sol++;
                }
            }
        }    

        return sol;
    }
};