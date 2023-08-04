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
    vector<int> rightSideView(TreeNode* root) {
        //Can solve this via Level Order Traversal.
        //We just have to print the Last Element of Each Level.
        if(root == NULL){
            return {};
        }
        vector<int> ans;
        queue<TreeNode*> q;
        q.push(root);
        while(q.size()!=0){
            int i = q.size();
            while(i!=1){
                TreeNode* curr = q.front();
                q.pop();
                if(curr->left) q.push(curr -> left);
                if(curr->right) q.push(curr -> right);
                i--;
            }
            TreeNode* last = q.front();
            q.pop();
            ans.push_back(last->val);
            if(last -> left) q.push(last -> left);
            if(last -> right) q.push(last -> right);
        }
        return ans;
    }
};