Solution 1-:
Steps-:
1)using count function.
2)if count==n means 1st node to be deleted.

Code-:
int Count(ListNode* head)
{
        int c=0;
        while(head!=NULL)
        {
            c++;
            head=head->next;
        }
        return c;
}

ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head->next==NULL) return NULL;
        int count=Count(head);
        if(count==n) 
        return head->next;
        n=count-n;
       

        ListNode* prev=NULL;
        ListNode* curr=head;
        while(n--)
        {
            prev=curr;
            curr=curr->next;
        }
        prev->next=curr->next;
        delete(curr);
        return head;
}


Solution 2-:
Steps-:
0)slow and fast at head.
1)fast will move n steps ahead of slow.
2)if(no_of_nodes==nth) it means they need 1st node to be deleted so -:
  return head->next;
3)else we go both 1 step and we remove the slow from the linked list.
Code-:
ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        ListNode* slow=head;
        ListNode* fast=head;
        while(n--)
        {
           fast=fast->next;
        }
        if(fast==NULL) return head->next;
        
        ListNode* prev=NULL;
        while(fast!=NULL)
        {
            prev=slow;
            slow=slow->next;
            fast=fast->next;
        }
        prev->next=slow->next;
        return head;
    }