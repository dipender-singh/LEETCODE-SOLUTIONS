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
    TreeNode* pre = NULL;
    int ans = INT_MAX;
    void helper(TreeNode* root){
        if(root==NULL){
            return ;
        }
        helper(root->left);
        if(pre!=NULL){
            ans = min(ans,abs((pre->val)-(root->val)));
        }
        pre = root;
        helper(root->right);
    }
    
    int minDiffInBST(TreeNode* root) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);cout.tie(0);
        helper(root);
        return ans;
    }
};