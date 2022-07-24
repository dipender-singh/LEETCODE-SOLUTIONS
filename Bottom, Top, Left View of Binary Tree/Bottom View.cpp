/*
Given a binary tree, print the bottom view from left to right.
A node is included in bottom view if it can be seen when we look at the tree from bottom.

                      20
                    /    \
                  8       22
                /   \        \
              5      3       25
                    /   \      
                  10    14

For the above tree, the bottom view is 5 10 3 14 25.
If there are multiple bottom-most nodes for a horizontal distance from root, then print the later one in level traversal. For example, in the below diagram, 3 and 4 are both the bottommost nodes at horizontal distance 0, we need to print 4.

                      20
                    /    \
                  8       22
                /   \     /   \
              5      3 4     25
                     /    \      
                 10       14

For the above tree the output should be 5 10 4 14 25.
 

Example 1:

Input:
       1
     /   \
    3     2
Output: 3 1 2
Explanation:
First case represents a tree with 3 nodes
and 2 edges where root is 1, left child of
1 is 3 and right child of 1 is 2.

Thus nodes of the binary tree will be
printed as such 3 1 2.
Example 2:

Input:
         10
       /    \
      20    30
     /  \
    40   60
Output: 40 20 60 30
Your Task:
This is a functional problem, you don't need to care about input, just complete the function bottomView() which takes the root node of the tree as input and returns an array containing the bottom view of the given tree.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).

Constraints:
1 <= Number of nodes <= 105
1 <= Data of a node <= 105

*/
class Solution {
  public:
    vector <int> bottomView(Node *root) {
        // Your Code Here
        //The logic is simple here for every vertical line we have to print the last element of
        //every vertical line
        queue<pair<int,Node*>> q;//This queue will help us to iterate in a level order traversal type
        vector<int> ans;
        map<int,int> mp;//This map will help us to store the data of each node with the key as the number of the vertical 
        q.push({0,root});
        while(q.size()!=0){
            auto p = q.front();
            q.pop();
            Node* temp = p.second;
            if(mp.find(p.first)!=mp.end()){
                mp.erase(p.first);
                mp[p.first]=temp->data;
            }
            else{
                mp[p.first]=temp->data;
            }
            int x = p.first;
            if(temp->left!=NULL) q.push({x-1,temp->left});
            if(temp->right!=NULL) q.push({x+1,temp->right});
        }
        for(auto it : mp){
            ans.push_back(it.second);
        }
        return ans;
    }
};
