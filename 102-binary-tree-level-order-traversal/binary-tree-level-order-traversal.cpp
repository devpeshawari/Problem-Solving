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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> sol;
        if(root == NULL){
            return {};
        }         
        queue<TreeNode *> qu;
        qu.push(root);
        while(!qu.empty()){
            int size = qu.size();
            vector<int> temp;
            for(int i = 0; i < size; i++){
                TreeNode * node = qu.front();
                temp.push_back(node->val);
                if(node->left != NULL) qu.push(node->left);
                if(node->right != NULL) qu.push(node->right);
                qu.pop();
            }
            sol.push_back(temp);
        }

        return sol;
    }
};