Solution 1-:
Steps-:

1) Case1-: 
   if root is null.
   {0,0} -> {rob,skip}.

2) left_choices[2] -> [rob,skip].
   right_choices[2]-> [rob,skip].

2) At every node -> we have two options -> {rob,skip}.
   
   rob -> {rob the house} + skip(left_child) + skip(right_child).
   skip -> {max(left[0],left[1])} +        max(right[0],right[1]).  
          either rob the left or skip.     either rob the right or skip the right.
   
Time->O(N)
Space->O(h) -> height of tree. or O(N) for skew tree.
Code-:
pair<int,int> helper(TreeNode* root)
{
        if(root==NULL) return {0,0};
        pair<int,int>left_choices=helper(root->left);
        pair<int,int>right_choices=helper(root->right);

        int rob= root->val+left_choices.second + right_choices.second;
        int skip=max(left_choices.first,left_choices.second) + max(right_choices.first,right_choices.second);
        return {rob,skip};
}
int rob(TreeNode* root) {
        pair<int,int>ans=helper(root);
        return max(ans.first,ans.second);
}