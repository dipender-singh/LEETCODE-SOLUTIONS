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
    int global = INT_MAX;
    TreeNode* prev = NULL;
    
    void helper(TreeNode* root){
        if(root == NULL){
            return ;
        }
        helper(root -> left);
        if(prev!=NULL){
            global = min(global,abs(root -> val - prev -> val));
        }
        prev = root;
        helper(root->right);
    }
    
    int getMinimumDifference(TreeNode* root) {
        //Now without using any Extra Space of N and thus Reducing the Space Complexity to O(H).
        helper(root);
        return global;
    }
};