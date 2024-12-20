Steps-:
1)in top view we see binary tree like 
       0 
    -1    1
-2    0  0   2  


2) Here we see binary tree as -:
       0
    1     2
3    4   5    6 

level1 => 1-1+1  -> 1 
level2 -> 3-2+1  -> 2 
level3 -> 7-4+1  -> 4 




Code-:
int widthOfBinaryTree(TreeNode* root) 
{
        queue<pair<TreeNode*,int>>q;
        q.push({root,1});
        int ans=1;
        while(q.empty()==false)
        {
            int first=q.front().second;
            int last=q.back().second;
            ans=max(ans,last-first+1);
            int size=q.size();
            for(int i=0;i<size;i++)
            {
                TreeNode* curr=q.front().first;
                int index=q.front().second;
                q.pop();
                if(curr->left)
                q.push({curr->left,(long long)2*index+1});
                if(curr->right)
                q.push({curr->right,(long long)2*index+2});
            }
        }
        return ans;
}