//Now we are gonna solve this using Doubly Linked List,
//Now how to create a Doubly Linked List here.
//Now to create a Doubly Linked List we need a class to initialize the initial values
//For Linked List Explanantion: https://leetcode.com/problems/design-browser-history/discuss/3309557/Image-Explanation-Both-Array-and-Stack-Approaches-C%2B%2BJavaPython

class Node{
  public:
    //Member Variables
    string val;
    Node* pre;
    Node* next;
    //Now when we will create an Object of the Class the Node, we will need a constructor to give it some initial 
    //values.
    Node(string val){
        pre = NULL;
        next = NULL;
        this->val = val;
    }
};
//Now when we will create a node of the linked list we will need a pointer to point to that node also.
Node *curr;
class BrowserHistory {
public:
    BrowserHistory(string homepage) {
       curr = new Node(homepage);
       //Now curr is a pointer of type Node, which will point to the newly made node of the linked list; 
    }
    
    void visit(string url) {
        curr->next = new Node(url);
        curr->next->pre = curr;
        curr = curr->next;
    }
    
    string back(int steps) {
        while(steps!=0 and curr->pre!=NULL){
            curr = curr->pre;
            steps--;
        }
        return curr->val;
    }
    
    string forward(int steps) {
        int x = 0;
        while(x!=steps and curr->next!=NULL){
            x++;
            curr = curr->next;
        }
        return curr->val;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */