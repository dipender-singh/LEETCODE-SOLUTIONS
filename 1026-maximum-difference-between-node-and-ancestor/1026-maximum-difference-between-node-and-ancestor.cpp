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
    
    int helper(TreeNode* root, int mx, int mn){
        if(root==NULL){
            return abs(mx-mn);
        }
        mx = max(root->val,mx);
        mn = min(root->val,mn);
        
        return max(helper(root->left,mx,mn),helper(root->right,mx,mn));
        
    }
    
    int maxAncestorDiff(TreeNode* root) {
        //Brute Force
        ios_base::sync_with_stdio(0);
        cin.tie(0);cout.tie(0);
//We are given a binary tree and we need to return the maximum absolute difference between a node and its ancestor
        int ans = 0;
        int mx = INT_MIN;
        int mn = INT_MAX;
        ans = helper(root,mx,mn);
        return ans;
    }
};