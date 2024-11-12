class Solution {
public:
    bool dfs(int start, vector<vector<int>> &adjList, vector<int> &vis, vector<int> &totalVis){
        vis[start] = 1;
        totalVis[start] = 1;

        for(auto it: adjList[start]){
            if(vis[it] == 1){
                return true;
            }
            else if(totalVis[it] == 0 && dfs(it,adjList,vis,totalVis) == true){
                return true;
            }
        }

        vis[start] = 0;

        return false;

    }
    
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        int m = prerequisites.size();
        vector<vector<int>> adjList(n);
        vector<int> vis(n,0);
        vector<int> totalVis(n,0);
        for(int i = 0; i < m; i++){
            int a = prerequisites[i][0];
            int b = prerequisites[i][1];
            adjList[a].push_back(b);
        }
        for(int i = 0;  i < n; i++){
            if(!totalVis[i]){
                if(dfs(i,adjList,vis,totalVis) == true){
                    return false;
                }
            }
        }
        return true;
    }
};