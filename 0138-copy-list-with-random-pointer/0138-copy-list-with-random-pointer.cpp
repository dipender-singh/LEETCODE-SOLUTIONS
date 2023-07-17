/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);cout.tie(0);
        if(head == NULL){
            return NULL;
        }
        
        Node* temp = head;
        Node* t = NULL;
        Node* dummyhead = NULL;
        
        //First we will Manipulate the Original List and will add the Node in front of the Original Node.
        
        while(temp!=NULL){
            Node* node = new Node(temp->val);
            t = node;
            t->next = temp->next;
            temp -> next = t;
            temp = temp -> next -> next;
        }
        
        //Secondly we will try to Copy the Random Pointers of the Previous Nodes for the Newly Created Nodes.
        
        Node* iter = head;
  while (iter != NULL) {
    if (iter->random != NULL) {
      iter->next->random = iter->random->next;
    }
    iter = iter->next->next;
  }  
        //Thirdly we will Seperate the Newly Created Nodes from the Original List to a New List.
        Node* slow = head;
        Node* fast = slow -> next;
        dummyhead = fast;
        while(fast->next!=NULL){
            slow -> next = fast -> next;
            slow = fast -> next;
            fast -> next = slow -> next;
            fast = slow -> next;
        }
            slow -> next = fast -> next;
            slow = fast -> next;
            return dummyhead;
    }
};