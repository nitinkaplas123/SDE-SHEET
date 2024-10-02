Steps-:
1)Here postorder means -:
  left right root
2)So in postorder we have to traverse from the last to start.
3)And here we have to first make the right subtree and then left subtree bcz 
  we have to folow the postorder fashion.
4)Inorder help us to divide the tree from left subtree and right subtree.


Code-: Time->O(N) Space->O(N)
TreeNode* helper(vector<int>& inorder, vector<int>& postorder,
                     unordered_map<int,int>m,int low,int high,int &post_index)
{
        if(post_index<0 || low>high) return NULL; 
        int val=postorder[post_index--];
        int index=m[val];
        TreeNode* root=new TreeNode(val);
        root->right=helper(inorder,postorder,m,index+1,high,post_index);
        root->left=helper(inorder,postorder,m,low,index-1,post_index);
        return root;
}

TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n=inorder.size();
        unordered_map<int,int>m;
        int post_index=n-1;
        for(int i=0;i<n;i++)
        {
            m.insert({inorder[i],i});
        }
        return helper(inorder,postorder,m,0,n-1,post_index);
}