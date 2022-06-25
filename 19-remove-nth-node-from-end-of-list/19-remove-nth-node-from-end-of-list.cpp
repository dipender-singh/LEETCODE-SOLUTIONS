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
        /*BRUTE FORCE
        ios_base::sync_with_stdio(0);
        cin.tie(0);cout.tie(0);
        ListNode* temp = head;
        ListNode* c = head;
        ListNode* p = head;
        int size = 0;
        while(temp!=NULL){ //O(N)
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
        while(count!=lim){ // O(N-M)
            c=p;
            p=p->next;
            count++;
        }
        c->next=p->next;
        p->next=NULL;
        return head;
        TOTAL TC IS:- O(SIZE)+O(SIZE-N) 
        */
        //OPTIMIZED : THINK OF IT 
        ios_base::sync_with_stdio(0);
        cin.tie(0);cout.tie(0);
        // Now we will take a pointer fast ans slow and move fast pointer n steps and a slow pointer 
        // will be at head for now. So now we have created a gap of 'n' nodes in between the slow and 
        // fast pointer. So now we will move both slow and fast pointer by one, now when fast pointer 
        //will reach to the end node, our slow pointer will be at the 'n'th node from the end BECAUSE 
        //WE HAVE CREATED A GAP OF 'n' NODES BETWEEN SLOW POINTER AND FAST POINTER.
        ListNode* slow = head;
        ListNode* fast = head;
        int x = 1;
        while(x <= n){
            fast=fast->next;
            x++;
        }
        if(fast==NULL){ // fast has become null we have reached the end then it means we have to del 
                        // head
            head=head->next;
            slow->next=NULL;
            return head;
        }
        while(fast->next!=NULL){
            fast=fast->next;
            slow=slow->next;
        }
        slow->next = slow->next->next;
        return head;
    }
};