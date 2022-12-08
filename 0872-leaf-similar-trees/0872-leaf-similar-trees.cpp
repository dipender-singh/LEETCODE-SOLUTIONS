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
    //Brute Force
    
    void helpertwo(TreeNode* root2, vector<int>& second){
        if(root2->left==NULL and root2->right==NULL){
            second.push_back(root2->val);
        }
        if(root2->left!=NULL) helpertwo(root2->left,second);
        if(root2->right!=NULL) helpertwo(root2->right,second);
    }
    
    void helperone(TreeNode* root1, vector<int>& first){
        if(root1->left == NULL and root1->right == NULL){
            first.push_back(root1->val);
        }
        if(root1->left!=NULL) helperone(root1->left,first);
        if(root1->right!=NULL) helperone(root1->right,first);
    }
    
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        //Brute Force
        ios_base::sync_with_stdio(0);
        cin.tie(0);cout.tie(0);
        vector<int> first;
        vector<int> second;
        helperone(root1,first);
        helpertwo(root2,second);
        int n = first.size();
        int m = second.size();
        if(n!=m){
            return false;
        }
        for(int i = 0 ; i < n ; i++){
            if(first[i]!=second[i]){
                return false;
            }
        }
        return true;
    }
};