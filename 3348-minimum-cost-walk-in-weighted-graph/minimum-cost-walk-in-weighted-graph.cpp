class DisjointSet{
public:    
    vector<int> size;
    vector<int> parent;
    
    DisjointSet(int n){
        parent.resize(n);
        size.resize(n,1);

        for(int i = 0; i < n; i++){
            parent[i] = i;
        }
    }

    int findParent(int i){
        if(parent[i] == i){ 
            return i;
        }

        return parent[i] = findParent(parent[i]);
    }

    void unionBySize(int x, int y){
        int px = findParent(x);
        int py = findParent(y);
        if(px == py) return;
        if(size[px] >= size[py]){
            parent[py] = px;
            size[px]+=size[py]; 
        }
        else{
            parent[px] = py;
            size[py]+=size[px];    
        }
    }


};


class Solution {
public:
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        unordered_map<int,int> mp;
        int m = edges.size();
        DisjointSet ds(n);
        vector<int> sol;
        for(int i = 0; i < m; i++){
            int node1 = edges[i][0];
            int node2 = edges[i][1];
            int weight = edges[i][2];
            int parent1 = ds.findParent(node1);
            int parent2 = ds.findParent(node2);
            if(mp.find(parent1) != mp.end()) weight = weight & mp[parent1];
            if(mp.find(parent2) != mp.end()) weight = weight & mp[parent2];
            ds.unionBySize(parent1,parent2);
            int parent = ds.findParent(parent1);
            mp[parent] = weight;
        }    

        for(int i = 0; i < query.size(); i++){
            int start = query[i][0];
            int end = query[i][1];
            int parent1 = ds.findParent(start);
            int parent2 = ds.findParent(end);

            if(parent1 == parent2) sol.push_back(mp[parent1]);
            else sol.push_back(-1);
        }

        return sol;
    }
};