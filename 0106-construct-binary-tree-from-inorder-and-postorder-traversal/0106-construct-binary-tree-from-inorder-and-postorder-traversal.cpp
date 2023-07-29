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
    TreeNode* build(vector<int>& inorder, vector<int>& postorder, int& i, int left, int right) {
        if (left > right) {
            return nullptr;
        }
        TreeNode* root = new TreeNode(postorder[i--]); // Decrement i before using it
        int pos = 0;
        for (int j = left; j <= right; j++) {
            if (inorder[j] == root->val) {
                pos = j;
                break;
            }
        }
        root->right = build(inorder, postorder, i, pos + 1, right);
        root->left = build(inorder, postorder, i, left, pos - 1);
        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = postorder.size() - 1;
        return build(inorder, postorder, n, 0, n);
    }
};
