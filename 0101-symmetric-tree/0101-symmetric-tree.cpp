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
    bool isSymmetric(TreeNode* root) {
        //BFS
        if(root -> left == NULL and root->right == NULL){
            return true;
        }
        queue<pair<TreeNode*,TreeNode*>> q;
        q.push({root->left,root->right});
        while(q.size()!=0){
            TreeNode* curr1 = q.front().first;
            TreeNode* curr2 = q.front().second;
            q.pop();
            if(curr1 == NULL and curr2 == NULL){
                continue;
            }
            if(curr1==NULL || curr2 == NULL){
                return false;
            }
            if(curr1 -> val != curr2->val){
                return false;
            }
            q.push({curr1->left,curr2->right});
            q.push({curr1->right,curr2->left});
        }
        return (q.size()==0);
    }
};