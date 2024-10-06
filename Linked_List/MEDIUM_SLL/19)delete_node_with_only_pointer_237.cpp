Solution 1-:
eg.
[4,5,1,9]   node to be deleted ->5   o/p->[4,1,9]
Steps-:
1)Node pointer is giving to us as in eg 5
2)Make a temp node to next to 5 (means node 1 is temp)
3)Make value of node pointer equal to temp node [4,1,1,9]
4)Now linking node->next=temp->next and delete the temp node  o/p [4,1,9]


Code-: Time->O(1) 
void deleteNode(ListNode* node)
{
        ListNode* curr=node;
        ListNode* temp=curr->next;
        curr->val=temp->val;
        curr->next=temp->next;
        delete(temp);
        return ;
}
