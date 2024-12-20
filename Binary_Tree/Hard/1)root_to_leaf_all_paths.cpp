https://www.geeksforgeeks.org/problems/root-to-leaf-paths/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=root-to-leaf-paths


Code-:
void helper(Node* root,vector<int>v1,vector<vector<int>>&v)
{
        if(root==NULL)
        return ;
        v1.push_back(root->data);
        
        if(root->left==NULL and root->right==NULL)
        {
            v.push_back(v1);
            return ;
        }
        
        helper(root->left,v1,v);
        helper(root->right,v1,v);
}

vector<vector<int>> Paths(Node* root) {
       vector<vector<int>>ans;
       vector<int>v1;
       helper(root,v1,ans);
       return ans;
}