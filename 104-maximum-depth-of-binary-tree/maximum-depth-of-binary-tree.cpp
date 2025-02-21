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
    // root is null -> 0;
    // if I have just 1 node height is 1;
    // height of tree is equal to currNode + max(leftSubTree,rightSubTree)

    
    
    int maxDepth(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        int leftSide = maxDepth(root->left);
        int rightSide = maxDepth(root->right);

        return 1 + max(leftSide,rightSide);    
    }
};