class Solution {
public:
    int M = 1e9 + 7;
    int numOfSubarrays(vector<int>& arr) {
        int n = arr.size();
        int evenSum = 1;
        int oddSum = 0;
        int currSum = 0;
        int sol = 0;
        for(int i = 0; i < n; i++){
           (currSum+=arr[i])%2;
           if(currSum%2 == 1)sol= (sol%M + evenSum)%M;
           else sol = (sol%M +  oddSum)%M;
           if(currSum%2) oddSum++;
           else evenSum++;
        }

        return sol;
    }
};