class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<vector<int>> sol;
        sort(intervals.begin(), intervals.end());
        int lastEnd = intervals[0][1];
        int lastStart = intervals[0][0];
        sol.push_back({intervals[0][0], intervals[0][1]});
        for(int i = 1; i < n; i++){
            int start = intervals[i][0];
            int end = intervals[i][1];
            if(start > lastEnd){
                sol.push_back({intervals[i][0], intervals[i][1]});
                lastEnd = intervals[i][1];
                lastStart = intervals[i][0];
            }
            else{
                sol[sol.size() - 1][1] = max(end,lastEnd);
                lastEnd = max(lastEnd,end);
            }
        } 


        return sol;
    }
};