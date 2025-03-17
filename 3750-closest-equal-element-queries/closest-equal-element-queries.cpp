class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        int q = queries.size();
        unordered_map<int,vector<int>> mp;
        vector<int> sol(n,-1);
        vector<int> ans;
        for(int i = 0; i < n; i++){
            mp[nums[i]].push_back(i);  
        }
        
        for(auto arr: mp){
            int m = arr.second.size();
            if(m == 1) continue;
            
            for(int i = 0; i < m; i++){
                
                if(i == 0){
                    sol[arr.second[i]] = min(abs(n - abs(arr.second[i] - arr.second[m - 1])),abs(arr.second[i] - arr.second[i + 1]));
                    if(arr.second[i] == 0) cout << abs(n - (arr.second[i] - arr.second[m - 1]));
                }
                else if(i == m - 1){
                    sol[arr.second[i]] = min(abs(arr.second[i] - arr.second[i - 1]),n - abs(arr.second[i] - arr.second[(i + 1)%m]));    
                }
                else{
                    sol[arr.second[i]] = min(abs(arr.second[i] - arr.second[i - 1]),abs(arr.second[i] - arr.second[(i + 1)%m]));   
                }
            }
        }

        for(int i = 0; i < q; i++){
            ans.push_back(sol[queries[i]]);
        }

        return ans;
    }
};