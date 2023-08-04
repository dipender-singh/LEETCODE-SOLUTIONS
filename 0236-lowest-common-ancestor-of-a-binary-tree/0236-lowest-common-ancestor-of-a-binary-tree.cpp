/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    
    TreeNode* helper(TreeNode* root, TreeNode* p ,TreeNode* q){
        if(root == NULL){
            return NULL;
        }
        if(root == p || root == q){
            return root;
        }
        TreeNode* l = helper(root->left,p,q);
        TreeNode* r = helper(root->right,p,q);
        if(l!=NULL and r!=NULL){
            return root;
        }
        if(l==NULL){
            return r;
        }
        return l;
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL){
            return NULL;
        }
        return helper(root,p,q);
        //Time Complexity : O(N) in the Worst Case.
        //Space Complexity : O(H) in the Worst Case.
    }
};