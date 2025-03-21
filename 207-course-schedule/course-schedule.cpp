class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int m = prerequisites.size();
        vector<vector<int>> adjList(numCourses);
        vector<int> indegree(numCourses,0);
        for(int i = 0; i < m; i++){
            adjList[prerequisites[i][1]].push_back(prerequisites[i][0]);
            indegree[prerequisites[i][0]]++;
        }   

        queue<int> qu;
        for(int i = 0; i < numCourses; i++){
            if(indegree[i] == 0) qu.push(i);
        }

        while(!qu.empty()){
            int node = qu.front();
            qu.pop();
            for(auto it: adjList[node]){
                indegree[it]--;
                if(indegree[it] == 0){
                    qu.push(it);
                }
            }
        }

        for(int i = 0; i < numCourses; i++){
            if(indegree[i] != 0) return false;
        }

        return true;
    }
};