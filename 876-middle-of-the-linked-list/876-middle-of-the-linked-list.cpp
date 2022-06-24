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
    ListNode* middleNode(ListNode* head) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);cout.tie(0);
        /*BRUTE FORCE 
        ListNode* temp = head;
        int count=0;
        while(temp!=NULL){ // O(n)
            count++;
            temp=temp->next;
        }
        if(count==1){
            return head;
        }
        if(count%2==0){
            count=(count/2);
            int ans=0;
            ListNode* t=head;
            while(ans<count){
                t=t->next;
                ans++;
            }
            return t;
        }
        count=(count/2);
            int ans=0;
            ListNode* t=head;
            while(ans<count){
                t=t->next;
                ans++;
            }
        return t;
        */
        //SLOW AND FAST POINTER 
        //Slow Pointer will move One Position and Fast Pointer will move Two Positions
        ListNode* s =head;
        ListNode* f =head;
        while(f!=NULL and f->next!=NULL){
            s=s->next;
            f=f->next->next;
        }
        return s;
  }
};