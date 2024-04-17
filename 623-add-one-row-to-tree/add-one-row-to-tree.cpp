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
    void help(TreeNode * node, int val, int depth){
        if(node == NULL){
            return;
        }    

        if(depth == 2){
        
                TreeNode * newHeadl = new TreeNode(val);
                TreeNode * temp = node->left;
                node->left = newHeadl;
                newHeadl->left = temp;    
            
           
                TreeNode * newHeadr = new TreeNode(val);
                temp = node->right;
                node->right = newHeadr;
                newHeadr->right = temp;     
            
            return;
        }

        help(node->left,val, depth - 1);
        help(node->right,val, depth - 1);

    }
    
    
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth == 1){
            TreeNode * head = new TreeNode(val);
            head->left = root;
            return head;
        }
        help(root,val,depth);
        return root;
    }
};