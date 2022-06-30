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
    
    ListNode* reverser(ListNode* temp){
        ListNode* p = NULL;
        ListNode* f = temp;
        ListNode* t = temp;
        while(f->next!=NULL){
            f = f->next;
            t->next = p;
            p = t;
            t = f;
        }
        t->next=p;
        return t;
    }
    
    //This function will reverse the first part of my List
    ListNode* reversef(ListNode* temp, int k){
        ListNode* p = NULL;
        ListNode* f = temp;
        ListNode* t = temp;
        while(k!=0){
            f=f->next;
            t->next=p;
            p=t;
            t=f;
            k=k-1;
        }
        temp->next = reverser(f);
        return p;
    }
    
    // This function will just reverse my whole list
    ListNode* reversew(ListNode* temp){
        ListNode* p = NULL;
        ListNode* f = temp;
        ListNode* t = temp;
        while(f->next!=NULL){
            f = f->next;
            t->next = p;
            p = t;
            t = f;
        }
        t->next=p;
        return t;
    }
    
    ListNode* rotateRight(ListNode* head, int k) {
        //Brute Force
        ios_base::sync_with_stdio(0);
        cin.tie(0);cout.tie(0);
        if(head==NULL){
            return head;
        }
        if(head->next==NULL){
            return head;
        }
        if(k==0){
            return head;
        }
        ListNode* temp = head;
        ListNode* res = head;
        int size = 0;
        while(temp!=NULL){
            temp=temp->next;
            size++;
        }
        if(k==size || k%size==0){
            return head;
        }
        k = k % size;
        int x = k;
        head = reversew(head); // Now i have reversed my whole List
        head = reversef(head,x);
        return head;
    }
};