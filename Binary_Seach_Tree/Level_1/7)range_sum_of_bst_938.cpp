Solution 1:


Time ->O(N)
Space ->O(N)
Code:
void helper(TreeNode* root,vector<int>&v)
{
        if(root==NULL) return ;
        helper(root->left,v);
        v.push_back(root->val);
        helper(root->right,v);
}
int rangeSumBST(TreeNode* root, int low, int high) {
    vector<int>inorder;
    helper(root,inorder);
    
    int ans=0;
    for(int i=0;i<inorder.size();i++)
    {
        if(low<=inorder[i] and high>=inorder[i])
        ans+=inorder[i];
    }
    return ans;
}


Solution 2:


Time Complexity : O(log(n))
Space Complexity: O(log(n))
Code:
int helper(TreeNode* root,int low,int high)
{
    if(root==NULL) return 0;
    if(low>root->val)
    return helper(root->right,low,high);

    else if(high<root->val)
    return helper(root->left,low,high);
    else
    return root->val + helper(root->left,low,high) + helper(root->right,low,high);
}
int rangeSumBST(TreeNode* root, int low, int high) {
    return helper(root,low,high);
}