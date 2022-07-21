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
    
    int helper(TreeNode* p , TreeNode* q){
        if(p==NULL and q==NULL){
            return 0;
        }
        else if(p==NULL and q!=NULL){
            return -1;
        }
        else if(p!=NULL and q==NULL){
            return -1;
        }
        else if(p->val!=q->val){
            return -1;
        }
        else if(p->val!=q->val){
            return 0;
        }
        int l = helper(p->left,q->left);
        int r = helper(p->right,q->right);
        if(l==-1 || r ==-1){
            return -1;
        }
        return 0;
    }
    
    bool isSameTree(TreeNode* p, TreeNode* q) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);cout.tie(0);
        if(helper(p,q)==-1) return false;
        return true;
    }
};