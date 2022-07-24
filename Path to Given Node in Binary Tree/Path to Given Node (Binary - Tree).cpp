 /*
 https://www.interviewbit.com/problems/path-to-given-node/
 Path to Given Node

Easy

350

12
Asked In:
Amazon
Problem Description

Given a Binary Tree A containing N nodes.

You need to find the path from Root to a given node B.

NOTE:

No two nodes in the tree have same data values.
You can assume that B is present in the tree A and a path always exists.


Problem Constraints
 1 <= N <= 105 

 1 <= Data Values of Each Node <= N

 1 <= B <= N



Input Format
First Argument represents pointer to the root of binary tree A.

Second Argument is an integer B denoting the node number.



Output Format
Return an one-dimensional array denoting the path from Root to the node B in order.



Example Input
Input 1:

 A =

           1
         /   \
        2     3
       / \   / \
      4   5 6   7 


B = 5

Input 2:

 A = 
            1
          /   \
         2     3
        / \ .   \
       4   5 .   6


B = 1




Example Output
Output 1:

 [1, 2, 5]
Output 2:

 [1]


Example Explanation
Explanation 1:

 We need to find the path from root node to node with data value 5.
 So the path is 1 -> 2 -> 5 so we will return [1, 2, 5]
Explanation 2:

 We need to find the path from root node to node with data value 1.
 As node with data value 1 is the root so there is only one node in the path.
 So we will return [1]

 */
 
 bool findpath(TreeNode* root, int x , vector<int>& ans){
	if(root==NULL){
		return false;
	}
	ans.push_back(root->val);
	if(root->val == x){
		return true;
	}
	if(findpath(root->left,x,ans)|| findpath(root->right,x,ans)){ 
	// Dono mein se ek bhi side agar ture return kar deti hai toh iska matlab
	// hai ki mujhe wo element mil gaya hai use maine apme answer mein daal diya hai
		return true;
	}
	ans.pop_back(); // upar ki dono condt. ne mujhe false diya hai or isi wajah se mai loop mein nahi gya toh mera current root can't be included in the path
	return false;
}
 
vector<int> Solution::solve(TreeNode* A, int B) {
	vector<int> ans;
	findpath(A,B,ans);
	return ans;
	}
