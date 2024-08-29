class Solution {
public:
    class DisjointSet{
        public:
            vector<int> parent;
            vector<int> size;
            DisjointSet(int n){
                parent.resize(n);
                size.resize(n);
                for(int i = 0; i < n; i++){
                    size[i] = 1;
                    parent[i] = i;
                }
            }
            
            int findParent(int u){
                if(parent[u] == u){
                    return u;
                }

                return parent[u] = findParent(parent[u]);
            }

            void UnionBySize(int u, int v){
                int parU = findParent(u);
                int parV = findParent(v);
                if(parU == parV){
                    return;
                }
                if(size[parU] >= size[parV]){
                    parent[parV] = parU;
                    size[parU]++;
                }
                else{
                    parent[parU] = parV;
                    size[parV]++;    
                }
                
            }


    };
    
    // when are two stones in the same set
    // 1. if they share the same row
    // 2. if they share the same column
    // 3. if x1 == x2 || y1 == y2     
    
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        DisjointSet stoneSets(n);
        int sol = n;
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                if(stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]){
                    stoneSets.UnionBySize(i,j);
                }
            }
        }
        int numSets = 0;

        for(int i = 0; i < n; i++){
            if(stoneSets.findParent(i) == i){
                numSets++;
            }
        }


        return n - numSets;

    }
};