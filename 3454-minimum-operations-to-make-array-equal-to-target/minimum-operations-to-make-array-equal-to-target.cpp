#define ll long long 
class Solution {
public:
    long long minimumOperations(vector<int>& nums, vector<int>& target) {
        int n = nums.size();
        vector<int> arr(n);
        for(int i = 0; i < n; i++){
            arr[i] = target[i] - nums[i];
        }

        ll sol = abs(arr[0]);
        ll last = arr[0];
        for(int i = 1; i < n; i++){
            cout << last << " ";
            if(arr[i] == 0){
                last = 0;
                continue;
            }
            if(last == 0){
                sol+=abs(arr[i]);
                last = arr[i];
            }
            else if(last > 0){
                if(arr[i] > 0){
                    if(arr[i] >= last){
                        sol+=arr[i] - last;
                    }
                    last = arr[i];
                }
                else{
                    last = arr[i];
                    sol+=abs(arr[i]);    
                }
            }
            else{
                if(arr[i] < 0){
                    if(arr[i] <= last){
                        sol+=abs(arr[i] - last);
                    }
                    last = arr[i];
                }
                else{
                    last = arr[i];
                    sol+=abs(arr[i]);    
                }
            }
            
        }

        return sol;
    }
};