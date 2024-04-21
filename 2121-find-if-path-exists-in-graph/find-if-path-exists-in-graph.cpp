class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
      vector<vector<int>> adjList(n);
      vector<int> vis(n,0);
      for(int i = 0; i < edges.size(); i++){
        adjList[edges[i][0]].push_back(edges[i][1]);
        adjList[edges[i][1]].push_back(edges[i][0]);
      }  
      queue<int> qu;
      qu.push(source);
      while(!qu.empty()){
        int node = qu.front();
        vis[node] = 1;
        qu.pop();
        if(node == destination){
            return true;
        }
        for(auto it: adjList[node]){
            if(!vis[it]){
                qu.push(it);
                vis[it] = 1;
            }
        }
      }

      return false;

    }
};