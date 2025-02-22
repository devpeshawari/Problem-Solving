/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

    TreeNode * findLCA(TreeNode * node, TreeNode * p, TreeNode * q){
        if(node == NULL) return NULL;
        if(node == p) return p;
        if(node == q) return q;
        TreeNode * leftTree = findLCA(node->left,p,q);
        TreeNode * rightTree = findLCA(node->right,p,q);
        if((leftTree == p || rightTree == p) && (leftTree == q || rightTree == q)) return node;
        if(leftTree != NULL ) return leftTree;
        if(rightTree != NULL) return rightTree;

        return NULL;
    }
    
    



class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return findLCA(root,p,q);
    }
};