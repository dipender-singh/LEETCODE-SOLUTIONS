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
class BSTIterator {
public:
    vector<int> ans;
    int i = 0;
    void helper(TreeNode* root, vector<int>& ans){
        if(root == NULL){
            return;
        }
        helper(root -> left,ans);
        ans.push_back(root->val);
        helper(root -> right,ans);
    }
    
    BSTIterator(TreeNode* root) {
        helper(root,ans);
        
    }
    
    int next() {
        return ans[i++];
    }
    
    bool hasNext() {
        return (i < ans.size());
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */