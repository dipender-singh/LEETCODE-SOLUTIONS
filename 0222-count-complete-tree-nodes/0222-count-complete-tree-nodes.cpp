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
/*
If we have to traverse in the Tree and have to use the Time Complexity to be less than O(n) so can we use Morris Traversal here or not ??
*/
class Solution {
public:
    
    int helper(TreeNode* root){
        if(root == NULL){
            return 0;
        }
        return 1 + helper(root -> left) + helper(root -> right);
    }
    
    int countNodes(TreeNode* root) {
        //Brute Force using Recursion:
        return helper(root);
    }
};