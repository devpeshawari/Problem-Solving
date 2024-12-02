class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        int n = sentence.size();
        int m = searchWord.size();
        int j = 0; 
        int counter = 1;
        for(int i = 0; i < n; i++){
            if(sentence[i] == searchWord[j]){
                j++;
            }
            else if(sentence[i] == ' '){
                j = 0;
                counter++;
            }
            else{
                j = 0;
                i++;
                counter++;
                while(i < n && sentence[i] != ' '){
                    i++;
                }
                
            }
            if(j == m){
                return counter;
            }
        }


        return -1;
    }
};