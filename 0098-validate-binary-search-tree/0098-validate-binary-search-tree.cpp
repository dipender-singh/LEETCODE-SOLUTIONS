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
    
    TreeNode* prev = NULL;
    
    bool helper(TreeNode* root){
        if(root == NULL){
            return true;
        }
        bool l = helper(root -> left);
        if(prev!=NULL and prev->val >= root ->val){
            return false;
        }
        prev = root;
        bool r = helper(root -> right);
        return l & r;
    }
    
    bool isValidBST(TreeNode* root) {
        //Can we use the Concept of PREV which we used in the Question 530. Minimum Absolute Difference in BST.
        //Will try to use the Concept of PREV Pointer here as well.
        
        bool ans = helper(root);
        return ans;
    }
};