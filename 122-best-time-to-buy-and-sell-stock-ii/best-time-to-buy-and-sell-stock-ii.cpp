class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int minNum = prices[0];
        int sol = 0; 
        for(int i = 1; i < n; i++){
            int temp = max(0,prices[i] - minNum);
            minNum = prices[i];
            sol+=temp;
        }    

        return sol;
    }
};