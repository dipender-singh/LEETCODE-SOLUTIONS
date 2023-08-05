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
    int max_path = INT_MIN;
    int pathSum(TreeNode* root){
        if(root == NULL){
            return 0;
        }
        int l = pathSum(root -> left);
        int r = pathSum(root -> right);
        int path1 = root -> val + l;
        int path2 = root -> val + r;
        int path3 = root -> val + l + r;
        int path4 = root -> val;
        max_path = max(max_path,max(path1,max(path2,max(path3,path4))));
        return max(path4,max(path1,path2));
    }
    
    int maxPathSum(TreeNode* root) {
        pathSum(root);
        return max_path;
    }
};