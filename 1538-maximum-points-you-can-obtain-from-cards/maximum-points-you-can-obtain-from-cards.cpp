class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int j = 0;
        int n = cardPoints.size();
        int total = 0;
        int sol = 0;
        
        for(int i = 0; i < n; i++){
            total+=cardPoints[i];
        }
        int sum = 0;
        if(n == k){
            return total;
        }
        for(int i = 0; i < n; i++){
            sum+=cardPoints[i];
            if(i - j + 1 == n - k){
                sol = max(sol,total - sum);
                sum-=cardPoints[j];
                j++;
            }
        }

        return sol;
    }
};