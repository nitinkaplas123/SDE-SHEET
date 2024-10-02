Solution 1-:
Steps-:
1)here we use the concept of merge two linked_list.

Code-:  Time ->O(M*(N1+N2)) -> O(M*2N) -> O(2*MN)
Node* mergeTwoLists(Node* head1, Node* head2) O(N1+N2)
{
    Node* dummyNode=new Node(-1);
    Node* temp=dummyNode;
    
    while(head1!=NULL and head2!=NULL)
    {
        if(head1->data<head2->data)
        {
            temp->bottom=head1;
            temp=head1;
            head1=head1->bottom;
        }
        else
        {
            temp->bottom=head2;
            temp=head2;
            head2=head2->bottom;
        }
    }
    
    if(head1!=NULL)
    temp->bottom=head1;
    if(head2!=NULL)
    temp->bottom=head2;
    return dummyNode->bottom;
}

Node *flatten(Node *root)  O(M) here we have M nodes in horizontal so we call merge function M times.
{
    if(root==NULL || root->next==NULL)
    return root;
    
    Node* mergeHead=flatten(root->next);
    root=mergeTwoLists(root,mergeHead);
    return root;
}