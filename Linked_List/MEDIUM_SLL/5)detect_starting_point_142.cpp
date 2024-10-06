Solution 1-:
Steps-:
1)using hashset
2)very first node which we see in hashset is the starting point.

Code-: Time->O(N)  Space ->O(N)
ListNode *detectCycle(ListNode *head) 
{
        unordered_set<ListNode*>s;
        ListNode* curr=head;
       
        while(curr!=NULL)
        {
           if(s.find(curr)!=s.end())
           break;
           
           else
           s.insert(curr);
           curr=curr->next;
        }
        return curr;
}


Solution 2-:
Steps-:
Using tortouise method
1)if there is loop so we find slow==fast.
2)now slow at head of the list and fast at which we find slow==fast
3)Now slow and fast move 1 step
4)When we reach slow==fast means this is the top of starting point of the loop.



Code-:
ListNode *detectCycle(ListNode *head) 
{
       if(head==NULL || head->next==NULL) return NULL;
       ListNode* slow=head;
       ListNode* fast=head;
       while(fast!=NULL and fast->next!=NULL)
       {
           slow=slow->next;
           fast=fast->next->next;
           if(slow==fast)
           break;
       }
       if(slow!=fast) return NULL;

       slow=head;
       while(slow!=fast)
       {
           slow=slow->next;
           fast=fast->next;
       }
       return slow;
}
