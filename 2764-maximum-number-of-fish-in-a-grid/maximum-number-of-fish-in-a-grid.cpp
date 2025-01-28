class Solution {
public:
    int dfs(int x, int y, vector<vector<int>> &grid){
        int n = grid.size();
        int m = grid[0].size();
        int score = grid[x][y];
        grid[x][y] = 0;
        int dx[4] = {0,-1,0,1};
        int dy[4] = {-1,0,1,0};

        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx >= 0 && ny >= 0 && nx < n && ny < m && grid[nx][ny]){
                score+=dfs(nx,ny,grid);
            }
        }

        return score;
    }
    
    
    int findMaxFish(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int sol = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] != 0){
                    sol = max(sol,dfs(i,j,grid));   
                }
            }
        }

        return sol;
    }
};