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
    int sol = INT_MIN;
    int help(TreeNode * node){
        if(node == NULL) return 0;
        int left = max(help(node->left),0);
        int right = max(help(node->right),0);
        sol = max(sol,(node->val + left + right));
        return max(node->val + left,node->val + right);
    }
    
    int maxPathSum(TreeNode* root) {
        help(root);
        return sol;
    }
};