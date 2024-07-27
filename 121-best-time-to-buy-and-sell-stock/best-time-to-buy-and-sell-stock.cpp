class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxNum = 0;
        int minNum = INT_MAX;
        int sol = 0;
        int n = prices.size();
        for(int i = n - 1; i >= 0; i--){
            if(prices[i] > maxNum){
                minNum = prices[i];
                maxNum = prices[i];
            }
            minNum = min(minNum,prices[i]);

            sol = max(maxNum - minNum,sol);
            
        }   

        return sol;
  
    }
};