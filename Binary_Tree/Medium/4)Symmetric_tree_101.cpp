Code-:
bool helper(TreeNode* root1,TreeNode* root2)
{
        if(root1==NULL and root2==NULL) return true;
        if(root1==NULL || root2==NULL) return false;
        return (root1->val==root2->val and helper(root1->left,root2->right)
                                       and helper(root1->right,root2->left));
}

bool isSymmetric(TreeNode* root) 
{
        if(root->left==NULL and root->right==NULL) return true;
        return helper(root->left,root->right);
}


java code-:
class Solution {
    private boolean helper(TreeNode root1, TreeNode root2) {
        if (root1 == null && root2 == null) return true;
        if (root1 == null || root2 == null) return false;
        
        return (root1.val == root2.val) &&
               helper(root1.left, root2.right) &&
               helper(root1.right, root2.left);
    }

    public boolean isSymmetric(TreeNode root) {
        if (root == null) return true;  // Edge case: Empty tree is symmetric
        return helper(root.left, root.right);
    }
}