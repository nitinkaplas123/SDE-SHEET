https://www.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card

Code-:
void left_boundary(Node* root,vector<int>&v1)
{
        if(root==NULL) return ;
        if(root->left==NULL and root->right==NULL) return ;
        
        v1.push_back(root->data);
        if(root->left)
        left_boundary(root->left,v1);
        else
        left_boundary(root->right,v1);
}

void leaf_nodes(Node* root,vector<int>&v1)
{
        if(root==NULL) return ;
        if(root->left==NULL and root->right==NULL)
        {
            v1.push_back(root->data);
            return ;
        }
        leaf_nodes(root->left,v1);
        leaf_nodes(root->right,v1);
}
void right_boundary(Node* root,vector<int>&v1)
{
        if(root==NULL) return ;
        if(root->left==NULL and root->right==NULL) return ;
        
        v1.push_back(root->data);
        if(root->right)
        right_boundary(root->right,v1);
        else
        right_boundary(root->left,v1);
}
    
vector<int> boundaryTraversal(Node *root) 
{
        vector<int>v;
        if(root->left==NULL and root->right==NULL) return {root->data};
        
        v.push_back(root->data);
        left_boundary(root->left,v);
        leaf_nodes(root,v);
        
        vector<int>v1;
        right_boundary(root->right,v1);
        reverse(v1.begin(),v1.end());
        
        for(int i=0;i<v1.size();i++)
        {
            v.push_back(v1[i]);
        }
        return v;
}