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
    ListNode* reverseList(ListNode* head) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);cout.tie(0);
        /*Iteratively
        if(head==NULL || head->next==NULL){ // if the list has one or no nodes at all
            return head;
        }
        if(head->next->next==NULL){ // if list has two nodes
            ListNode* p = head;
            ListNode* temp = p->next;
            temp->next=p;
            p->next=NULL;
            return temp;
        }
        ListNode* p = head;
        ListNode* c = head->next;
        ListNode* t = head->next->next;
        p->next=NULL;
        while(t->next!=NULL){
            c->next=p;
            p=c;
            c=t;
            t=t->next;
        }
        c->next=p;
        t->next=c;
        return t;
        //Recursively
        //Base Condition // Small Calculation //Recursive Call
        if(head->next==NULL || head==NULL){
            return head;
        }
        */
        //Base Condition
        if(head==NULL || head->next==NULL){ // if the list has one or no nodes at all
            return head;
        }
        //Recursive Call
        ListNode* temp = reverseList(head->next);
        //Small Calculation
        //Now we can say that the previous L.L. is reversed and now my head element is pointing to thr 
        //last element of the reversed L.L so we just have to do this:-
        head->next->next=head;
        head->next=NULL;
        return temp;

    }
};