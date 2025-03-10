Question-:
1)x and y are called as cousins when they both have different parents and they both have same depth.
  
cousins ->   par1!=par2 and level1==level2

Solution 1-:
Steps-:
1)Make a map of parent child relationship.
2)Now find the dep1 of x and find the dep2 of y.
3)If m[x]!=m[y] and dep1==dep2.

Time ->O(N)
Space ->O(N)
Code-:
void helper(TreeNode* root,unordered_map<int,TreeNode*>&m)
{
        queue<TreeNode*>q;
        // unordered_map<TreeNode*,bool>visited;
        q.push(root);
        // visited[root]=true;
        m[root->val]=NULL;
        while(!q.empty())
        {
            TreeNode* curr=q.front();
            q.pop();

            if(curr->left)
            {
               m[curr->left->val]=curr;
               q.push(curr->left);
            }
            if(curr->right)
            {
                m[curr->right->val]=curr;
                q.push(curr->right);
            }
        }
}
void helper1(TreeNode* root,int value,int level,int &ans)
{
         if(root==NULL) return ;
         if(root->val==value) 
         {
            ans=level;
            return ;
         }
         helper1(root->left,value,level+1,ans);
         helper1(root->right,value,level+1,ans);
}
bool isCousins(TreeNode* root, int x, int y) {
        //parent 
        unordered_map<int,TreeNode*>m;
        helper(root,m);

        if(m[x]==m[y]) return false;

        // depth 
        int dep1=0;
        helper1(root,x,0,dep1);

        int dep2=0;
        helper1(root,y,0,dep2);

        return (dep1==dep2);
}



Solution 2-:
Steps-:
1)Using level order traversal we can update 
  par1 and par2 
  level1 and level2.
2)if par1!=par2 and level1==level2.


Time->O(N)
Space->O(N)
Code-:
bool isCousins(TreeNode* root, int x, int y) {
         queue<pair<TreeNode*,int>>q;
         q.push({root,0});
         
         int par1=0;
         int par2=0;
         int level1=0;
         int level2=0;
         while(!q.empty())
         {
            TreeNode* curr=q.front().first;
            int level=q.front().second;
            q.pop();

            if(curr->left)
            {
               if(curr->left->val==x)
               {
                  par1=curr->val;
                  level1=level+1;
               }
               if(curr->left->val==y)
               {
                  par2=curr->val;
                  level2=level+1;
               }
               q.push({curr->left,level+1});
            }
            if(curr->right)
            {
               if(curr->right->val==x)
               {
                  par1=curr->val;
                  level1=level+1;
               }
               if(curr->right->val==y)
               {
                  par2=curr->val;
                  level2=level+1;
               }
               q.push({curr->right,level+1});
            }
         }
         return (par1!=par2 and level1==level2);
}


