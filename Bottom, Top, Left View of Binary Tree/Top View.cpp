/*
Given below is a binary tree. The task is to print the top view of binary tree. Top view of a binary tree is the set of nodes visible when the tree is viewed from the top. For the given below tree

       1
    /     \
   2       3
  /  \    /   \
4    5  6   7

Top view will be: 4 2 1 3 7
Note: Return nodes from leftmost node to rightmost node.

Example 1:

Input:
      1
   /    \
  2      3
Output: 2 1 3
Example 2:

Input:
       10
    /      \
  20        30
 /   \    /    \
40   60  90    100
Output: 40 20 10 30 100
Your Task:
Since this is a function problem. You don't have to take input. Just complete the function topView() that takes root node as parameter and returns a list of nodes visible from the top view from left to right.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N).

Constraints:
1 = N = 105
1 = Node Data = 105
*/
class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        //Your code here
        //Same approach that was used in Vertical order traversal using the vertical lines
        //We will push only the first item of every vertical in our answer
        //If for any vertical line a value is already there in our map then we will not insert 
        //any extra value for the same vertical in our map
        queue<pair<int,Node*>> q;
        vector<int> ans;
        map<int,int> mp;
        q.push({0,root});
        while(q.size()!=0){
            auto p = q.front();
            q.pop();
            Node* temp = p.second;
            if(mp.find(p.first)==mp.end()){
            mp[p.first]=temp->data;
            }
            int x = p.first;
            if(temp->left!=NULL) q.push({x-1,temp->left});
            if(temp->right!=NULL) q.push({x+1,temp->right});
        }
        for(auto m : mp){
            ans.push_back(m.second);
        }
        return ans;
    }

};
