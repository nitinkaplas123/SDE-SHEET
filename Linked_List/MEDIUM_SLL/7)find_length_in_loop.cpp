https://www.geeksforgeeks.org/problems/find-length-of-loop/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=find-length-of-loop


Steps-:
1)First find there is loop or not.
2)Now find the starting point in a linked list.
3)slow=starting point 
  fast will traverse a loop and count the node in a loop.

Code-:
int countNodesinLoop(Node *head) {
       if(head->next==NULL) return 0;
       Node* slow=head;
       Node* fast=head;
       while(fast!=NULL and fast->next!=NULL)
       {
           slow=slow->next;
           fast=fast->next->next;
           if(slow==fast)
           break;
       }
       if(slow!=fast)
       return 0;
       
       // starting point 
       slow=head;
       while(slow!=fast)
       {
           slow=slow->next;
           fast=fast->next;
       }
       
       int count=1;
       while(fast->next!=slow)
       {
           count++;
           fast=fast->next;
       }
       return count;
}