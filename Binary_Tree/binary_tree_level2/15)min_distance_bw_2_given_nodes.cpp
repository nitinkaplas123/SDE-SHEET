
Solution 1-:
Steps-:
1. Find the Lowest Common Ancestor (LCA):
2. Once the LCA is found, calculate the distances from the LCA to nodes 
3. The distance between the LCA and a node is the number of edges in the path from the LCA to that node.
4. Add these distances to get the total distance between nodes 

Code-:
Node* LCA(Node* root,int a,int b)
{
        if(root==NULL) return NULL;
        if(root->data==a || root->data==b)
        return root;
        
        Node* left=LCA(root->left,a,b);
        Node* right=LCA(root->right,a,b);
        
        if(left!=NULL and right!=NULL) return root;
        if(left==NULL and  right==NULL)  return NULL;
        return (left!=NULL)?left:right;
}
  
void helper(Node* root,int a,vector<int>v,int &ans)
{
        if(root==NULL) return ;
        v.push_back(root->data);
        
        if(root->data==a)
        {
            ans=v.size()-1;
            return ;
        }
        helper(root->left,a,v,ans);
        helper(root->right,a,v,ans);
}

int findDist(Node* root, int a, int b) {
       Node* lca=LCA(root,a,b);
       vector<int>v1,v2;
       int ans1,ans2;
       helper(lca,a,v1,ans1);
       helper(lca,b,v2,ans2);
       return ans1+ans2;
}