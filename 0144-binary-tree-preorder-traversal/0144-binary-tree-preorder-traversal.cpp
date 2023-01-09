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
        //Base Case
        if(root==NULL){
            return ;
        }
        ans.push_back(root->val);
        helper(root->left,ans);
        helper(root->right,ans);
    }
    
    vector<int> preorderTraversal(TreeNode* root) {
        //There are Two ways one is Recursion adn the other way is by using Stack
        //Recursion
        vector<int> ans;
        /*if(root==NULL){
            ans.push_back(root);
            return ans;
        }*/
        helper(root,ans);
        return ans;
    }
};