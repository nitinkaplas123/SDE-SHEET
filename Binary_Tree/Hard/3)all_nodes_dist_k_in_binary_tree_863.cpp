Reference -> striver video.


Steps-:
1)Make a parent child map. 
2)now we have to find k=2 means 
  queue -> add root 
  this is the 0th dist. 
3)We make visited array for marked visited which already visited by us.
  dist==k 
  whatever we have in queue all nodes are our answer.

Code-: Time->O(N)
void parent(TreeNode* root,unordered_map<TreeNode*,TreeNode*>&m)
{
        queue<TreeNode*>q;
        q.push(root);
        m[root]=NULL;

        while(q.empty()==false)
        {
            TreeNode* curr=q.front();
            q.pop();

            if(curr->left)
            {
                m[curr->left]=curr;
                q.push(curr->left);
            }
            if(curr->right)
            {
                m[curr->right]=curr;
                q.push(curr->right);
            }
        }
}
vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int>v;

        //parent 
        unordered_map<TreeNode*,TreeNode*>m;
        parent(root,m);

        // find all nodes dist k. 
        queue<TreeNode*>q;
        unordered_map<TreeNode*,bool>visited(false);
        q.push(target);
        visited[target]=true;
        
        int dist=0;
        while(dist<k)
        {
           int size=q.size();
           for(int i=0;i<size;i++)
           {
              TreeNode* curr=q.front();
              q.pop();

              if(m[curr]!=NULL and visited[m[curr]]==false)
              {
                 q.push(m[curr]);
                 visited[m[curr]]=true;
              }
              if(curr->left and visited[curr->left]==false)
              {
                q.push(curr->left);
                visited[curr->left]=true;
              }
              if(curr->right and visited[curr->right]==false)
              {
                q.push(curr->right);
                visited[curr->right]=true;
              }
           }
           dist++;
        }

        while(q.empty()==false)
        {
            int val=q.front()->val;
            q.pop();
            v.push_back(val);
        }
        return v;
  }