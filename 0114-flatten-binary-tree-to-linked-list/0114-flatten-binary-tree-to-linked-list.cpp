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
    
    void helper(TreeNode* root, vector<int>& ans){
        if(!root) return;
        ans.push_back(root -> val);
        helper(root->left,ans);
        helper(root->right,ans);
    }
    
    void flatten(TreeNode* root) {
        vector<int> ans;
        helper(root,ans);
        TreeNode* temp = root;
        for(int i = 1 ; i < ans.size() ; i++){
            temp -> left = NULL;
            TreeNode* node = new TreeNode(ans[i]);
            temp -> right = node;
            temp = temp -> right;
        }
    }
};