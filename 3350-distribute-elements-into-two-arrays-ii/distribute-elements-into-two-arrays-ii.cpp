class Solution {
public:
    int greaterCount(vector<int> &arr, int x){  
        int n = arr.size();
        int l = 0;
        int h = n - 1;
        int sol = 0;
        while(l <= h){
            int m = (l + h)/2;

            if(arr[m] <= x){
                l = m + 1;  
            }
            else{
                sol = n - m;
                h = m - 1;
            }

        }


        return sol;
    } 
    
    vector<int> resultArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> arr1;
        vector<int> arr2;
        vector<int> sortArr1;
        vector<int> sortArr2;
        arr1.push_back(nums[0]);
        arr2.push_back(nums[1]);
        sortArr1.push_back(nums[0]);
        sortArr2.push_back(nums[1]);
        for(int i = 2; i < n; i++){
            int x = greaterCount(sortArr1,nums[i]);
            int y = greaterCount(sortArr2,nums[i]);
            if(x > y){
                arr1.push_back(nums[i]);
                sortArr1.insert(sortArr1.end() - x,nums[i]);
            }
            else if(x < y){
                arr2.push_back(nums[i]);
                sortArr2.insert(sortArr2.end() - y,nums[i]);
            }
            else{
                if(arr1.size() <= arr2.size()){
                    arr1.push_back(nums[i]);
                    sortArr1.insert(sortArr1.end() - x,nums[i]);
                }
                else{
                    arr2.push_back(nums[i]);
                    sortArr2.insert(sortArr2.end() - y,nums[i]);
                }
            }
        }

        vector<int> sol;

        for(int i = 0; i < arr1.size(); i++){
            sol.push_back(arr1[i]);
        }
        for(int i = 0; i < arr2.size(); i++){
            sol.push_back(arr2[i]);
        }


        return sol;

    }
};