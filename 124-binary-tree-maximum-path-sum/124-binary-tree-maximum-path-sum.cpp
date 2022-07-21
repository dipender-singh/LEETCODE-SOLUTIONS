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
    int max_path=INT_MIN;
    
    int helper(TreeNode* root){
        if(!root)return 0;
        int lv = max(helper(root->left),0); // Because i want to eleiminate the negative values
        int rv = max(helper(root->right),0);
        max_path = max(max_path,root->val+lv+rv);
        return root->val+max(lv,rv);
    }
    
    int maxPathSum(TreeNode* root) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);cout.tie(0);
        helper(root);
        return max_path;
    }
};