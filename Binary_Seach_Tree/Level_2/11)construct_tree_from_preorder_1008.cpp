Solution 1-:
Steps-:
1)using inorder and preorder.

Code-: Time->O(N^2)
int pre_index=0;
TreeNode* helper(vector<int>&preorder,vector<int>&inorder,
                     int low,int high,int n)
{
        if(pre_index==n) return NULL;
        if(low>high) return NULL;
        int val=preorder[pre_index];
        
        int mid;
        for(int i=low;i<=high;i++)
        {
            if(inorder[i]==val)
            {
                mid=i;
                break;
            }
        }
        pre_index++;
        TreeNode* root=new TreeNode(val);
        root->left=helper(preorder,inorder,low,mid-1,n);
        root->right=helper(preorder,inorder,mid+1,high,n);
        return root;
}

TreeNode* bstFromPreorder(vector<int>& preorder) {
        int n=preorder.size();
        vector<int>pre;
        vector<int>in;
        pre=preorder;
        sort(preorder.begin(),preorder.end());
        return helper(pre,preorder,0,n-1,n);
}



Solution 2-:
Steps-:
1)Using unordered_map.

Code-:
int pre_index=0;
TreeNode* helper(vector<int>&preorder,vector<int>&inorder,
                     int low,int high,int n,unordered_map<int,int>&m)
{
        if(pre_index==n) return NULL;
        if(low>high) return NULL;
        int val=preorder[pre_index++];
        
        int index=m[val];
        TreeNode* root=new TreeNode(val);
        root->left=helper(preorder,inorder,low,index-1,n,m);
        root->right=helper(preorder,inorder,index+1,high,n,m);
        return root;
}

TreeNode* bstFromPreorder(vector<int>& preorder) {
        int n=preorder.size();
        vector<int>pre;
        vector<int>in;
        pre=preorder;
        sort(preorder.begin(),preorder.end());
        unordered_map<int,int>m;
        for(int i=0;i<n;i++)
        {
            m.insert({preorder[i],i});
        }
        return helper(pre,preorder,0,n-1,n,m);
}



Solution 3-:
Steps-:
1)Using bound means we are setting the max limit in both the direction 

Case1-:
For the left side.
bound-> root->val itself.
means all the values which are smaller than my root->val should be come in left side of binary tree.

Case2-:
For the right side.
from the starting we are giving INT_MAX as the bound.

Note-: Do dry run onces.

How we can do it using this method 
bcz in preorder -> left root right.
we know that all the values in left side will be smaller than root->data 
and all the values in right side is greater than root->data.


Code-:Time->O(N)
int pre_index=0;
TreeNode* helper(vector<int>&preorder,int bound)
{
       if(pre_index==preorder.size() || preorder[pre_index]>bound)
       return NULL;

       TreeNode* root=new TreeNode(preorder[pre_index++]);
       root->left=helper(preorder,root->val);
       root->right=helper(preorder,bound);
       return root;
}

TreeNode* bstFromPreorder(vector<int>& preorder) {
        int bound=INT_MAX;
        return helper(preorder,bound);
}