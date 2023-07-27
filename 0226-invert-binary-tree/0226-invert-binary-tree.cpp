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
    TreeNode* invertTree(TreeNode* root) {
       //Brute Force
        if(root == NULL){
            return NULL;
        }
        TreeNode* l = NULL;
        TreeNode* r = NULL;
        if(root -> left) {
             l = invertTree(root->left);
        }
        if(root -> right) {
             r = invertTree(root->right);
        }
        root -> left = r;
        root -> right = l;
        return root;
    }
};