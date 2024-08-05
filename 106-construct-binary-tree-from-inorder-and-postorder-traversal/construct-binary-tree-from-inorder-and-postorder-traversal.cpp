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
    TreeNode* help(int i, int j, int x, vector<int>& inorder, vector<int>& postorder, unordered_map<int,int> &mp) {
        if(i > j){
            return NULL;
        }
        TreeNode * head = new TreeNode(postorder[x]);
        int pivot = mp[postorder[x]];

        head->right = help(pivot + 1,j,x - 1,inorder,postorder, mp);
        head->left = help(i,pivot - 1,x - (j - pivot + 1),inorder,postorder, mp);
        return head;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = postorder.size();
        unordered_map<int,int> mp;
        for(int i = 0; i < n; i++){
            mp[inorder[i]] = i;
        }

        return help(0,n - 1,n - 1,inorder,postorder,mp);
        
    }
};