/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
    if(head==nullptr || head->next==nullptr){
        return nullptr;
    }

    ListNode* slow=head;
    ListNode* fast=head;

    while(fast && fast->next){
        slow=slow->next;
        fast=fast->next->next;
        
        if(slow==fast) break;
    } 

    if(slow!=fast) return nullptr;

    fast=head;
    while(slow!=fast){
        slow=slow->next;
        fast=fast->next;
    }

    return slow;
}

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    if(headA == nullptr || headB==nullptr){
        return nullptr;
    }        

    ListNode* tail=headA;
    ListNode* curr=headA;

    while(curr){
        tail=curr;
        curr=curr->next;
    }

    tail->next=headB;

    ListNode* ans=detectCycle(headA);

    tail->next=nullptr;
    return ans;
}
};