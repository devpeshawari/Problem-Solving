class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        unordered_map<int,int> mp1;
        unordered_map<int,int> mp2;
        int n = target.size();
        
        for(int i = 0; i < n; i++){
            mp1[arr[i]]++;
            mp2[target[i]]++;
        }

        for(auto it: mp1){
            int num = it.first;
            int feq = it.second;
            if(mp2.find(num) == mp2.end() || mp1[num] != mp2[num]){
                return false;
            }
        }    

        return true;
    }
};