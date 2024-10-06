Solution -:
Steps-:
1)Corner cases-:
  if there is no node || 1 node || 2 node we return odd_head
2)We make odd and even nodes and odd_head and even_head respectivity
3)Using flag we make diff odd position linked list and even position.
4)At last we linked odd->next=even_head and even->next=NULL;

Code-:
ListNode* oddEvenList(ListNode* head)
{
       if(head==NULL || head->next==NULL || head->next->next==NULL) return head;
       ListNode* odd_head=head;
       ListNode* even_head=head->next;
       ListNode* odd=head;
       ListNode* even=head->next;

       ListNode* curr=head->next->next;
       bool flag=false;
       while(curr!=NULL)
       {
           if(flag==false)
           {
               odd->next=curr;
               odd=curr;
           }
           else
           {
               even->next=curr;
               even=curr;
           }
           curr=curr->next;
           flag=!flag;
       }
       odd->next=even_head;
       even->next=NULL;
       return odd_head;
}