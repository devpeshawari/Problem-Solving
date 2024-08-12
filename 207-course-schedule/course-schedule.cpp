class Solution {
public:
    bool dfs(int node, int vis[], int pathvis[] , vector<vector<int>>& adjList){
        vis[node] = 1;
        pathvis[node] = 1;
        for(auto it: adjList[node]){
            if(!vis[it]){
                if(dfs(it, vis , pathvis , adjList) == true){
                    return true;
                }
            }
            else if(pathvis[it] == 1){
                return true;
            }
            
            
            
        }
        pathvis[node] = 0;
        return false;
    }
    
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<vector<int>> adj_list;
        adj_list.resize(numCourses);
        
        for(int i = 0; i < prerequisites.size(); i++){
            adj_list[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        int vis[numCourses];
        int pathvis[numCourses];
        for(int i = 0; i < n; i++){
            vis[i] = 0;
            pathvis[i] = 0;
        }
        bool cond = false;
        for(int i = 0; i < n; i++){
            if(!vis[i]){
                cond = dfs(i,vis,pathvis,adj_list);
                if(cond == true){
                    break;
                }
            }   
        }
        return !cond;    
    }
};