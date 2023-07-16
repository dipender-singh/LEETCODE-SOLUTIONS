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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* t1 = l1;
        ListNode* t2 = l2;
        ListNode* t = NULL;
        ListNode* h = t;
        int carry = 0;
        int sum = 0;
        while(t1!=NULL and t2!=NULL){
            sum = 0;
            sum = t1->val + t2->val + carry;
                carry = sum / 10; 
                sum = sum % 10;
            ListNode* node = new ListNode(sum);
            if(t == NULL){
                t = node; 
                h = t;
            }
            else{
                t->next = node;
                t = node;
            }
            t1 = t1->next;
            t2 = t2->next;
        }
        //Now we have to see which Linked List we have traversed completely. 
        if(t1 == NULL){
            while(t2!=NULL){
            sum = 0;
            sum = t2->val + carry;
                carry = sum / 10; 
                sum = sum % 10;
            ListNode* node = new ListNode(sum);
                t->next = node;
                t = node;
            t2 = t2->next;
            }
        }
        else if(t2 == NULL){
            while(t1!=NULL){
            sum = 0;
            sum = t1->val + carry;
                carry = sum / 10;
                sum = sum % 10;
            ListNode* node = new ListNode(sum);
                t->next = node;
                t = node;
                t1 = t1 -> next;
            }
        }
        if(carry >= 1){
            ListNode* node = new ListNode(carry);
            t->next = node;
        }
        return h;
    }
};