Solution 1-:
Steps-:
1)Here its a BST so its inorder traversal is always in a sorted manner.
2)Make a vector v where we are storing the values of node in inorder fashion which is sorted.
3)Now check its sorted or not.


Code-: Time->O(N) Space->O(N)
void helper(Node* root,vector<int>&v)
{
        if(root==NULL) return ;
        helper(root->left,v);
        v.push_back(root->data);
        helper(root->right,v);
}

bool isBST(Node* root) 
{
       vector<int>v;
       helper(root,v);
       int n=v.size();
       for(int i=0;i<n-1;i++)
       {
           if(v[i]>=v[i+1]) return false;
       }
       return true;
}


Solution 2-:
Steps-:
1) Here we use prev variable where we store the just prev value in inorder fashion and compare with root 
   where root is (i+1) value in inorder and prev is (ith) value.
2) if the prev>=root(curr) its means its not sorted which means its not BST.

Code-:
void helper(Node* root,int &prev,int &res)
{
        if(root==NULL) return ;
        helper(root->left,prev,res);
        
        if(root->data<=prev) res=0;
        prev=root->data;
        
        helper(root->right,prev,res);
}

bool isBST(Node* root) 
{
       int prev=INT_MIN;
       int res=1;
       helper(root,prev,res);
       return res;
}

Solution 3-: When its -ve values.
Code-:
void helper(TreeNode* root,TreeNode* &prev,bool &ans)
{
        if(root==NULL)
        return ;

        helper(root->left,prev,ans);
        if(prev!=NULL)
        {
          if(prev->val>=root->val)
          ans=false;
        }
        
        prev=root;

        helper(root->right,prev,ans);
}

bool isValidBST(TreeNode* root) {
        TreeNode* prev=NULL;
        bool ans=true;
        helper(root,prev,ans);
        return ans;
}