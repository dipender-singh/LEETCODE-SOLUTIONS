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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        //Brute Force
        //Now here values should be the same and the Nodes Links should also be there. 
        if((p == NULL and q != NULL) || (p != NULL and q == NULL) ){
            return false;
        }
        else if( p == NULL and q == NULL){
            return true;
        }
        else if(p -> val != q -> val){
            return false;
        }
        bool l = true;
        l = isSameTree(p -> left, q -> left);
        bool r = true;
        r = isSameTree(p -> right, q -> right);
        return l and r;
    }
};