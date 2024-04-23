class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<unordered_set<int>> adjList(n);
        if(n == 1){
            return {0};
        }
        if(n == 2){
            return {0,1};
        }
        for(auto it: edges){
            adjList[it[0]].insert(it[1]);
            adjList[it[1]].insert(it[0]); 
        }
        unordered_set<int> rem;
        for(int i = 0; i < n; i++){
            rem.insert(i);
        }
        queue<int> qu;
        for(int i = 0; i < n; i++){
            if(adjList[i].size() == 1){
                qu.push(i);
            }
        }
        // cout << qu.size();
        while(n > 2){
            int size = qu.size();
            n-=qu.size();
            cout << size;
            for(int i = 0; i < size; i++){
                int node = qu.front();
                qu.pop();
                int neighbour = *adjList[node].begin();
                adjList[neighbour].erase(node);
                adjList[node].erase(neighbour);
                rem.erase(node);
                if(adjList[neighbour].size() == 1){
                    qu.push(neighbour);
                }
            }  
        }
        vector<int> sol;

        for(auto it: rem){
            sol.push_back(it);
        }

        return sol;
    }
};