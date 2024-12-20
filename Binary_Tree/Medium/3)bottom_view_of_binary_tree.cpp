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