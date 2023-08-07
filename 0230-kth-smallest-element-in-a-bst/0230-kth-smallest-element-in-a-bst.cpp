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
    
    int helper(TreeNode* root, int& k){
        if(root == NULL){
            return -1;
        }
        int l = -1;
        int r = -1;
        l = helper(root -> left,k);
        if(k == 0){
            return prev -> val;
        }
        k--;
        prev = root;
        r = helper(root -> right,k);
        if(l != -1){
            return l;
        }
        return r;
    }
    
    int kthSmallest(TreeNode* root, int k) {
        
        //This  concept of Subtracting "k" is working just have to check for some steps like what to return and where to subtract the value. 
        int ans = 0;
        if(root -> left == NULL and root -> right == NULL and k == 1) {
            return root->val;
        }
        ans = helper(root,k);
        if(prev!=NULL and ans == -1){
            return prev->val;
        }
        return ans;
    }
};