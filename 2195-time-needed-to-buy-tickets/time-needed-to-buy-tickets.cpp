class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int n = tickets.size();
        int sol = 0;
        sol+=tickets[k];
        for(int i = 0; i < k; i++){
            sol+= min(tickets[i],tickets[k]);
        }
        for(int i = k + 1; i < n; i++){
            sol+= min(tickets[i],tickets[k] - 1);
        }

        return sol;
    }
};