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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);cout.tie(0);
       // Iteratively
        if(list1==NULL and list2==NULL){ // when both lists are empty
            return list1;
        }
        if(list1==NULL){ // if list1 is empty
            return list2;
        }
        if(list2==NULL){ // if list2 is empty
            return list1;
        }
        //create a dummy node
        ListNode* dh=NULL;
        ListNode* dt=NULL;
        if(list1->val <= list2->val){
            dh=list1;
            dt=list1;
            list1=list1->next;
        }
        else{
            dh=list2;
            dt=list2;
            list2=list2->next;
        }
        while(list1!=NULL and list2!=NULL){
            if(list1->val <= list2->val){
                dt->next=list1;
                list1=list1->next;
                dt=dt->next;
            }
            else{
                dt->next=list2;
                list2=list2->next;
                dt=dt->next;
            }
        }
        if(list1!=NULL){
            dt->next=list1;
            list1=list1->next;
        }
        if(list2!=NULL){
            dt->next=list2;
            list2=list2->next;
        }
        return dh;
    }
};