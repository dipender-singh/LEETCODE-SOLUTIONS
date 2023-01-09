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
    void helper(TreeNode* root, vector<int>& ans){
        //Base Case
        if(root==NULL){
            return ;
        }
        ans.push_back(root->val);
        helper(root->left,ans);
        helper(root->right,ans);
    }
    */
    
    vector<int> preorderTraversal(TreeNode* root) {
        //There are Two ways one is Recursion adn the other way is by using Stack
        //Recursion Time Complexity is O(n) and the Space Complexity is also O(n)[Internal Stack Space is used].
        vector<int> ans;
        //Iteratively
        stack<TreeNode*> st;
        //Just store the root in the stack and then pop it store it in the vector then store the
        //Right pehle dalega then Left dalega then again pop karke unki value dali jayegi and then unko
        if(root==NULL){
            return {};
        }
        st.push(root);
        while(st.size()!=0){
            TreeNode* current = st.top();
            st.pop();
            ans.push_back(current->val);
            if(current->right!=NULL) st.push(current->right);
            if(current->left!=NULL) st.push(current->left);
        }
        return ans;
    }
};