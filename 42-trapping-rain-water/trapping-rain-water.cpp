class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int right_max = 0;
        int left_max = 0;
        int sol = 0;
        int l = 0;
        int r = n - 1; 
        while(l <= r){
            left_max = max(left_max,height[l]);
            right_max = max(right_max,height[r]);
            if(left_max <= right_max){
                sol+=left_max - height[l];
                l++;
            }
            else{
                sol+=right_max - height[r];
                r--;
            }
        }


        return sol; 
    }
};