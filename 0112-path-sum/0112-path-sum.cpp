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
    
    bool pathSum(TreeNode* root, int targetSum){
        if(root == NULL){
            return false;
        }
        targetSum = targetSum - root->val;
        if(root->left == NULL and root->right == NULL and targetSum == 0){
            return true;
        }
        return pathSum(root->left,targetSum) || pathSum(root->right,targetSum);
    }
    
    bool hasPathSum(TreeNode* root, int targetSum) {
        //Do a Dry Run a bit. 
        //Now when the TargetSum becomes equal to Zero, then we have to ensure that the Node at which we have got targetSum equal to Zero, that Node has to be a Leaf Node.
        if(root == NULL){
            return NULL;
        }
        return pathSum(root,targetSum);
    }
};