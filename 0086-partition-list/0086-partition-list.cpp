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
    ListNode* partition(ListNode* head, int x) {
        /*
        //Brute Force
        if(head == NULL){
            return NULL;
        }
        ListNode* t1 = NULL;
        ListNode* t2 = NULL;
        ListNode* temp = head;
        ListNode* dummy1 = NULL;
        ListNode* dummy2 = NULL;
        while(temp!=NULL){
            if(temp->val < x){
                ListNode* node1 = new ListNode(temp->val);   
            if(t1 == NULL){
                t1 = node1;
                dummy1 = t1;
            }
            else if(t1 != NULL){
                t1 -> next = node1;
                t1 = t1 -> next;
            }
            }
            else if(temp->val >= x){
                ListNode* node2 = new ListNode(temp->val);
                if(t2 == NULL){
                    t2 = node2;
                    dummy2 = t2;
                }
                else if(t2 != NULL){
                    t2 -> next = node2;
                    t2 = t2 -> next;
                }
            }
            temp = temp -> next;
        }
        
        if(dummy1 == NULL){
            return dummy2;
        }
        if(dummy2 == NULL){
            return dummy1;
        }
        t1 -> next = dummy2;
        return dummy1;
        //Time Complexity : O(n)
        //Space Complexity : O(n)
        */
        
        //Better Approach: Uisng TWO DUMMY Nodes. 
        //Hint: https://leetcode.com/problems/partition-list/discuss/2315494/JavaC%2B%2B-Detailed-Explanation
        
         ListNode *left = new ListNode(0);
        ListNode *right = new ListNode(0);
        
        ListNode *leftTail = left;
        ListNode *rightTail = right;
        
        while(head != NULL){
            if(head->val < x){
                leftTail->next = head;
                leftTail = leftTail->next;
            }
            else{
                rightTail->next = head;
                rightTail = rightTail->next;
            }
            head = head->next;
        }
        
        leftTail->next = right->next;
        rightTail->next = NULL;
        
        return left->next;
    }
};