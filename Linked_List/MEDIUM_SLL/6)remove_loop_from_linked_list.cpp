https://www.geeksforgeeks.org/problems/remove-loop-in-linked-list/1

Solution 1-:
Steps-:
1)Using two pointer prev=null and curr=head
2)using hashset to store the nodes in it.
3)if we find the curr node in set so here prev=>next=NULL to reove the loop from the linked list.

Code-: Time->O(n) Space->O(N)
void removeLoop(Node* head)
{
       unordered_set<Node*>s;
       Node* curr=head;
       Node* prev=NULL;
       while(curr!=NULL)
       {
           if(s.find(curr)!=s.end())
           {
               prev->next=NULL;
               return;
           }
           
           s.insert(curr);
           prev=curr;
           curr=curr->next;
       }
 }




Solution 2-:
Steps-:
1)Here first we have to find the point when slow==fast
2)If its equal means there is loop else not.
3)Now we have to find the starting point of the loop (here slow and fast is pointing to starting point of loop)
4)slow is at starting of loop and to break the loop logic is (fast->next!=slow)  if it reach there fast->next=NULL


Code-: Time->O(n) Space->O(1)
void removeLoop(Node* head)
{
       
       if(head==NULL || head->next==NULL) return ;
       Node* slow=head;
       Node* fast=head;
       // point where slow==fast in a loop
       while(fast!=NULL and fast->next!=NULL)
       {
           slow=slow->next;
           fast=fast->next->next;
           if(fast==slow)
           break;
       }
       
       //loop is there or not if slow==fast there is loop else  not
       if(slow==fast)
       slow=head;
       else
       return ;
       
       // here we find the starting point of the loop
       while(fast!=slow)
       {
           slow=slow->next;
           fast=fast->next;
       }
       
       //here we find the last node of the loop so that we can make its next null to 
       // break the loop.
       while(fast->next!=slow)
       {
           fast=fast->next;
       }
       fast->next=NULL;
}