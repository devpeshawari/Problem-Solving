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
    TreeNode* help(int i, int j,int x, vector<int>& preorder, vector<int>& inorder,unordered_map<int,int> &mp) {
        int n = preorder.size();
        if(i > j){
            return NULL;
        }
        int pivot = mp[preorder[x]];
        TreeNode * head = new TreeNode(preorder[x]);
        
        head->left = help(i,pivot - 1,x + 1,preorder,inorder,mp);
        head->right = help(pivot + 1,j,x + pivot - i + 1,preorder,inorder,mp);  

        return head;

    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        TreeNode * head = new TreeNode(preorder[0]);
        unordered_map<int,int> mp;
        for(int i = 0; i < n; i++){
            mp[inorder[i]] = i; 
        }


        return help(0,n - 1,0,preorder,inorder,mp);

    }
};