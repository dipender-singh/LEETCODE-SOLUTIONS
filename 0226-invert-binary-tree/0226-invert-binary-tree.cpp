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
    /*
    TreeNode* helper(TreeNode *root){
        //Base Case
        if(root==NULL){
            return NULL; 
        }
        TreeNode* l = helper(root->left);
        TreeNode* r = helper(root->right);
        if(l!=NULL || r!=NULL){
            TreeNode* temp1 = l;
            TreeNode* temp2 = r;
            root->right = temp1;
            root->left = temp2;
        }
        return root;
    }
    
    TreeNode* invertTree(TreeNode* root) {
        //Brute Force-> Can also further optimize it and can think of more better approaches also. 
        ios_base::sync_with_stdio(0);
        cin.tie(0);cout.tie(0);
        return helper(root);
    }
    */
    //Will try to use BFS
    TreeNode* invertTree(TreeNode* root){
        ios_base::sync_with_stdio(0);
        cin.tie(0);cout.tie(0);
        if(root==NULL){
            return NULL;
        }
        queue<TreeNode*> q;
        q.push(root);
        while(q.size()!=0){
            //Now what the BFS does is, it store's all the Nodes of a level in the Queue
            TreeNode* first = q.front();
            q.pop();
            if(first->left!=NULL) q.push(first->left);
            if(first->right!=NULL) q.push(first->right);
            
            //Now just swap the both the nodes
            TreeNode* temp1 = first->left;
            first->left = first->right;
            first->right = temp1;
        }
        return root;
    }
};