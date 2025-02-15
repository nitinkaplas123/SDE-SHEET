Solution 1-:
Steps-:
1)Start from root. -> find all the path sum using solve 
  if(sum==target) count++;

2)Now your root node is change to root->left 
  and then root node is change to root->right.
  and every time call the solve function.

3) Which means u have to use every node as a root node and find all possible sum and match the sum with target. 


Time->O(N^2)
Space->O(log(n))

Code-:
void solve(TreeNode* root,int target,int &count,long long int sum)
{
    if(root==NULL) return ;
    sum+=(long long)root->val;
    if(sum==target)
    count++;

    solve(root->left,target,count,sum);
    solve(root->right,target,count,sum);
}
void helper(TreeNode* root,int target,int &count)
{
        if(root==NULL) return ;
        long long int sum=0;
        solve(root,target,count,sum);
        helper(root->left,target,count);
        helper(root->right,target,count);
}
int pathSum(TreeNode* root, int targetSum) {
        if(root==NULL) return 0;
        int count=0;
        helper(root,targetSum,count);
        return count;
}



Solution 2-:
Steps-:
1)Make a hashmap for preFixSum. 
2)using prefixSum we can able to check all the possible paths with target. 

### **Algorithm**
1. **Use DFS to traverse the tree.**  
2. **Keep track of the current sum.**  
3. **Check if a valid path exists using the prefix sum hashmap.**  
4. **Recur for left and right subtrees.**  
5. **Backtrack by decrementing the prefix sum count.**


Time ->O(N)
Space->O(N)

Code-:
void dfs(TreeNode* root, int targetSum, long long currSum, unordered_map<long long, int>& prefixSumCount, int &count) {
        if (!root) return;

        // Update the current prefix sum
        currSum += root->val;

        // Check if there exists a prefix sum that forms a valid path
        if (prefixSumCount.find(currSum - targetSum) != prefixSumCount.end()) {
            count += prefixSumCount[currSum - targetSum];
        }

        // Add current sum to prefix sum count
        prefixSumCount[currSum]++;

        // Recur for left and right subtrees
        dfs(root->left, targetSum, currSum, prefixSumCount, count);
        dfs(root->right, targetSum, currSum, prefixSumCount, count);

        // Backtrack: Remove current sum from map
        prefixSumCount[currSum]--;
}
int pathSum(TreeNode* root, int targetSum) {
        unordered_map<long long, int> prefixSumCount;
        prefixSumCount[0] = 1;  // Base case: There's one way to get sum = 0 (empty path)
        int count = 0;
        dfs(root, targetSum, 0, prefixSumCount, count);
        return count;
}

