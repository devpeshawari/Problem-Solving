class Solution {
public:
    void solve(int i, int n, char prev,string currStr, vector<string> &sol){
        if(i == n){
            sol.push_back(currStr);
            return;
        }
        if(prev != 'a'){
            solve(i + 1,n,'a',currStr+'a',sol);
        }
        if(prev != 'b'){
            solve(i + 1,n,'b',currStr+'b',sol);
        }
        if(prev != 'c'){
            solve(i + 1,n,'c',currStr+'c',sol);
        }
    }
    
    
    string getHappyString(int n, int k) {
        vector<string> allStrings;

        solve(0,n,'d',"",allStrings);
        sort(allStrings.begin(),allStrings.end());
        cout << allStrings.size();
        if(k > allStrings.size()) return "";
        return allStrings[k - 1];
    }
};