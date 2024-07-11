class Solution {
public:
    
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size(); //size of the array 
        int l = 0;
        int h = n - 1;
        int sol = k;
        while(l <= h){
            int m = (l + h)/2;
            if(arr[m] - 1 - m < k){
                sol = arr[m] + k  - (arr[m] - 1- m);
                l = m + 1;
            }
            else{
                h = m - 1;
            }
        }

        return sol;

    }
};