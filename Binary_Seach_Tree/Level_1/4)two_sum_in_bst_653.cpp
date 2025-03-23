Solution 1-:
Steps-:
1)store the node value in inorder fashion.
2)Usinfg 2 pointer we can check.

Time->  O(N)
Space ->O(N)
Code-:
void helper(TreeNode* root,vector<int>&v)
{
        if(root==NULL) return ;
        helper(root->left,v);
        v.push_back(root->val);
        helper(root->right,v);
}
bool findTarget(TreeNode* root, int k) {
         vector<int>v;
         helper(root,v);

         int low=0;
         int high=v.size()-1;
         while(low<high)
         {
             int sum=v[low] + v[high];
             if(sum==k) return true;
             else if(sum<k)
             low++;
             else
             high--;
         }
         return false;
}



Solution 2-:
Steps-:
1)using precessor -> pending.