

Code-: Time->O(log(N))
TreeNode* searchBST(TreeNode* root, int val) {
        while(root!=NULL)
        {
            if(root->val==val)
            return root;
            else if(root->val<val)
            root=root->right;
            else
            root=root->left;
        }
        return NULL;
}