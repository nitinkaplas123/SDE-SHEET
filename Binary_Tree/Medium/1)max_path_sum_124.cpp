Code-:
int helper(TreeNode* root,int &res)
{
        if(root==NULL) return 0;
        int left=helper(root->left,res);
        int right=helper(root->right,res);
        res=max(res,max(root->val,max(root->val+left,max(root->val+right,root->val+left+right))));
        return max(root->val,max(left+root->val,right+root->val));
}

int maxPathSum(TreeNode* root) {
        int res=INT_MIN;
        helper(root,res);
        return res;
}