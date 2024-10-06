Solution 1 -:
Steps-:
1)First we count the node of the linked list which is n
2)Now shift n/2 times from head
3)Now we reach the middle of the list and here return the middle node of the list.

Code-: Time->O(N)
int count(ListNode* curr)
{
        int c=0;
        while(curr!=NULL)
        {
            c++;
            curr=curr->next;
        }
        return c;
}
ListNode* middleNode(ListNode* head) 
{
        ListNode* curr=head;
        int n=count(head);

        for(int i=0;i<n/2;i++)
        {
           curr=curr->next;
        }
        return curr;
}



Solution 2-:
Steps-:
1)Using fast and slow method (rabbit and tortouise)
2)slow ->one step move 
3)fast->two step move

Code-: Time->O(n/2)
ListNode* middleNode(ListNode* head) 
{
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast!=NULL and fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
}