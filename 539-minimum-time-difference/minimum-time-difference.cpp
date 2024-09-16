class Solution {
public:
    int getTime(string &s){
        int hour = ((s[0] - '0') * 10) + (s[1] - '0'); 
        int minutes = ((s[3] - '0') * 10) + (s[4] - '0');

        return hour * 60 + minutes;
    }
    
    
    int findMinDifference(vector<string>& timePoints) {
        int n = timePoints.size();
        sort(timePoints.begin(), timePoints.end());
        int sol = INT_MAX;

        for(int i = 1; i < n; i++){
            int time1 = getTime(timePoints[i - 1]);
            int time2 = getTime(timePoints[i]);
            int diff1 = time2 - time1;
            int diff2 = ((24 * 60) - (time2)) + time1;
            int diff = min(diff1,diff2);
            sol = min(diff,sol);
        }
        int time1 = getTime(timePoints[0]);
        int time2 = getTime(timePoints[n - 1]);
        int diff = ((24 * 60) - (time2)) + time1;
        cout << diff;
        sol = min(diff,sol);
       
        return sol;
    }
};