class Solution {
public:
    int countSeniors(vector<string>& details) {
        int n = details.size();
        int sol = 0;
        for(int i = 0; i < n; i++){
            int age = (details[i][11] - '0') * 10;
            age+= (details[i][12] - '0');
            if(age > 60) sol++;
        }


        return sol;
        
    }
};