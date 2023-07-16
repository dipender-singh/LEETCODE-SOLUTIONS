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
        if(list1 == NULL and list2 == NULL){
            return NULL;
        }
        else if(list1 == NULL){
            return list2;
        }
        else if(list2 == NULL){
            return list1;
        }
        ListNode* dhead = NULL;
        ListNode* dtail = NULL;
        if(list1->val <= list2->val){
            dhead = list1;
            dtail = list1;
            list1 = list1->next;
        }
        else if(list2->val < list1->val){
            dhead = list2;
            dtail = list2;
            list2 = list2->next;
        }
        
        while(list1!=NULL and list2!=NULL){
            if(list1->val <= list2->val){
                dtail -> next = list1;
                list1 = list1 -> next;
                dtail = dtail -> next;
            }
            else if(list1 -> val > list2 -> val){
                dtail -> next = list2;
                list2 = list2 -> next;
                dtail = dtail -> next;
            }
        }
        if(list1 == NULL){
            dtail -> next = list2;
            list2 = list2 -> next;;
        }
        else if(list2 == NULL){
            dtail -> next = list1;
            list1 = list1 -> next;
        }
        return dhead;
    }
};