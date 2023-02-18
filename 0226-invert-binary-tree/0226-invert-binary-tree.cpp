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
    
    TreeNode* helper(TreeNode *root){
        //Base Case
        if(root==NULL){
            return NULL; 
        }
        TreeNode* l = helper(root->left);
        TreeNode* r = helper(root->right);
        if(l!=NULL || r!=NULL){
            TreeNode* temp1 = l;
            TreeNode* temp2 = r;
            root->right = temp1;
            root->left = temp2;
        }
        return root;
    }
    
    TreeNode* invertTree(TreeNode* root) {
        //Brute Force
        ios_base::sync_with_stdio(0);
        cin.tie(0);cout.tie(0);
        return helper(root);
    }
};