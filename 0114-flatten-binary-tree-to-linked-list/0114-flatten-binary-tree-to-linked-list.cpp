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
    
    void helper(TreeNode* root){
        if(root == NULL) return;                                                                                         
        helper(root -> left);
        helper(root -> right);
        TreeNode* temp = root -> right;
        TreeNode* t = root;
        root -> right = root -> left;
        root -> left = NULL;
        while(t -> right != NULL){
            t = t -> right;
        }
        t -> right = temp;
    }
    
    void flatten(TreeNode* root) {
        helper(root);
    }
};