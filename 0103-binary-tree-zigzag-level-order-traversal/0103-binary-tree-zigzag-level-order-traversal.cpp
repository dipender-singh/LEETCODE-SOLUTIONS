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
        //Brute Force
        ios_base::sync_with_stdio(0);
        cin.tie(0);cout.tie(0);
        vector<int> ans;
        vector<vector<int>> f_ans = {};
        if(root==NULL){
            return f_ans;
        }
        queue<TreeNode*> q;
        int curr_level = 0;
        q.push(root);
        while(q.size()!=0){
            //Now we have to get the number of elements in the current level of the tree and that we can find 
            //from the size of the queue.
            int s = q.size();
            for(int i = 0 ; i < s ; i++){
                TreeNode* curr = q.front();
                q.pop();
                ans.push_back(curr->val);
                if(curr->left!=NULL) q.push(curr->left);
                if(curr->right!=NULL) q.push(curr->right);
            }
            //Now we have to check that previously we were at which level even or odd.
            if(curr_level%2==0){
                f_ans.push_back(ans);
            }
            else{
                reverse(ans.begin(),ans.end());
                f_ans.push_back(ans);
            }
            curr_level++;
            ans={};
        }
        return f_ans;
    }
};