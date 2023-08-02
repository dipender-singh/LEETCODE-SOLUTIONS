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
    
    int helper(TreeNode* root, int num){
        if(root == NULL){
            return 0;
        }
        if(root->left == NULL and root->right == NULL){
            return root->val + num*10;
        }
        num = num * 10 + root -> val;
        int l = helper(root -> left, num);
        int r = helper(root -> right, num);
        return l+r;
    }
    
    int sumNumbers(TreeNode* root) {
        return helper(root,0);
    }
};