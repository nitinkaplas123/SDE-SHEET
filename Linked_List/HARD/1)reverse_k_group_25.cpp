Solution -:

here we have to reverse k group 
but if we left with less number of nodes than k than no need to reverse it just return as it is.

eg. [1,2,3,4,5,6,7,8]   k=3
o/p->  3->2->1->6->5->4->7->8

Steps-:
1)here we have to check first number of nodes are greater than k 
  if yes then reverse k nodes 
  else return head (means no need to reverse nodes just return the head of remaining nodes)
2)then using recursion we calling rest of the nodes and return prev 

[1,2,3,4,5,6,7,8]

1st => 3->2->1   here 1 is the head and 3 is prev
2nd => 6->5->4   here head->next=f(4,3)  means 3->2->1->6->5->4
3rd => 7->8      here 7 is the head      means 3->2->1->6->5->4->7->8



Code-: Time->O(N)
ListNode* reverseKGroup(ListNode* head, int k) 
{
         ListNode* curr=head;
         for(int i=0;i<k;i++)
         {
            if(curr==NULL) return head;
            curr=curr->next;
         }

         curr=head;
         ListNode* prev=NULL;
         for(int i=0;i<k;i++)
         {
            ListNode* save=curr->next;
            curr->next=prev;
            prev=curr;
            curr=save;
         }

         head->next=reverseKGroup(curr,k);
         return prev;
}