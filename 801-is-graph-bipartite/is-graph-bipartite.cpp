class Solution {
public:
    bool dfs(int node, int color, vector<vector<int>> &graph, vector<int> &vis){
        vis[node] = color;
        int paint = 1;
        if(color == 1) paint = 2;
        for(auto neighbour: graph[node]){
            if(vis[neighbour] == color){
                return false;
            }
            else if(!vis[neighbour]){
                if(dfs(neighbour,paint,graph,vis) == false) return false;
            }
        }

        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        // queue<pair<int,int>> qu;
        vector<int> vis(n,0);

        for(int i = 0; i < n; i++){
            if(!vis[i]){
                if(!dfs(i,1,graph,vis)) return false;
            }
        }
        

        return true;
    }
};