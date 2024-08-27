class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        int m = edges.size();
        vector<double> prob(n,0.0);
        vector<vector<pair<int,double>>> adjList(n);
        for(int i = 0; i < m; i++){
            adjList[edges[i][0]].push_back({edges[i][1],succProb[i]});
            adjList[edges[i][1]].push_back({edges[i][0],succProb[i]});
        }

        priority_queue<pair<int,double>> qu;
        prob[start_node] = 1;
        qu.push({start_node,prob[start_node]});
        while(!qu.empty()){
            double currProb = qu.top().second;
            int node = qu.top().first;
            qu.pop();
            for(auto it: adjList[node]){
                double transProb = it.second;
                int neighbour = it.first;
                if(prob[neighbour] < (currProb * transProb)){
                    prob[neighbour] = (currProb * transProb);
                    qu.push({neighbour,prob[neighbour]});
                }
            }
        }

        return prob[end_node];
    }
};