Solution 1-:
Steps-:
1)using level order traversal. 
2)count the swap using min swap to sort an array.


Time->O(N) +O(Nlog(n)) for queue traversal + sort the each level.
Space->O(N)+O(N) 
Code-:
int helper(vector<int>&v1)
    {
        vector<pair<int,int>>v;
        int i=0;

        for(int i=0;i<v1.size();i++)
        {
            v.push_back({v1[i],i});
        }
        
        sort(v.begin(),v.end());

        i=0;
        int count=0;
        while(i<v.size())
        {
            int index=v[i].second;
            if(i!=index){
                swap(v[i],v[index]);
                count++;
            }
            else
            i++;
        }
        return count;
    }
    int minimumOperations(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        vector<int>v1;
       
        int count=0;
        while(q.empty()==false)
        {
           int size=q.size();
           if(size>1)
           count+=helper(v1);
           v1.clear();
           for(int i=0;i<size;i++)
           {
                TreeNode* curr=q.front();
                q.pop();
                
                if(curr->left!=NULL){
                q.push(curr->left);
                v1.push_back(curr->left->val);
                }
                if(curr->right!=NULL){
                q.push(curr->right);  
                v1.push_back(curr->right->val);
                }
           }
        }
        return count;
    }