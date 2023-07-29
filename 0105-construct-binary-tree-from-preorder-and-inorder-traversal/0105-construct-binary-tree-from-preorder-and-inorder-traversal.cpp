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
    TreeNode* build(vector<int>& preorder, vector<int>& inorder,int i, int l, int r){
        if(l > r){
            return NULL;
        }
        TreeNode* root = new TreeNode(preorder[i++]);
        int pos = 0;
        for(int j = l ; j <= r ; j++){
            if(inorder[j] == root->val){
                pos = j;
                break;
            }
        }
        root -> left = build(preorder,inorder,i,l,pos-1);
        root -> right = build(preorder,inorder,i,pos+1,r);
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return build(preorder,inorder,0,0,inorder.size()-1);
    }
    */
    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int& i, int left, int right){
        if(left > right){
            return NULL;
        }
        TreeNode* root = new TreeNode(preorder[i++]);
        int pos = 0;
        for(int j = left ; j <= right ; j++){
            if(inorder[j] == root->val){
                pos = j;
                break;
            }
        }
        root -> left = build(preorder, inorder, i, left, pos-1);
        root -> right = build(preorder, inorder, i, pos+1, right);
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int index = 0;
        return build(preorder, inorder, index, 0, inorder.size()-1);
    }
};