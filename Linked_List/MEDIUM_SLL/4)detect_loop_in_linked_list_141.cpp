Solution 1-:
Steps-:
1)using hashset where we store all the node one by one.
2)if we get curr node in hashset that means there is a loop

Code-: Time->O(N)  Space ->O(N)
bool hasCycle(ListNode *head) 
{
        ListNode* curr=head;
        unordered_set<ListNode*>s;
        while(curr!=NULL)
        {
           if(s.find(curr)!=s.end())
           return 1;
           s.insert(curr);
           curr=curr->next;
        }
        return 0;
}


Solution 2-: Using tortouise method
Steps-:
1)slow = move 1 step
2)fast move 2 steps 
3)Here there is two case-:
  Case 1-:
  If there is loop means at a time slow==fast
  Case 2-:
  If there is no loop as we know slow move 1 step and fast 2 step slow and fast never meet so there return 0;

Code-: Time->O(N)  Space ->O(1)

bool hasCycle(ListNode *head)
{
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast!=NULL and fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast) return 1;
        }
        return 0;  
}