Solution 1-:
Steps-: 
1)Helper function 
  Make a map for parent child relationship where we have to store the map key:value, curr:parent.
2)Find function 
  where we make node which is pointing to target node.
3)Now using bfs we traverse the whole tree from node and using visited map we mark it if its visited.
  Here we go 3 directions.
  1. Go to the parent of curr node.
  2. Go to left of the curr node.
  3. Go to right of the curr node.



Time ->O(N) Space->O(N)
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
    void target_node(TreeNode* root,TreeNode* &node,int start)
    {
        if(root==NULL) return ;
        if(root->val==start)
        {
            node=root;
            return ;
        }
        target_node(root->left,node,start);
        target_node(root->right,node,start);
    }
    int amountOfTime(TreeNode* root, int start) {
        //parent 
        unordered_map<TreeNode*,TreeNode*>m;
        parent(root,m);

        //target node
        TreeNode* node=NULL;
        target_node(root,node,start);


        // time calculate
        queue<TreeNode*>q;
        unordered_map<TreeNode*,bool>visited(false);
        int time=0;
        q.push(node);
        visited[node]=true;

        while(q.empty()==false)
        {
            int size=q.size();
            for(int i=0;i<size;i++)
            {
                TreeNode* curr=q.front();
                q.pop();

                if(m[curr] and visited[m[curr]]==false)
                {
                    visited[m[curr]]=true;
                    q.push(m[curr]);
                }
                if(curr->left and visited[curr->left]==false)
                {
                    visited[curr->left]=true;
                    q.push(curr->left);
                }
                if(curr->right and visited[curr->right]==false)
                {
                    visited[curr->right]=true;
                    q.push(curr->right);
                }
            }
            time++;
        }
        return time-1;
    }