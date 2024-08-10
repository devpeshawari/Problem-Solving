class Solution {
public:
    void bfs(int x, int y, vector<vector<char>>& board){
        int n = board.size();
        int m = board[0].size();
        queue<pair<int,int>> qu;
        qu.push({x,y});
        while(!qu.empty()){
            int nodex = qu.front().first;
            int nodey = qu.front().second;
            board[nodex][nodey] = 'y';
            int dx[4] = {0,-1,0,1};
            int dy[4] = {-1,0,1,0};
            qu.pop();
            for(int i = 0; i < 4; i++){
                int nx = nodex + dx[i];
                int ny = nodey + dy[i];
                if(nx < n && ny < m && nx >= 0 && ny >= 0 && board[nx][ny] == 'O'){
                    board[nx][ny] = 'y';
                    qu.push({nx,ny});
                }
            }

        }
    }
    
    
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        for(int i = 0; i < n; i++){
            if(board[i][0] == 'O'){
                bfs(i,0,board);
            }
        }
        for(int i = 0; i < n; i++){
            if(board[i][m - 1] == 'O'){
                bfs(i,m - 1,board);
            }   
        }
        for(int i = 0; i < m; i++){
            if(board[0][i] == 'O'){
                bfs(0,i,board);
            }   
        }
        for(int i = 0; i < m; i++){
            if(board[n - 1][i] == 'O'){
                bfs(n - 1, i, board);
            }   
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(board[i][j] == 'O') board[i][j] = 'X';
                if(board[i][j] == 'y') board[i][j] = 'O';
                
            }
        }


        
    }
};