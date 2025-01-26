Solution 1-:
Using recursion

Code-:
void helper(Node* root,map<int,pair<int,int>>&m,int dist,int level)
{
        if(root==NULL) return ;
        if(m[dist].second==0 || m[dist].first<=level)
        m[dist]={level,root->data};
        
        helper(root->left,m,dist-1,level+1);
        helper(root->right,m,dist+1,level+1);
}

vector <int> bottomView(Node *root) {
        vector<int>v;
        map<int,pair<int,int>>m;
        helper(root,m,0,0);
       
        for(auto x:m)
        {
            v.push_back(x.second.second);
        }
        return v;
}


Solution 2-:
Using level order traversal 

Code-:
vector <int> bottomView(Node *root) {
        vector<int>ans;
        queue<pair<int,Node*>>q;
        map<int,int>m;
        q.push({0,root});
        while(!q.empty())
        {
            int h=q.front().first;
            Node* curr=q.front().second;
            q.pop();
            
            m[h]=curr->data;
            if(curr->left)
            q.push({h-1,curr->left});
            if(curr->right)
            q.push({h+1,curr->right});
        }
        
        for(auto x:m)
        {
            ans.push_back(x.second);
        }
        return ans;
}