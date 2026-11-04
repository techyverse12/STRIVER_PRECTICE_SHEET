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
        ListNode* currnext=NULL;
        ListNode* prev=NULL;
        ListNode* temp=head;
        while(temp!=NULL){
            currnext=temp->next;
            temp->next=prev;
            prev=temp;
            temp=currnext;
        }
        return prev;
    }
};