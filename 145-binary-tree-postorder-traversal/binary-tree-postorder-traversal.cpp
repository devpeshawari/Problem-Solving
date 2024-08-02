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
        help(node->left, sol);
        help(node->right, sol);
        sol.push_back(node->val);


        return ;
    }
    
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> sol;

        help(root,sol);


        return sol;    
    }
};