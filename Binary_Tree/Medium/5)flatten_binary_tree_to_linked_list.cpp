Question -:
1)Convert binary tree into linked list as a preorder traversal.
  means -> root left right.
2)root->right=prev element.
3)root->left=NULL (always Null).

Solution 1-:
Steps-:
1)Using recursion we are solving this.
2)if its recursion go first -> right,left,root so that its preorder traversal.
3)Root->right=prev.
4)Root->left=NULL.

Time->O(N) Space->O(log(N)).
Code-:
void helper(TreeNode* root,TreeNode* &prev)
{
        if(root==NULL) return ;
        helper(root->right,prev);
        helper(root->left,prev);
        root->right=prev;
        root->left=NULL;
        prev=root; 
}
void flatten(TreeNode* root) {
        TreeNode* prev=NULL;
        helper(root,prev);
}