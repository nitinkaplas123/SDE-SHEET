Question -:
1)We are given a linked list where we have two types of pointers.
  1. next pointer which is pointing to the next node.
  2. random pointer which is pointing to the random node in a linked list.
2)We have to make a clone of original linked list and return the clone ka head.
3)Here we have to return the head of the clone linked list means we have to return the node which is pointer which is address 
  which means its different which means if we return head of the original linked list its wrong answer because address is unique for all.



Solution 1-:
Steps-:
1)Using hashmap.
2)We make a map of node of node.
3)where key-> original value
  where value -> clone of original.
4)just make a clone using map 
5)return m[head].



Code-: Time->O(N) Space->O(N)
Node* copyRandomList(Node* head) {
        // step1-: make a map
        unordered_map<Node*,Node*>m;
        Node* curr=head;
        while(curr!=NULL)
        {
            m[curr]=new Node(curr->val);
            curr=curr->next;
        }
        //step2 -: make connextion of clone as same as in original.
        curr=head;
        while(curr!=NULL)
        {
            m[curr]->next=m[curr->next];
            m[curr]->random=m[curr->random];
            curr=curr->next;
        }
        return m[head];
}




Solution 2-:
Steps-:
1)Make a copy of all the nodes just bw between 2 original node.
Original -> 1->2->3
Copy bw  -> 1->1->2->2->3->3


2)Now make the random pointers on clone nodes same as in original nodes.
 //step2 -:
curr=head;
while(curr!=NULL)
{
    curr->next->random=(curr->random)?curr->random->next:NULL;
    curr=curr->next->next;
}

3)Now separate both the linked list -: 
  1)Original ->which is starting from the head.
  2)Clone    -> which is starting from the 2nd nodes.

4)At the end just return the clone head of the linked list.



Node* copyRandomList(Node* head) {
        if(head==NULL) return NULL;
        //step1-:
        Node* curr=head;
        while(curr!=NULL)
        {
            Node* save=curr->next;
            curr->next=new Node(curr->val);
            curr->next->next=save;
            curr=save;
        }

        //step2 -:
        curr=head;
        while(curr!=NULL)
        {
            curr->next->random=(curr->random)?curr->random->next:NULL;
            curr=curr->next->next;
        }

        curr=head;
        Node* ans=head->next;
        Node* clone=head->next;
        while(clone->next!=NULL)
        {
            Node* temp1=curr->next->next;
            curr->next=temp1;
            curr=temp1;

            Node* temp2=clone->next->next;
            clone->next=temp2;
            clone=temp2;
        }
        curr->next=NULL;
        clone->next=NULL;
        return ans;
}