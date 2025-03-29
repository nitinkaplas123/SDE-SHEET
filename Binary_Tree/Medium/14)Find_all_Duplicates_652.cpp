why ?

str=left+right+to_string(root->val)


str=left+to_string(root->val)+right
example=:

  1          $1$1$            

1     $

$1$


final -> $1$1$  


    1   

         1 


 1 -> $1$

 1 
    1 



left=> $      right => $1$    

str=$1$1$


which is wrong. 



why demitor ","   -> searching 

Code-:
string helper(TreeNode* root,string str,unordered_map<string,int>&m,vector<TreeNode*>&ans)
{
        if(root==NULL)
        return "$";

        string left=helper(root->left,str,m,ans);
        string right=helper(root->right,str,m,ans);
        str=left+","+right+","+to_string(root->val);

        m[str]++;

        if(m[str]==2)
        ans.push_back(root);
        return str;
}
vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode*>ans;
        string str="";
        unordered_map<string,int>m;
        helper(root,str,m,ans);
        return ans;
}