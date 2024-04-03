class Solution {
public:
    bool dfs(int x, int y, int ind, vector<vector<char>> &board, string &word){
        if(ind == (word.size() - 1) && word[ind] == board[x][y]){
            return true;
        }
        if(word[ind] != board[x][y]){
            return false;
        }
        char temp = board[x][y];
        int n = board.size();
        int m = board[0].size();
        board[x][y] = '.';
        int diffx[4] = {0,1,0,-1};
        int diffy[4] = {-1,0,1,0};
        bool tempAns = false;
        for(int i = 0; i < 4; i++){
            int currx = x + diffx[i];
            int curry = y + diffy[i];
            if(currx >= 0 && curry >= 0 && currx < n && curry < m && board[currx][curry] != '.'){
                if(dfs(currx,curry,ind + 1,board,word)){
                    return true;
                }
            }
        }

        board[x][y] = temp;
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(dfs(i,j,0,board,word) == true){
                    return true;
                }
            }
        }

        return false;

    }
};