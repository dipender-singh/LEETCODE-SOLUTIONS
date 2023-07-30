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
    bool hasPathSum(TreeNode* root, int targetSum) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);cout.tie(0);
        if(root == NULL){
            return NULL;
        }
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        int sum = 0;
        while(q.size()!=0){
            TreeNode* curr = q.front().first;
            sum = q.front().second;
            q.pop();
            sum += curr -> val; 
            if(curr -> left == NULL and curr -> right == NULL and sum == targetSum){
                return true;
            }
            if(curr -> left) q.push({curr->left,sum});
            if(curr -> right) q.push({curr->right,sum});
        }
        return false;
    }
};