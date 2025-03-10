Steps-:
Case1-:

1->right 4   1->left=NULL
what is my answer -> [1,4]
if(curr->left==NULL)
{
    ans.push_back(curr->val);
    curr=curr->right;
}

Case2-: 
1)Firstly go to level2 make at connection of extreme right with level1.
  where level1 is curr and prev is at level2 right most 
  prev->right=curr. 
  similarily go down and make connections.

TreeNode* prev=curr->left;
while(prev->right!=NULL and prev->right!=curr)
{
    prev=prev->right;
}

1) if(prev->right==NULL)
   it means make connection prev->right=curr and curr ko bolo ek step niche aa ja.

2) if(prev->right==curr).
   ab connection thor do.



Time->O(N)
Space->O(1)
Code-:
vector<int> inorderTraversal(TreeNode* root) {
        vector<int>ans;
        TreeNode* curr=root;
        while(curr!=NULL)
        {
            if(curr->left==NULL)
            {
                ans.push_back(curr->val);
                curr=curr->right;
            }
            else
            {
                TreeNode* prev=curr->left;
                while(prev->right!=NULL and prev->right!=curr)
                {
                    prev=prev->right;
                }

                if(prev->right==NULL)
                {
                    prev->right=curr;
                    curr=curr->left;
                }
                else
                {
                   prev->right=NULL;
                   ans.push_back(curr->val);
                   curr=curr->right;
                }
            }
        }
        return ans;
}