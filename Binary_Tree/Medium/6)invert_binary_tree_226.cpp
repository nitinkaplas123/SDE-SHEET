Solution 1-:
Steps-:
1) go to extreme left. 
2) go to extreme right.
3) swap the node 
4) continue the process.

Conclude-> means swap the nodes from bottom and going up while swapping.


Time->O(N)
Code-:
void helper(TreeNode* root)
{
        if(root==NULL) return ;
        helper(root->left);
        helper(root->right);
        swap(root->left,root->right);
        return ;
}
TreeNode* invertTree(TreeNode* root) {
        helper(root);
        return root;
}


java Code-:
class Solution {
    private void helper(TreeNode root) {
        if (root == null) return;

        helper(root.left);
        helper(root.right);

        // Swap left and right children
        TreeNode temp = root.left;
        root.left = root.right;
        root.right = temp;
    }

    public TreeNode invertTree(TreeNode root) {
        helper(root);
        return root;
    }
}