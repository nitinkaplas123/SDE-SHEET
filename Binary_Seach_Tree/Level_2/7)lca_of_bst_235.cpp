Steps-:
its BST 
Case1-:
if p and q are smaller than root
means both are in left side of the root
go to left side.

Case 2-:
if p and q are greater then root
means both are in right side of the root.
go to right side.

Case 3-:
either of both in different side.
left and right 
or
right and left.

here we are return the root.


Code-:
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root->val>p->val and root->val>q->val)
        return lowestCommonAncestor(root->left,p,q);
        else if(root->val<p->val and root->val<q->val)
        return lowestCommonAncestor(root->right,p,q);
        else
        return root;
}