class Solution {
public:

    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size(); //size of the array 
        int next = 1;

        for(int i = 0; i < n; i++){ //iterating through the array
            while(arr[i] > next && k != 0){
                next++; //incrementing next
                k--;
            }
            if(k == 0){
                return next - 1;
            }
            next++;
        }

        return arr[n - 1] + k;
    }
};