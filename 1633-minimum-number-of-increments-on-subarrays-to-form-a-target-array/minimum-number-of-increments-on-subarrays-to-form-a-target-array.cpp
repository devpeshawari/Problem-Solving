class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int n = target.size();
        int sol = target[0];
        int last = target[0];
        for(int i = 1; i < n; i++){
            if(last > target[i]){
                last = target[i];
            }
            else{
                sol+=target[i] - last;
                last = target[i];
            }
        }   

        return sol;



        
    }
};