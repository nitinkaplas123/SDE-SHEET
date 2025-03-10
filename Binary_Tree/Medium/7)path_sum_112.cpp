Solution 1-:
Steps-:
1)Making sum varible which stores the sum of root to leaf.
2)if any path sum is equal to target -> make ans=true.
Code-:
void helper(TreeNode* root,int target,int sum,bool &ans)
{
         if(root==NULL) return ;
         sum+=root->val;

         if(root->left==NULL and root->right==NULL)
         {
            if(sum==target)
            ans=true;
            return ;
         }
         helper(root->left,target,sum,ans);
         helper(root->right,target,sum,ans);
}
bool hasPathSum(TreeNode* root, int targetSum) {
         int sum=0;
         bool ans=false;
         helper(root,targetSum,sum,ans);
         return ans;
}


