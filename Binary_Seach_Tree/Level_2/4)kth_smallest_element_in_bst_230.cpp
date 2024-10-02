Steps-:
1)In bst my 1st smallest element is in left->left->left....


Code-: Time->O(N)
void helper(TreeNode* root,int k,int &count,int &ans)
{
        if(root==NULL) return ;

        helper(root->left,k,count,ans);
        count++;

        if(count==k)
        {
            ans=root->val;
            return ;
        }

        helper(root->right,k,count,ans);
}

int kthSmallest(TreeNode* root, int k) {
        int count=0;
        int ans=0;
        helper(root,k,count,ans);
        return ans;
}