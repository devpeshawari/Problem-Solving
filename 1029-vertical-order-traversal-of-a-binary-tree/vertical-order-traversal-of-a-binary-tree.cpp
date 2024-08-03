/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,multiset<int>>> mp;
        queue<pair<TreeNode *,pair<int,int>>> qu;
        if(root == NULL){
            return {};
        }
        qu.push({root,{0,0}});

        while(!qu.empty()){
            int size = qu.size();
            for(int i = 0; i < size; i++){
                TreeNode * node = qu.front().first;
                int y = qu.front().second.first;
                int x = qu.front().second.second;
                mp[y][x].insert(node->val);
                if(node->left != NULL) qu.push({node->left,{y - 1,x + 1}});
                if(node->right != NULL) qu.push({node->right,{y + 1,x + 1}});
                qu.pop();
            }
        }

        vector<vector<int>> sol;

        for(auto it: mp){
            vector<int> temp;
            for(auto it1: it.second){
                for(auto it2: it1.second){
                    temp.push_back(it2);
                }
            }
            sol.push_back(temp);
        }
        

        return sol;
    }
};