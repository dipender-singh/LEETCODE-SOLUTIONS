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
//Using concept of Vertical and Levels as we discussed in the question: Vertical Order Traversal of B-Tree 
//Now according to me, I can say that we want the last element of every level of every vertical
    vector<int> rightSideView(TreeNode* root) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);cout.tie(0);
        vector<int> ans;
        queue<TreeNode*> q;
        if(root==NULL){
            return {};
        }
        q.push(root);
        while(q.size()!=0){
            int n = q.size();
            for(int i = 0 ; i < n-1 ; i++){
            TreeNode* temp = q.front();
            q.pop();
            if(temp->left!=NULL) q.push(temp->left);
            if(temp->right!=NULL) q.push(temp->right);   
            }
            TreeNode* temp = q.front();
            q.pop();
            int a = temp->val;
            ans.push_back(a);
            if(temp->left!=NULL) q.push(temp->left);
            if(temp->right!=NULL) q.push(temp->right);
        }
        return ans;
    }
};