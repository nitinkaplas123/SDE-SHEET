Solution 1-:
Steps-:
1)go from root-> leaf -> sum variable.
2) values are in v1 vector.

Code-:
void helper(TreeNode* root, int target,int sum,vector<int>v1,vector<vector<int>>&ans)
{
        if(root==NULL) return ;
        sum+=root->val;
        v1.push_back(root->val);

        if(root->left==NULL and root->right==NULL)
        {
            if(sum==target)
            ans.push_back(v1);
            return ;
        }

        helper(root->left,target,sum,v1,ans);
        helper(root->right,target,sum,v1,ans);
}
vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>>ans;
        int sum=0;
        vector<int>v1;
        helper(root,targetSum,sum,v1,ans);
        return ans;
}


Solution 2-:
Steps-:
1)with reference.

Code-:
void helper(TreeNode* root, int target,int &sum,vector<int>&v1,vector<vector<int>>&ans)
{
        if(root==NULL) return ;
        sum+=root->val;
        v1.push_back(root->val);

        if(root->left==NULL and root->right==NULL)
        {
            if(sum==target)
            ans.push_back(v1);
            v1.pop_back();
            sum-=root->val;
            return ;
        }

        helper(root->left,target,sum,v1,ans);
        helper(root->right,target,sum,v1,ans);
        v1.pop_back();
        sum-=root->val;
}
vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>>ans;
        int sum=0;
        vector<int>v1;
        helper(root,targetSum,sum,v1,ans);
        return ans;
}