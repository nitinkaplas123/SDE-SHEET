https://www.geeksforgeeks.org/problems/find-pairs-with-given-sum-in-doubly-linked-list/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=find-pairs-with-given-sum-in-doubly-linked-list

Steps-:
1)curr1 at the starting of the linked list.
2)curr2 at the ending of the linked list.

Code-:
vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target)
{
       vector<pair<int,int>>v;
       Node* curr1=head;
      
       Node* curr2=head;
       while(curr2->next!=NULL)
       {
           curr2=curr2->next;
       }
     
       while(curr1->data<curr2->data)
       {
           int sum=curr1->data + curr2->data;
           if(sum==target)
           {
               v.push_back({curr1->data,curr2->data});
               curr1=curr1->next;
               curr2=curr2->prev;
           }
           else if(sum>target)
           curr2=curr2->prev;
           else
           curr1=curr1->next;
       }
       return v;
}