class Solution {
public:
    
    int dfs(int start,int parent,unordered_set<int> &res,vector<int> vis, vector<vector<int>> &adjList){
        vis[start] = 1;
        vector<int> sol;
        for(auto neighbour: adjList[start]){
            if(vis[neighbour] && (neighbour != parent)){
                res.insert(start);
                return neighbour;
            }   
            else if(!vis[neighbour]){
                int temp = dfs(neighbour,start,res,vis,adjList);
                if(start == 1) cout << temp;
                if(temp == start){
                    res.insert(start);
                    return -1;
                }
                else if(temp != -1){
                    res.insert(start);
                    return temp;
                }
            } 
        } 

        return -1;
    }
    
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> vis(n + 1,0);
        vector<vector<int>> adjList(n + 1);
        vector<int> sol;
        for(int i = 0; i < edges.size(); i++){
            adjList[edges[i][0]].push_back(edges[i][1]);
            adjList[edges[i][1]].push_back(edges[i][0]);
        }
        unordered_set<int> res;
        int temp = dfs(1,-1,res,vis,adjList);

        // for(auto it: res){
        //     cout << it << " ";
        // }

        for(int i = 0; i < edges.size(); i++){
            if(res.find(edges[i][0]) != res.end() && res.find(edges[i][1]) != res.end()){
                sol = edges[i];
            }
        }



        return sol;

    }
};