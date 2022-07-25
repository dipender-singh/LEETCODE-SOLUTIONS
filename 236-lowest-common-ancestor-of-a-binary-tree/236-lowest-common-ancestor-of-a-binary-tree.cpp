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
    
    TreeNode* find(TreeNode* root, TreeNode* p, TreeNode* q){
        if(root==NULL || root==p || root==q){
            return root;
        }
        TreeNode* l = find(root->left,p,q);
        TreeNode* r = find(root->right,p,q);
        if(l==NULL){
            return r;
        }
        else if(r==NULL){
            return l;
        }
        else{
            return root;
        }
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);cout.tie(0);
        TreeNode* temp = find(root,p,q);
        return temp;
    }
};