/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* help(TreeNode* node, TreeNode* p, TreeNode* q) {
        if(node == NULL){
            return NULL;
        }
        TreeNode * left = help(node->left,p,q);
        TreeNode * right = help(node->right,p,q);
        if(left == p && right == q){
            return node;
        } 
        if(node == p || node == q){
            return node;
        }    
        if(left == q && right == p){
            return node;
        }
        if(left != NULL && right == NULL){
            return left;
        }   
        if(left == NULL && right != NULL){
            return right;
        }  
        
        
        if(node->left == NULL && node->right ==NULL){
            return NULL;
        }

        return NULL;

    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return help(root,p,q);
    }
};