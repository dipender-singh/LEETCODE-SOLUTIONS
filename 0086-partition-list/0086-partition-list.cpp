/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        //Brute Force
        //This basically means that we have to Re-Arrange the Nodes here. 
    /*    
    1 -> 4 -> 3 -> 2 -> 5 -> 2
    
    x = 3
    
    Here, all nodes with values less than 3 (i.e., 1, 2, 2) come before all nodes with values greater than or 
    equal to 3 (i.e., 4, 3, 5). Moreover, the relative order of nodes within each partition is maintained. That 
    means if a node appears before another node in the original list, it should also appear before that node in 
    the modified list.
    */            
        
        //We have to use the Two Pointer Approach here. 
        //Do a dry run of how we will detach and attach the nodes at each step, in order to get the final LL.
        
        //Creating Seperate List for Elements less than X and Seperate List for Elements greator than or equal to X. 
        
        if(head == NULL){
            return NULL;
        }
        ListNode* t1 = NULL;
        ListNode* t2 = NULL;
        ListNode* temp = head;
        ListNode* dummy1 = NULL;
        ListNode* dummy2 = NULL;
        while(temp!=NULL){
            if(temp->val < x){
                ListNode* node1 = new ListNode(temp->val);   
            if(t1 == NULL){
                t1 = node1;
                dummy1 = t1;
            }
            else if(t1 != NULL){
                t1 -> next = node1;
                t1 = t1 -> next;
            }
            }
            else if(temp->val >= x){
                ListNode* node2 = new ListNode(temp->val);
                if(t2 == NULL){
                    t2 = node2;
                    dummy2 = t2;
                }
                else if(t2 != NULL){
                    t2 -> next = node2;
                    t2 = t2 -> next;
                }
            }
            temp = temp -> next;
        }
        
        //Now there can be three conditions here: 1. When all the elements are greator than or equal to x, 
        //2. When all the elements are less than x .
        //3. When there is a mixed conditon
        
        if(dummy1 == NULL){
            return dummy2;
        }
        if(dummy2 == NULL){
            return dummy1;
        }
        t1 -> next = dummy2;
        return dummy1;
    }
};