class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        long long sol = 0;
        int n = nums.size();
        int j = 0;
        map<int,int> mp;
        for(int i = 0; i < n; i++){
            int minElement = 0;
            int maxElement = 0;
            mp[nums[i]]++;
            if(!mp.empty()){
                auto pointer1 = *mp.begin();
                auto pointer2 = mp.rbegin();
                minElement = pointer1.first;
                maxElement = pointer2->first;
            }
            

            while(!mp.empty() && abs(minElement - maxElement) > 2){
                mp[nums[j]]--;
                if(mp[nums[j]] == 0) mp.erase(nums[j]);
                j++;
                if(!mp.empty()){
                    auto pointer1 = *mp.begin();
                    auto pointer2 = mp.rbegin();
                    minElement = pointer1.first;
                    maxElement = pointer2->first;
                }
            }
            sol+= i - j + 1;
        }

        return sol;

    }
};