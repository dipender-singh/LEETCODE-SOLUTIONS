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
    int maxDepth(TreeNode* root) {
        //Brute Force
        //Recursion
        /*
        1. Base Case
        2. Recursive Call + Small Calculation
        3. Return Statement
        */
        if(root == NULL){
            return 0;
        }
        return 1 + max(maxDepth(root -> left), maxDepth(root -> right));
    }
};