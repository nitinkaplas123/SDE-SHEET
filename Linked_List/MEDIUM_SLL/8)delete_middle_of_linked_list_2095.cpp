Steps-:
1)Find the middle of the linked list.
2)prev is just prev element of the slow.
3)slow is pointing to the middle of the linked list.
4)prev->next=slow->next;

Code-:
ListNode* deleteMiddle(ListNode* head) {
        if(head->next==NULL) return NULL;

        ListNode* slow=head;
        ListNode* fast=head;
        ListNode* prev=NULL;

        while(fast!=NULL and fast->next!=NULL)
        {
            prev=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        prev->next=slow->next;
        delete(slow);
        return head;
}