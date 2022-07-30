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
    
    int insert(TreeNode* root, int val){
        if(root==NULL){
            return 0;
        }
        if(root->val > val){
            //Go to left
            int l = insert(root->left,val);
            if(l==0){
                //insert the node and attach that to the left of this root
                TreeNode* node = new TreeNode(val);
                root->left = node;
            }
        }
        else if (root->val < val){
            int r = insert(root->right,val);
            if(r==0){
                TreeNode* node = new TreeNode(val);
                root->right = node;
            }
        }
        return 1;
    }
    
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);cout.tie(0);
        //Now if we are given NULL as our root and we have to create a tree using the given Val
        if(root==NULL){
            TreeNode* node = new TreeNode(val);
            return node;
        }
        //Now after inserting the Node the tree should still be a BST
        insert(root,val);
        return root;
    }
};