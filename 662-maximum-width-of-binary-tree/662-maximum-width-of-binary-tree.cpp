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

    int widthOfBinaryTree(TreeNode* root) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);cout.tie(0);
        if(root==NULL){
            return 0;
        }
        long ans=0;
        queue<pair<TreeNode*,long long int>> q;//Along with the level we will store it's index also
        q.push({root,0});//Indexing the node's will start from 0
        while(q.size()!=0){
            int n = q.size();
            int mini = q.front().second;//Minimum index of that level will be present at the top of the queue
            long first,second;
            for(int i = 0 ; i < n ; i++){
                long curr_ind = q.front().second-mini; 
                TreeNode* temp = q.front().first;
                q.pop();
                if(i==0) first = curr_ind;
                if(i==n-1) second = curr_ind;
                if(temp->left) q.push({temp->left,(long long int)(2*curr_ind+1)});
                if(temp->right) q.push({temp->right,(long long int)(2*curr_ind+2)});
            }
            ans = max(ans,second-first+1);
        }
        return ans;
    }
};