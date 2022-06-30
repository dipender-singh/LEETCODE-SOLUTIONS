// { Driver Code Starts
#include <bits/stdc++.h>

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};

using namespace std;

void printList(Node *Node)
{
    while (Node != NULL)
    {
        printf("%d ", Node->data);
        Node = Node->bottom;
    }
}

Node* flatten (Node* root);

int main(void) {

	int t;
	cin>>t;
	while(t--){
    int n,m,flag=1,flag1=1;
    struct Node * temp=NULL;
	struct Node * head=NULL;
	struct Node * pre=NULL;
	struct Node * tempB=NULL;
	struct Node * preB=NULL;
		cin>>n;
        int work[n];
		for(int i=0;i<n;i++)
            cin>>work[i];
		for(int i=0;i<n;i++){
			m=work[i];
			--m;
			int data;
			scanf("%d",&data);
			temp = new Node(data);
			temp->next = NULL;
			temp->bottom = NULL;
			
			if(flag){
				head = temp;
				pre = temp;
				flag = 0;
				flag1 = 1;
			}
			else{
				pre->next = temp;
				pre = temp;
				flag1 = 1;
			}
			for(int j=0;j<m;j++){
				
				int temp_data;
				scanf("%d",&temp_data);
				tempB = new Node(temp_data);

				if(flag1){
					temp->bottom=tempB;
					preB=tempB;
					flag1=0;
				}
				else{
					preB->bottom=tempB;
					preB=tempB;
				}
			}
		}
		   Node *fun = head;
		   Node *fun2=head;

            Node* root = flatten(head);
            printList(root);
            cout<<endl;

	}
	return 0;
}
// } Driver Code Ends


/* Node structure  used in the program

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};
*/

/* Function which will merge our Two Linked Lists*/


Node *mergeTwoLists(Node* a, Node* b){
    Node *temp = new Node(0);
    Node *res = temp;
    
    while(a != NULL && b != NULL){
        if(a -> data < b -> data){
            temp -> bottom = a;
            temp = temp -> bottom;
            a = a -> bottom;
        }
        else{
            temp -> bottom = b;
            temp = temp -> bottom;
            b = b -> bottom;
        }
    }
    if(a)  temp -> bottom = a;
    else  temp -> bottom = b;
    return  res -> bottom;
}

Node *flatten(Node *root)
{
   if(root == NULL || root -> next == NULL) return root;
   // recursion for right list
   root -> next = flatten(root -> next);    
   // now merge
   root = mergeTwoLists(root, root -> next);    
   
   return root;
}
/*  Function which returns the  root of 
    the flattened linked list. 
Node *flatten(Node *root)
{
   // Your code here
   //Base Case
   if(root==NULL || root.next==NULL){
       return root;
   }
   //We will move to the List which at our Right Side
   root.next = flatten(root.next); //Now try to imagine that if we have reached to 
   // the Last Node of the List and from there we returned the address of it's head node 
   // now we want that addres on the rght side of our current node 
   root = merge(root,root.next);
   //Now when we have merged The Two Lists now we want that list to be our current list so that's
   // why we are storing the addres of the starting node of the combined list in our current root.
   return root;
}
*/

