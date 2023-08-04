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
    
    TreeNode* helper(TreeNode* root, TreeNode* p ,TreeNode* q){
        if(root == NULL){
            return NULL;
        }
        if(root == p){
            return p;
        }
        else if(root == q){
            return q;
        }
        TreeNode* l = helper(root->left,p,q);
        TreeNode* r = helper(root->right,p,q);
        if(l!=NULL and r!=NULL){
            return root;
        }
        if(l==NULL){
            return r;
        }
        return l;
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL){
            return NULL;
        }
        return helper(root,p,q);
    }
};