class Solution {
public:
    int cond(int k, int h, vector<int>& piles){
        long long time = 0;
        int n = piles.size();
        for(int i = 0; i < n; i++){
            if(piles[i] < k){
                time++;
            }
            else{
                time+=piles[i]/k;
                if(piles[i]%k){
                    time++;
                }
            }
        }

        if(time <= h){
            return true;
        }
        return false;
    }
    
    
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int u = *max_element(piles.begin(), piles.end());
        int sol = u;
        while(l <= u){
            int mid = (l + u)/2;

            if(cond(mid,h,piles)){
                sol = mid;
                u = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }
        cout << cond(500000001,h,piles);
        return sol;
    }
};