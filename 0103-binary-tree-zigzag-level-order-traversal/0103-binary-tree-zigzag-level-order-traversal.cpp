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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        int h = 0;
//When we are at a Even Level we will have the Values in the Order of Right to Left, and in case of Odd Level Left to Right.
        if(root == NULL){
            return {};
        }
        vector<int> ans;
        vector<vector<int>> final_ans;
        queue<TreeNode*> q;
        q.push(root);
        while(q.size()!=0){
            int n = q.size();
                for(int i = 0 ; i < n ; i++){
                    TreeNode* curr = q.front();
                    q.pop();
                    if(curr -> left) q.push(curr -> left);
                    if(curr -> right) q.push(curr -> right);
                    ans.push_back(curr -> val);
                }
            if(h%2!=0){
                 reverse(ans.begin(),ans.end());
            }
            final_ans.push_back(ans);
            ans = {};
            h++;
        }
        return final_ans;
    }
};