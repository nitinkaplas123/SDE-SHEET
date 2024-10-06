https://www.geeksforgeeks.org/problems/given-a-linked-list-of-0s-1s-and-2s-sort-it/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=given-a-linked-list-of-0s-1s-and-2s-sort-it


Solution 1-:
Steps-:
1)Make a 3 size array where we store the count of 0,1,2
2)Now travere the for loop for count[0] and make 0 in it.
3)Now travere the for loop for count[1] and make 1 in it.
4)Now travere the for loop for count[2] and make 2 in it.

Code-: Time->O(n)
Node* segregate(Node *head) {
        int count[3]={0,0,0};
        
        
        Node* curr=head;
        while(curr!=NULL)
        {
            count[curr->data]++;
            curr=curr->next;
        }
      
        curr=head;
        for(int i=0;i<count[0];i++)
        {
            curr->data=0;
            curr=curr->next;
        }
        for(int i=0;i<count[1];i++)
        {
            curr->data=1;
            curr=curr->next;
        }
        for(int i=0;i<count[2];i++)
        {
            curr->data=2;
            curr=curr->next;
        }
        return head;
}





Solution 2-:
Steps-:
1)Make three dummy nodes for 0 ,1 ,2
2)Now linked separate 0 , 1, 2
3)At last we linked 0 1 2
4)At last there is possiblilty that-:
  1)zero element is not there
  2)ones element is not there
  3)twos element is not there

Case 1-:
if zeros are empty 
Case2-:
if ones are empty   -> only this have to take care
Case3-:
if twos are empty 
Note -: Donot forget to make the end node->next=NULL.

Code-:
Node* segregate(Node* head) {
       Node* zeros=new Node(-1);
       Node* zero=zeros;
       Node* ones=new Node(-1);
       Node* one=ones;
       Node* twos=new Node(-1);
       Node* two=twos;
       Node* curr=head;
       while(curr!=NULL)
       {
           if(curr->data==0)
           {
               zero->next=curr;
               zero=curr;
           }
           else if(curr->data==1)
           {
               one->next=curr;
               one=curr;
           }
           else
           {
               two->next=curr;
               two=curr;
           }
           curr=curr->next;
       }
       zero->next=(ones->next==NULL)?(twos->next):(ones->next);
       one->next=twos->next;
       two->next=NULL;
       return zeros->next;
}
