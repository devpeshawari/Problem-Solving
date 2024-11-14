class Solution {
public:
    bool cond(int m, int stores, vector<int> &arr){
        int used = 0;
        int n = arr.size();

        for(int i = 0; i < n; i++){
            used+=(arr[i]/m);
            if(arr[i]%m) used++;
            if(used > stores) return false;
        }

        return true;
    }
    
    int minimizedMaximum(int n, vector<int>& quantities) {
        int m = quantities.size();
        int h = *max_element(quantities.begin(), quantities.end());
        int sol = h;
        int l = 1;
        
        while(l <= h){
            int mid = (l + h)/2;
            if(cond(mid, n,quantities)){
                sol = mid;
                h = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }


        return sol;
    }
};