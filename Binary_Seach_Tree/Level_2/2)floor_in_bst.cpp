
Floor Means-:
1)Equal or just smaller value than x.

Code-: Time->O(log(n))
int floor(Node* root, int x) 
{
        int ans=-1;
        while(root!=NULL)
        {
            if(root->data==x)
            return root->data;
            else if(root->data<x)
            {
                ans=root->data;
                root=root->right;
            }
            else
            root=root->left;
        }
        return ans;
}