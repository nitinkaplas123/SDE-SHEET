Solution 1-:
Steps-:
1)Corner case-> if any one of the linked list is null than return another 
2)Using two pointer approach curr1 and curr2 are the pointer by comparing we make sorted linked list.
3)When any one is pointing to null then just linked with which list have node remaining.


Code-: Time->O(N)  Space ->O(1)
ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1==NULL)
        return list2;
        if(list2==NULL)
        return list1;
        ListNode* curr1=list1;
        ListNode* curr2=list2;
        ListNode* curr=NULL;
        ListNode* new_head=NULL;
        while(curr1!=NULL and curr2!=NULL)
        {
            if(curr1->val<curr2->val)
            {
               if(new_head==NULL)
               {
                   new_head=curr1;
                   curr=curr1;
               }
               else
               {
                   curr->next=curr1;
                   curr=curr1;
               }
               curr1=curr1->next;
            }
            else
            {
               if(new_head==NULL)
               {
                   new_head=curr2;
                   curr=curr2;
               }
               else
               {
                   curr->next=curr2;
                   curr=curr2;
               }
               curr2=curr2->next;
            }
        }

        if(curr1!=NULL)
        {
            curr->next=curr1;
        }
        if(curr2!=NULL)
        {
            curr->next=curr2;
        }
        
        return new_head;
    }


Solution 2-:
Using recusrion 

Code-:
 ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1==NULL)
        return list2;
        if(list2==NULL)
        return list1;

        if(list1->val<list2->val)
        {
            list1->next=mergeTwoLists(list1->next,list2);
            return list1;
        }
        else
        {
            list2->next=mergeTwoLists(list1,list2->next);
            return list2;
        }
    }