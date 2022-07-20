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
    //I guess we will find the height of the left sub tree and find the height of the right sub tree then return 
    //whichever is the max value
    int height(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        int l = 1+height(root->left);
        int r = 1+height(root->right);
        return max(l,r); 
    }
    
    int maxDepth(TreeNode* root) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);cout.tie(0);
        int rans = 0;
        int lans = 0;
        if(root==NULL){
            return 0;
        }
        lans = height(root->left);
        rans = height(root->right);
        int ans = max(rans,lans);
        return 1+ans;
    }
};