https://www.geeksforgeeks.org/problems/minimum-element-in-bst/1


Code-:
int minValue(Node* root) 
{
        if(root==NULL) return -1;
        int ans=INT_MAX;
        while(root!=NULL)
        {
            if(root->data<ans)
            {
                ans=root->data;
            }
            root=root->left;
        }
        return ans;
}