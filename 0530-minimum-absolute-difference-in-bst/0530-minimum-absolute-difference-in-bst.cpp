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
    
    void helper(TreeNode* root, vector<int>& ans){
        if(root == NULL){
            return;
        }
        helper(root -> left,ans);
        ans.push_back(root -> val);
        helper(root -> right,ans);
    }
    
    int getMinimumDifference(TreeNode* root) {
        vector<int> ans;
        helper(root,ans);
        int finalans = INT_MAX;
        for(int i = 1 ; i < ans.size() ; i++){
            finalans = min(finalans,abs(ans[i-1]-ans[i]));
        }
        return finalans;
    }
};