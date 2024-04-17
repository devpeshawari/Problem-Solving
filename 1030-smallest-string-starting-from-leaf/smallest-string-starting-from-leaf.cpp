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
    void help(TreeNode * node, string s, vector<string> &sol){
        if(node == NULL){
            return;
        }
        if(node->left == NULL && node->right == NULL){
            s+= char('a' + node->val);
            reverse(s.begin(), s.end());
            sol.push_back(s);
            return;
        }
        s+= char('a' + node->val); 
        help(node->left, s, sol);
        help(node->right, s, sol);
        
        
        
    }   
    
    string smallestFromLeaf(TreeNode* root) {
        vector<string> sol;
        help(root,"",sol);
        sort(sol.begin(),sol.end());
        return sol[0];
    }
};