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
    
    bool helper(TreeNode* p, TreeNode* q){
        //Nodes should have the same value
        //Structure should also be same
        if(p==NULL and q!=NULL){
            return false;
        }
        else if(p!=NULL and q==NULL){
            return false;
        }
        else if(p==NULL and q==NULL){
            return true;
        }
        if(p->val!=q->val){
            return false;
        }
        bool l = helper(p->left,q->left);
        bool r = helper(p->right,q->right);
        return (l&r);
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        //Brute Force
        ios_base::sync_with_stdio(0);
        cin.tie(0);cout.tie(0);
        return helper(p,q);
    }
};