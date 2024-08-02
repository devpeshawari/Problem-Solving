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
    int height(TreeNode * node, bool &sol){
        if(node == NULL) return 0;
        int left = 1 + height(node->left, sol);
        int right = 1 + height(node-> right, sol);
        if(abs(left - right) > 1){
            sol = false;
        }

        return max(left,right);
    }

    bool isBalanced(TreeNode* root) {
        bool sol = true;
        height(root,sol);

        return sol;    
    }
};