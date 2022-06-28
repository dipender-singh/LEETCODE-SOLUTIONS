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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);cout.tie(0);
        if(head==NULL || k==1){ 
            return head;
        }
        int size = 0;
        ListNode* dummy = new ListNode(0); // we have created a dummy node with intial val as 0
        dummy->next=head;
        ListNode* temp = head;
        while(temp!=NULL){ 
            size++;
            temp=temp->next;
        }
        ListNode* curr = dummy;
        ListNode* pre = dummy;
        ListNode* nex = dummy;
        while(size>=k){
            curr = pre->next;
            nex = curr->next; 
            for(int i = 1 ; i < k ; i++){
                curr->next = nex->next;
                nex->next = pre->next;
                pre->next = nex;
                nex = curr->next; 
            }
            pre=curr;
            size=size-k;
        }
        return dummy->next;
    }
};