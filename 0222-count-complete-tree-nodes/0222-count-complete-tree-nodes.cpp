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
    
    int height(TreeNode* root){
        if(root == NULL){
            return 0;
        }
        return 1 + height(root -> left) + height(root -> right);
    }
    
    int heightr(TreeNode* root){
        if(root == NULL){
            return 0;
        }
        int ans = 1;
        while(root -> right!=NULL){
            ans++;
            root = root -> right;
        }
        return ans;
    }
    int heightl(TreeNode* root){
        if(root == NULL){
            return 0;
        }
        int ans = 1;
        while(root -> left){
            ans++;
            root = root -> left;
        }
        return ans;
    }
    
    int countNodes(TreeNode* root) {
        //How this Concept of Finding the Number of Nodes is related to the Height of the Binary Tree.
        //What is the Total Number of Nodes if a Binary Tree is a Perfect Binary Tree.
        
        //Ok so the Concept here is to check for the Perfect Binary Tree, if the height of the Left Sub Tree is same as that the Height of the Right SubTree then we can say that the Tree is a Perfect Binary Tree and we can use the Direct Formula to Calculate the Number of Nodes in the Perfect Binary Tree, else we can go and calculate the Number of Nodes Recursively.
        if(root == NULL){
            return 0;
        }
        int l = heightl(root -> left);
        int r = heightr(root -> right);
        
        if( l == r){ //Means that the Tree is a Perfect Binary Tree. 
            return (pow(2,l+1)-1);
        }
        return height(root);
    }
};