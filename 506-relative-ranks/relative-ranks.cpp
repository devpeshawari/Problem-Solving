class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();
        unordered_map<int,int> mp;
        vector<string> sol(n);
        for(int i = 0; i < n; i++){
            mp[score[i]] = i;
        }
        sort(score.begin(), score.end(), greater<int>());
        for(int i = 0; i < n; i++){
            if(i + 1 == 1){
                sol[mp[score[i]]] = "Gold Medal";
            }
            else if(i + 1 == 2){
               sol[mp[score[i]]] = "Silver Medal";  
            }
            else if(i + 1 == 3){
               sol[mp[score[i]]] = "Bronze Medal"; 
            }
            else{
                sol[mp[score[i]]] = to_string(i + 1);
            }
            
        }    

        return sol;
    }
};