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
    int help(TreeNode * node){
        if(node == NULL){
            return 0;
        }
        int left = 1 + help(node->left);
        int right = 1 + help(node->right);


        return max(left,right);
    }
    
    int maxDepth(TreeNode* root) {
        return help(root);
    }
};