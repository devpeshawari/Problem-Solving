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
    void help(TreeNode * node, vector<int> &sol){
        if(node == NULL){
            return;
        }
        help(node->left,sol);
        sol.push_back(node->val);
        help(node->right, sol);


        return;
    }
    
    
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> sol;
        help(root,sol);
        return sol;
    }
};