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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        //BRUTE FORCE
        ios_base::sync_with_stdio(0);
        cin.tie(0);cout.tie(0);
        ListNode* temp = head;
        ListNode* c = head;
        ListNode* p = head;
        int size = 0;
        while(temp!=NULL){
            temp=temp->next;
            size++;
        }
        int count = 0;
        int lim = size-n;
        if(lim==0){ // this means that size == n this further explains that we have to remove the 
                    // current head and make the next element of the current head as the new head
        p = p->next;
        c->next=NULL;
        return p;
        }
        while(count!=lim){
            c=p;
            p=p->next;
            count++;
        }
        c->next=p->next;
        p->next=NULL;
        return head;
    }
};