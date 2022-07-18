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
    
    void postorder(TreeNode* root , vector<int>& ans){
        if(root==NULL){
            return;
        }
        postorder(root->left,ans);
        postorder(root->right,ans);
        ans.push_back(root->val);
    }
    
    vector<int> postorderTraversal(TreeNode* root) {
        //PostOrder:- left, right, root
        ios_base::sync_with_stdio(0);
        cin.tie(0);cout.tie(0);
        vector<int> ans;
        postorder(root,ans);
        return ans;
    }
};