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
        // Can be Solved in TWO ways :- Iteratively and Recursively
        //Iteratively
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
    }
};