class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int n = tickets.size();
        queue<int> qu;

        for(int i = 0; i < n; i++){
            qu.push(i);
        }
        int sol = 0;

        while(!qu.empty()){
            tickets[qu.front()]--;
            sol++;
            int temp = qu.front();
            qu.pop();
            if(tickets[temp] == 0){
                if(temp == k){
                    return sol;
                }
            }
            else{
                qu.push(temp);
            }
        }


        return sol;
    }
};