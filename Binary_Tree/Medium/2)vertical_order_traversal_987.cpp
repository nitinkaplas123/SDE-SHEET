Steps-:
1)Multiset works for elements in sorted order if the 
  element is at same dist and same level. 
2)while for loop in 2nd step-:
  1) for -> dist 
  2) for -> level
  3) for -> multiset




Code-: Time->O(Nlog(k)) where N is the no. of nodes and k is the multiset 
                        because its works on binary search
void helper(TreeNode* root,map<int,map<int,multiset<int>>>&m,int dist,int level)
{
         if(root==NULL) return ;
         m[dist][level].insert(root->val);

         helper(root->left,m,dist-1,level+1);
         helper(root->right,m,dist+1,level+1);
}

vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>>v;
        map<int,map<int,multiset<int>>>m;
        int dist=0;
        int level=0;
        helper(root,m,dist,level);
        vector<int>v1;
        for(auto x:m)
        {
            for(auto y:x.second)
            {
                for(auto z:y.second)
                {
                    v1.push_back(z);
                }
            }
            v.push_back(v1);
            v1.clear();
        }
        return v;
}