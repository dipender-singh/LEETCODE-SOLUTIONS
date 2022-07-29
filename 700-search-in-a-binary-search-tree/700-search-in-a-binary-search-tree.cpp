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
    
    TreeNode* searchBST(TreeNode* root, int val) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);cout.tie(0);
        if(root==NULL){
            return NULL;
        }       
        while(root!=NULL){
            if(root->val == val){
                return root;
            }
            else if(root->val < val){
                root=root->right;
            }
            else if(root->val > val){
                root=root->left;
            }
        }
        return root;
    }
};