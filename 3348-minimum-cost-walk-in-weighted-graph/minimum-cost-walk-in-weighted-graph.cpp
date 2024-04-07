class DisjointSet{
public:
    vector<int> parent;
    vector<long long> size;

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

    void UnionBySize(int x, int y){
        int ux = findParent(x);
        int uy = findParent(y);
        if(ux == uy){
            return;
        }
        if(size[ux] >= size[uy]){
            parent[uy] = ux;
        }
        else{
            parent[ux] = uy;
            size[uy]+=size[ux];
        }
    }


};


class Solution {
public:
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        int m = edges.size();        
        int q = query.size();
        vector<int> sol(q);
        DisjointSet ds(n);
        vector<int> score(n,pow(2,31) - 1);
        for(int i = 0; i < m; i++){
            ds.UnionBySize(edges[i][0],edges[i][1]);
        }
        for(int i = 0; i < m; i++){
            int parent = ds.findParent(edges[i][0]);
            score[parent] = score[parent] & edges[i][2]; 
        }

        for(int i = 0; i < q; i++){
            int u = query[i][0];
            int v = query[i][1];
            if(u == v){
                sol[i] = 0;
                continue;
            }
            if(ds.findParent(u) != ds.findParent(v)){
                sol[i] = -1;
            }
            else{
                sol[i] = score[ds.findParent(u)];
            }
        }


        return sol;
    }
};