Code-:
void helper(Node* root,vector<int>&v)
{
        if(root==NULL) 
        {
            v.push_back(-1);
            return ;
        }
        
        v.push_back(root->data);
        helper(root->left,v);
        helper(root->right,v);
}

vector<int> serialize(Node *root) 
{
        vector<int>v;
        helper(root,v);
        return v;
}
    
//Function to deserialize a list and construct the tree.
int index=0;
Node* helper2(vector<int>&A)
{
        if(index==A.size())
        return NULL;
        int val=A[index++];
        if(val==-1)
        return NULL;
        
        Node* root=new Node(val);
        root->left=helper2(A);
        root->right=helper2(A);
        return root;
}
Node * deSerialize(vector<int> &A)
{
         return helper2(A);
}