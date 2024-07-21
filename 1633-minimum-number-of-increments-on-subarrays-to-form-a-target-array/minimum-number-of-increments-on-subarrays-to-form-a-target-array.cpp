#define ll long long
class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int n = target.size();
        ll sol = abs(target[0]);
        ll last = target[0];
        for(int i = 1; i < n; i++){
            if(target[i] == 0){
                last = 0;
                continue;
            }
            if(last == 0){
                sol+=abs(target[i]);
                last = target[i];
            }
            else if(last > 0){
                if(target[i] > 0){
                    if(target[i] >= last){
                        sol+=target[i] - last;
                    }
                    last = target[i];
                }
                else{
                    last = target[i];
                    sol+=abs(target[i]);    
                }
            }
            else{
                if(target[i] < 0){
                    last = target[i];
                    if(target[i] <= last){
                        sol+=abs(target[i] - last);
                    }
                }
                else{
                    last = target[i];
                    sol+=abs(target[i]);    
                }
            }
            
        }

        return sol;


        
    }
};