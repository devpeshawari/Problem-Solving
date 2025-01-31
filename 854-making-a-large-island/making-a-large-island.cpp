class Solution {
public:
    int dfs(int x, int y, int key, vector<vector<int>> &grid){
        int n = grid.size();
        int m = grid[0].size();
        grid[x][y] = key;
        int sol = 1;
        int dx[4] = {0,-1,0,1};
        int dy[4] = {-1,0,1,0};

        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < n && ny < m && nx >= 0 && ny >= 0 && grid[nx][ny] != key && grid[nx][ny] != 0){
                sol+=dfs(nx,ny,key,grid);
            }
        }



        return sol;
    }
    
    
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        unordered_map<int,int> mp;
        vector<vector<int>> vis(n,vector<int>(m,0));
        int key = 2;
        int sol = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1){
                    mp[key] = dfs(i,j,key,grid);
                    sol = max(sol,mp[key]);
                    key++;
                }
            }
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                unordered_set<int> st;
                if(grid[i][j] == 0){
                    int dx[4] = {0,-1,0,1};
                    int dy[4] = {-1,0,1,0};

                    for(int k = 0; k < 4; k++){
                        int nx = i + dx[k];
                        int ny = j + dy[k];
                        if(nx < n && ny < m && nx >= 0 && ny >= 0){
                            if(mp.find(grid[nx][ny]) != mp.end()){
                                st.insert(grid[nx][ny]);
                            }
                        }
                    }
                    int temp = 1;
                    for(auto it: st){
                        temp+=mp[it];
                    }
                    sol = max(sol,temp);
                }
            }
        }

        return sol;
    }
};