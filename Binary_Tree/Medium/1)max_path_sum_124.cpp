Code-:
int helper(TreeNode* root,int &res)
{
        if(root==NULL) return 0;
        int left=helper(root->left,res);
        int right=helper(root->right,res);
        res=max(res,max(root->val,max(root->val+left,max(root->val+right,root->val+left+right))));
        return max(root->val,max(left+root->val,right+root->val));
}

int maxPathSum(TreeNode* root) {
        int res=INT_MIN;
        helper(root,res);
        return res;
}



Java Code-:
class Solution {
    private int helper(TreeNode root, int[] res) {
        if (root == null) return 0;

        int left = helper(root.left, res);
        int right = helper(root.right, res);

        res[0] = Math.max(res[0], Math.max(root.val, Math.max(root.val + left, 
                    Math.max(root.val + right, root.val + left + right))));

        return Math.max(root.val, Math.max(left + root.val, right + root.val));
    }

    public int maxPathSum(TreeNode root) {
        int[] res = {Integer.MIN_VALUE}; // Use an array to store max result
        helper(root, res);
        return res[0];
    }
}