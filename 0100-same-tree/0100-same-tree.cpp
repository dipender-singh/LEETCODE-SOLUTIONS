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
        //Will try to solve using BFS and DFS
        //First BFS: 
        queue<TreeNode*> q1;
        queue<TreeNode*> q2;
        if(p == NULL and q!= NULL || p!=NULL and q == NULL){
            return false;
        }
        if( p == NULL and q == NULL){
            return true;
        }
        q1.push(p);
        q2.push(q);
        while(q1.size()!=0 and q2.size()!=0){
            TreeNode* curr1 = q1.front();
            TreeNode* curr2 = q2.front();
            q1.pop();
            q2.pop();
            
        if((curr1 -> left==NULL and curr2 -> left!=NULL) || (curr1 -> left!=NULL and curr2 -> left==NULL)) return false;
            if( (!curr1 -> right and curr2 -> right) || (curr1 -> right and !curr2 -> right)) return false;
            if( curr1 -> val != curr2 -> val ) return false;
            if(curr1 -> left) q1.push(curr1 -> left);
            if(curr1 -> right) q1.push(curr1 -> right);
            if(curr2 -> left) q2.push(curr2 -> left);
            if(curr2 -> right) q2.push(curr2 -> right);
        }
        if( (q1.size() == 0 and q2.size() != 0) || (q1.size()!=0 and q2.size() == 0) ){
            return false;
        }
        return true;
    }
};