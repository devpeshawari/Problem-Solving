class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int n = students.size();
        int count = 0;
        int i = 0;
        queue<int> qu;
        for(int i = 0; i < n; i++){
            qu.push(students[i]);
        }

        while(i < n && count < qu.size()){
            if(sandwiches[i] == qu.front()){
                qu.pop();
                count = 0;
                i++;
            }
            else{
                count++;
                int temp = qu.front();
                qu.pop();
                qu.push(temp);
            }
        }   

        return qu.size();   
    }    
};