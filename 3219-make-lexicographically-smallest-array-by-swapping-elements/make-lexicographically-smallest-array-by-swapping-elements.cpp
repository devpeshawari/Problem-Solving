class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<int> numsSorted(nums);
        vector<int> sol;
        sort(numsSorted.begin(),numsSorted.end());
        int currGroup = 0;
        unordered_map<int,int> groups;
        unordered_map<int,queue<int>> groupList;
        groups[numsSorted[0]] = currGroup;
        groupList[0].push(numsSorted[0]);
        for(int i = 1; i < n; i++){
            if(numsSorted[i] - numsSorted[i - 1] > limit) currGroup++;
            groups[numsSorted[i]] = currGroup;
            groupList[currGroup].push(numsSorted[i]);
        }
        
        for(int i = 0; i < n; i++){
            int numGroup = groups[nums[i]];
            sol.push_back(groupList[numGroup].front());
            cout << numGroup << " ";
            groupList[numGroup].pop();
        }


        return sol;
    }
};