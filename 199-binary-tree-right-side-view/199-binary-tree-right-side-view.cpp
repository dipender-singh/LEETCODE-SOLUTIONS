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

//Current Solution:-    
//So what we will do is we will do a level order traversal and will traverse on each level for exactly it's 
//(size-1) times, doing this when we will reach to the last element of our level which is stored in our queue 
//and we will exit out of the loop through which we were traversing. Then simply we will store that node's 
//value in our ans vector and then will store it's left and right child into our queue if they exist 
    vector<int> rightSideView(TreeNode* root) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);cout.tie(0);
        vector<int> ans;
        queue<TreeNode*> q;
        if(root==NULL){
            return {};
        }
        q.push(root);
        while(q.size()!=0){//TC IS O(n)
            int n = q.size();//If suppose k is the size of each level
            for(int i = 0 ; i < n-1 ; i++){//TC is O(k-1)
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
        //TC IS O(N*K)
        //SC IS O(N)
    }
};