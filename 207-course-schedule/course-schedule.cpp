class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        int m = prerequisites.size();
        vector<vector<int>> adjList(n);
        vector<int> vis(n,0);
        vector<int> indegree(n,0);
        queue<int> qu;
        for(int i = 0; i < m; i++){
            int a = prerequisites[i][0];
            int b = prerequisites[i][1]; 
            indegree[b]++;
            adjList[a].push_back(b);
        }
        for(int i = 0 ; i< n; i++){
            if(indegree[i] == 0){
                qu.push(i);
            }
        }

        while(qu.size()){
            int node = qu.front();
            qu.pop();
            for(auto neighbour: adjList[node]){
                if(indegree[neighbour] >= 1){
                    indegree[neighbour]--;
                    if(indegree[neighbour] == 0){
                        qu.push(neighbour);
                    }
                }
            }
        }

        for(int i = 0 ; i< n; i++){
            if(indegree[i] != 0){
                return false;
            }
        }
        

        return true;
    }
};