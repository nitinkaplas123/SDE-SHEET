question link-:
https://practice.geeksforgeeks.org/problems/reverse-a-linked-list-in-groups-of-given-size/1


In this question we have to reverse k group node even if there is less nodes left 
means -:

eg. [1,2,3,4,5,6,7,8]  k=3
1st =>  3->2->1    here 3 is prev and 1 is head
2nd =>  6->5->4    here 6 is prev and 4 is head
3rd => 8->7        here 8 is prev and 7 is head


o/p ->  3->2->1->6->5->4->8->7

Solution 1-:
Using recursion

Steps-:
1)Make a reverse logic of k nodes
2)Then there is 2 cases-:
  1. if nodes are finished =>here we have to return the end point of reverse list.
  2. if nodes are there then we have to call recursive function by passing curr node as head
  3. after recusion finished first element of every group means head is linked with (prev) means 1st node 
     of reverse list.


Code-: Time->O(N)
struct node *reverseIt(struct node *head, int k) {
        int count=0;
        node* curr=head;
        node* prev=NULL;
        
        while(curr!=NULL and count<k)
        {
            node* save=curr->next;
            curr->next=prev;
            prev=curr;
            curr=save;
            count++;
        }
        
        if(curr!=NULL)
        head->next=reverseIt(curr,k);
        return prev;
}