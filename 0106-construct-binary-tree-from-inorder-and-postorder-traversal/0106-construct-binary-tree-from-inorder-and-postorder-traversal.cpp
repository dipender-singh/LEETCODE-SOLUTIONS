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

/*

Now a very simple and to note thing what is our Preorder Traversal -> Root , Left , Right. Now that means that after the Root Node we have the elements of the Left Sub Tree so we will make the Left Sub Tree First. 

Similarly we have PostOrder Traversal here and it is -> Left , Right , Root. Now when we move from the behind first we encounter the RootNode after that we have the elements of the Right Sub Tree so what we have to do is that we will after creating the RootNode will build the Right Sub Tree first, then we will build the Left Sub Tree.

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
        //Time Complexity: O(n)
        //Space Complexity: O(n) 
    }
};
