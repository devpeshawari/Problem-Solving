class Solution {
public:

    int lengthOfLongestSubstring(string s) {
        int n = s.size(); //the size of our string
        int j = 0;//which is the left pointer
        int sol = 0;
        unordered_set<char> mp;
        for(int i = 0; i < n; i++){
            if(mp.find(s[i]) != mp.end()){ //checking if the current element is in the map
                while(j < n && s[j] != s[i] ){
                    mp.erase(s[j]);
                    j++;
                }
                j++;
            }
            cout << j << " ";
            sol = max(i - j + 1, sol);
            mp.insert(s[i]);
        }

        return sol;
    }
};