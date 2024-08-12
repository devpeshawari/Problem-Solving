class Solution {
public:
    bool solve(int m, int k, vector<int>& position){
        int n = position.size();
        m--;
        int prev = position[0];
        for(int i = 1; i < n; i++){
            if(position[i] - prev >= k){
                m--;
                prev = position[i];
            }
            if(m == 0){
                return true;
            }
        }

        return false;
    }
    
    int maxDistance(vector<int>& position, int m) {
        int n = position.size();
        sort(position.begin(), position.end());
        int l = 1;
        int h = position[n - 1] - position[0];
        int sol = 1;
        while(l <= h){
            int k = (l + h)/2;

            if(solve(m,k,position)){
                sol = k;
                l = k + 1;
            }
            else{
                h = k - 1;
            }

        }


        return sol;
    }
};