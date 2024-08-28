class Solution {
public:
    int bfs(int startx, int starty, vector<vector<int>> &vis,vector<vector<int>>& grid1,vector<vector<int>>& grid2){
        int n = grid1.size();
        int m = grid1[0].size();
        queue<pair<int,int>> qu;
        qu.push({startx,starty});
        int dx[4] = {0,-1,0,1};
        int dy[4] = {-1,0,1,0};
        bool cond = false;
        while(!qu.empty()){
            int x = qu.front().first;
            int y = qu.front().second;
            qu.pop();
            vis[x][y] = 1;
            if(grid1[x][y] == 0){
                cond = true;
            }
            for(int i = 0; i < 4; i++){
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(nx < n && ny < m && nx >= 0 && ny >= 0 && !vis[nx][ny] && grid2[nx][ny] == 1){
                    qu.push({nx,ny});
                    vis[nx][ny] = 1;
                }
            }
        }

        if(cond){
            return 0;
        }

        return 1;

    }
    
    
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int n = grid1.size();
        int m = grid1[0].size();
        int sol = 0;
        vector<vector<int>> vis(n,vector<int>(m,0));

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(!vis[i][j] && grid2[i][j] == 1){
                    sol+=bfs(i,j,vis,grid1,grid2);
                }
            }
        }


        return sol;


    }
};