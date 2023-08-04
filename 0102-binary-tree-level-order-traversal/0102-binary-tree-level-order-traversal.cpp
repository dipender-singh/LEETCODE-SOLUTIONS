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
    vector<vector<int>> levelOrder(TreeNode* root) {
        //Will simply use the Level Order Traversal using Queue (Basically by performing BFS)
        //Ok so each level will be a vector in itself.
        if(root == NULL){
            return {};
        }
        vector<vector<int>> ans;
        vector<int> level;
        queue<TreeNode*> q;
        q.push(root);
        while(q.size()!=0){
            int n = q.size();
            level = {};
            for(int i = 0 ; i < n ; i++){
            TreeNode* curr = q.front();
            q.pop();
            if(curr -> left) q.push(curr -> left);
            if(curr -> right) q.push(curr -> right);
            level.push_back(curr -> val);
            }
            ans.push_back(level);
        }
        return ans;
    }
};