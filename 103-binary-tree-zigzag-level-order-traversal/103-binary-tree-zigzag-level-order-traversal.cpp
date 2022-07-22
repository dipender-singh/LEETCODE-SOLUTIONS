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
        //We will keep a count that will tell us to know that we have to reverse our vector or not
        //We will run a loop form 0 to the initial size of the queue before a for loop to get all the elements 
        //of a level in the ans vector  
        ios_base::sync_with_stdio(0);
        cin.tie(0);cout.tie(0);
        vector<int> ans;
        vector<vector<int>> f_ans;
        int cnt=0;
        if(root==NULL){
            return {};
        }
        cnt+=1;
        queue<TreeNode*> q;
        q.push(root);
        while(q.size()!=0){
         int s = q.size();//This will help us to get the number of elements in a particular level 
            ans={};
            for(int i = 0 ; i < s ; i++){
                TreeNode* temp = q.front();
                q.pop();
                ans.push_back(temp->val);
                if(temp->left!=NULL) q.push(temp->left);
                if(temp->right!=NULL) q.push(temp->right);
            }
            if(cnt%2==0){
                reverse(ans.begin(),ans.end());
            }
            cnt++;
            f_ans.push_back(ans);
        }
        return f_ans;
    }
};