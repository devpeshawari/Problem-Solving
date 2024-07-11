class Solution {
public:
    bool cond(int div,vector<int> &nums, int threshold){
        int n = nums.size();
        long long int score = 0;
        for(int i = 0; i < n; i++){
            score+=ceil(float(nums[i])/div); //incrementing our score;
        }
        if(score <= threshold){
            return true;
        }

        return false;
    } // bool function
    
    
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size();
        int l = 1; //declaring the lower limit
        int h = *max_element(nums.begin(), nums.end()); //declaring the uppr limit
        int sol = h;
        while(l <= h){ //initiating the binary search
            int m = (l + h)/2; // declaring the middle lement
            
            if(cond(m,nums,threshold)){
                sol = m;
                h = m - 1;
            }
            else{
                l = m + 1;
            }
        }
        cout << cond(3,nums,threshold);

        return sol; //returning the answer
    }
};