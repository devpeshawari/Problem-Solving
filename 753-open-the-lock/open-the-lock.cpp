class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> vis;
        for(int i = 0; i < deadends.size(); i++){
            vis.insert(deadends[i]);
        }
        if(vis.find(target) != vis.end() || vis.find("0000") != vis.end() ){
            return -1;
        }
        queue<pair<string,int>> qu;
        qu.push({"0000",0});
        while(qu.size()){
            string node = qu.front().first;
            int count = qu.front().second;
            qu.pop();
            vis.insert(node);
            if(node == target){
                return count;
            }
            for(int i = 0; i < 4; i++){
                char newNum1 = char('0' + ((node[i] - '0') + 1)%10); 
                char newNum2 = char('0' + ((node[i] - '0') - 1 + 10)%10);
                string newNode1 = node;
                string newNode2 = node;
                newNode1[i] = newNum1;
                newNode2[i] = newNum2;
                if(vis.find(newNode1) == vis.end()){
                    vis.insert(newNode1); 
                    qu.push({newNode1,count + 1});
                }
                if(vis.find(newNode2) == vis.end()){
                    vis.insert(newNode2);
                    qu.push({newNode2,count + 1});
                } 
            }   
        }



        return -1;



        return -1;
    }
};