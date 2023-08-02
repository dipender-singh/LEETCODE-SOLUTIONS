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
    int sumNumbers(TreeNode* root) {
        //Do using BFS -> DFS -> Morris Traversal. 
        stack<pair<TreeNode*,int>>q;
        q.push({root,0});
        int sum = 0;
        while(q.size()!=0){
            TreeNode* curr = q.top().first;
            int value = q.top().second;
            q.pop();
            value = curr->val+value*10;
            if(curr -> left) q.push({curr -> left, value});
            if(curr -> right) q.push({curr -> right, value});
            if(!curr->left and !curr->right) sum = sum + value;
        }
        return sum;
        //Time Complexity and Space Complexity are O(N) and O(H) respectively.
    }
};