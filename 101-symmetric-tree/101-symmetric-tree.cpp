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
    
    bool find(TreeNode* root1 , TreeNode* root2){
        if(root1==NULL and root2==NULL){
            return true;
        }
        else if(root1!=NULL and root2==NULL){
            return false;
        }
        else if(root1==NULL and root2!=NULL){
            return false;
        }
        else if(root1->val!=root2->val){
            return false;
        }
        bool l = find(root1->left,root2->right);
        bool r = find(root1->right,root2->left);
        bool a = l and r;
        return true and a;
    }
    
    bool isSymmetric(TreeNode* root) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);cout.tie(0);
        bool ans = false;
        if(root==NULL){
            return true;
        }
       // else if(root->left!=NULL and root->right!=NULL){
        ans = find(root->left,root->right);
        //}
        return ans;
    }
};