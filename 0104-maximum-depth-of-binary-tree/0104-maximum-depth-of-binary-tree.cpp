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
    int maxDepth(TreeNode* root) {
        if(root == NULL){
            return NULL;
        }
        //Using BFS: Now Remember for BFS we always use Queue and for DFS: We alsways use Stack
        int ans = 0;
        queue<TreeNode*> q;
        q.push(root);
        while(q.size()!=0){
            ++ans;
            int s= q.size();
            for(int i = 0 ; i < s ; i++){
                TreeNode* curr = q.front();
                q.pop();
                if(curr -> left) q.push(curr -> left);
                if(curr -> right) q.push(curr -> right);
            }
        }
        return ans;
    }
};