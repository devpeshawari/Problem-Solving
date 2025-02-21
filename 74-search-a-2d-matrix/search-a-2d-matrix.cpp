class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int findRow = -1;
        int l = 0;
        int h = n - 1;
        while(l<=h){
            int mid = (l + h)/2;
            
            if(matrix[mid][m - 1] >= target){
                findRow = mid;
                h = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }
        if(findRow == -1){
            return false;
        }
        l = 0;
        h = m - 1;
        while(l <= h){
            int mid = (l + h)/2;
            
            if(matrix[findRow][mid] == target){
                return true;
            }
            else if(matrix[findRow][mid] > target){
                h = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }
        cout << findRow;
        return false;
    }
};