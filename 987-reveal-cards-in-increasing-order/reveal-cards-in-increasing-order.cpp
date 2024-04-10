class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int n = deck.size();
        vector<int> sol(n);
        sort(deck.begin(), deck.end());
        queue<int> qu;
        for(int i = 0; i < n; i++){
            qu.push(i);
        }
        int j = 0;
        int count = 0;
        while(!qu.empty()){
            int temp = qu.front();
            qu.pop();
            if(count%2 == 0){
                sol[temp] = deck[j];
                j++;
            }
            else{
                qu.push(temp);
            }
            count++;
        }



        return sol;
    }   
};