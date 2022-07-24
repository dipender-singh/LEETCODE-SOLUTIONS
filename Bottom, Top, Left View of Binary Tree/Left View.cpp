/*
Given a Binary Tree, print Left view of it. Left view of a Binary Tree is set of nodes visible when tree is visited from Left side. The task is to complete the function leftView(), which accepts root of the tree as argument.

Left view of following tree is 1 2 4 8.

          1
       /     \
     2        3
   /     \    /    \
  4     5   6    7
   \
     8   

Example 1:

Input:
   1
 /  \
3    2
Output: 1 3

Example 2:

Input:

Output: 10 20 40
Your Task:
You just have to complete the function leftView() that returns an array containing the nodes that are in the left view. The newline is automatically appended by the driver code.
Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).

Constraints:
0 <= Number of nodes <= 100
1 <= Data of a node <= 1000
*/
vector<int> leftView(Node *root)
{
   // Your code here
//Questions for all the views of Binary Tree is done from the concepts of the question:- Vertical Order Traversal of B-Tree
//The logic here is very simple all i have done is taken value of the first node from each level
   queue<pair<int,Node*>> q; //This will store the node for each level, first it will store the left node of each level which will obviously be the first node of each level
   map<int,int> mp;//This map is used to store the node's value for each level
   vector<int> ans;
   if(root==NULL){
       return {};
   }
   q.push({0,root});
   while(q.size()!=0){
       auto p = q.front();
       q.pop();
       Node* temp = p.second;
       int x = p.first;
       if(mp.find(x)==mp.end()){
           mp[x]=temp->data;
       }
       if(temp->left!=NULL) q.push({x+1,temp->left});//We are pushing the left node first, this is automatically the first node of every level
       if(temp->right!=NULL) q.push({x+1,temp->right});//In case we don't have a node in front of our node in a level then this will become the first node of a level
   }
   for(auto it : mp){
       ans.push_back(it.second);
   }
   return ans;
}
