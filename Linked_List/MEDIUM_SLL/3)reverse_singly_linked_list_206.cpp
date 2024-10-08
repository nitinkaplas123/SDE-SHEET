Solution 1-:
using iterative method
Steps-:
1)Just prev=NULL and curr=head
2)Now at every step curr->next=prev and prev=curr curr=curr->next

Code-: Time->O(N)
ListNode* reverseList(ListNode* head) 
{
        ListNode* curr=head;
        ListNode* prev=NULL;
        while(curr!=NULL)
        {
            ListNode* save=curr->next;
            curr->next=prev;
            prev=curr;
            curr=save;
        }
        return prev;
}


Solution 2-:
Using Recursive method

Steps-:
1)Doing same as we do in sol 1

Code-:
ListNode* helper(ListNode* prev,ListNode* curr)
{
        if(curr==NULL) return prev;
        
        ListNode* save=curr->next;
        curr->next=prev;
        return helper(curr,save);
}
ListNode* reverseList(ListNode* head)
{
        ListNode* curr=head;
        ListNode* prev=NULL;
        return helper(prev,curr);
}


Solution 3-: using recursion

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


