Solution 1-:
Steps-:
1)Make two separate node for even and odd nodes 
2)After linking even with even nodes and odd with odd nodes
3)Then merge according to question statement.

Question link-:
https://practice.geeksforgeeks.org/problems/segregate-even-and-odd-nodes-in-a-linked-list5035/1


Node* divide(Node* head) 
{
        Node* dummy1=new Node(-1);
        Node* dummy2=new Node(-1);
        Node* even=dummy1;
        Node* odd=dummy2;
        Node* curr=head;
        
        while(curr!=NULL)
        {
            if(curr->data%2==0)
            {
                even->next=curr;
                even=curr;
            }
            else
            {
                odd->next=curr;
                odd=curr;
            }
            curr=curr->next;
        }
        even->next=dummy2->next;
        odd->next=NULL;
        return dummy1->next;
}