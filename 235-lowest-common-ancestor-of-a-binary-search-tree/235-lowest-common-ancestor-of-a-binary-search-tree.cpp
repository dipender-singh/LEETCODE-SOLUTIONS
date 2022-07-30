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
    
    TreeNode* helper(TreeNode* root, TreeNode* p, TreeNode* q){
        if(root==NULL || root==p || root==q){
            return root;
        }
        TreeNode* l = helper(root->left,p,q);
        TreeNode* r = helper(root->right,p,q);
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
        //Take Idea from LCA of BT
        ios_base::sync_with_stdio(0);
        cin.tie(0);cout.tie(0);
        TreeNode* a;
        TreeNode* b;
        if(p->val < q->val){
            a=p;
            b=q;
        }
        else{
            a=q;
            b=p;
        }
        TreeNode* ans = helper(root,a,b);
        return ans;
    }
};