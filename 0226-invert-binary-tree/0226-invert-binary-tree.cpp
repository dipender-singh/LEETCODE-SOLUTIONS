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
    TreeNode* invertTree(TreeNode* root) {
        //Now will Try to Solve using BFS and DFS.
        //First will Try using the BFS Approach.
        if(root == NULL){
            return NULL;
        }
        queue<TreeNode*> q;
        q.push(root);
        while(q.size()!=0){
            TreeNode* curr = q.front();
            q.pop();
            if(curr -> left) q.push(curr -> left);
            if(curr -> right) q.push(curr -> right);
            TreeNode* l = curr -> left;
            TreeNode* r = curr -> right;
            curr -> left = r;
            curr -> right = l;
        }
        return root;
    }
};