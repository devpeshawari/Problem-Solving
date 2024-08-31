class Solution {
public:
    int kthFactor(int n, int k) {
        int sol = -1;
        vector<int> arr_start;
        vector<int> arr_end;
        int count = 0;
        for(int i = 1; i <= sqrt(n); i++){
            if(n%i == 0){
                if(i == n/i){
                    count++;
                    arr_start.push_back(i);
                }
                else{
                    count+=2;
                    arr_start.push_back(i);
                    arr_end.push_back(n/i);
                   
                }
            }
        }
        if(k<=count){
            if(k<=arr_start.size()){
                sol = arr_start[k - 1];
            }
            if(k > arr_start.size()){
                sol = arr_end[arr_end.size() - (k - arr_start.size())];
            }
        }

        return sol;
    }
};