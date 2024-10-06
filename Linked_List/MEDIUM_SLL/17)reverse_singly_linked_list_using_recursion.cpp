Steps-:
Case 1-:
1)if there is only one node return head.

Case 2-:
Just do the dry run of 2 nodes rest will take care by recursion.

I/p -: 1->2
O/p -: 2->1

1. means my new_head of reverse linked list will be 2.
   so here we are calling reverseList function till we reach the last.
   so we stop at 2 and new_head is 2.
   and here my head is 1 
   ListNode* new_head=reverseList(head->next);

2.  head_next->next=head;
    here 1 is my head.
    head_next is 2.
    head_next->next=head.
    2->1

3.  1 is the head.
    1->next=NULL.
    head->next=NULL.

4.  return new_head.
    which is 2.

ListNode* reverseList(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;

        ListNode* new_head=reverseList(head->next);
        ListNode* head_next=head->next;
        head_next->next=head;
        head->next=NULL;
        return new_head;
}


