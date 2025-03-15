Steps-:
1)in top view we see binary tree like 
       0 
    -1    1
-2    0  0   2  


2) Here we see binary tree as -:
       0
    1     2
3    4   5    6 

level1 => 1-1+1  -> 1 
level2 -> 3-2+1  -> 2 
level3 -> 7-4+1  -> 4 




Code-:
int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*,int>>q;
        q.push({root,0});
        int ans=1;

        while(!q.empty())
        {
            int first=q.front().second;
            int last=q.back().second;
            ans=max(ans,last-first+1);

            int size=q.size();
            for(int i=0;i<size;i++)
            {
                TreeNode* curr=q.front().first;
                int h=q.front().second;
                q.pop();

                if(curr->left)
                q.push({curr->left,(long long)2*h+1});
                
                if(curr->right)
                q.push({curr->right,(long long)2*h+2});
                
            }
        }
        return ans;
}


java -:
class Solution {
    public int widthOfBinaryTree(TreeNode root) {
          if (root == null) return 0;

        Queue<Pair<TreeNode, Integer>> q = new LinkedList<>();
        q.offer(new Pair<>(root, 0));
        int ans = 1;

        while (!q.isEmpty()) {
            int size = q.size();
            int first = q.peek().getValue();
            int last = first; // Default to first in case there's only one node at the level

            for (int i = 0; i < size; i++) {
                Pair<TreeNode, Integer> curr = q.poll();
                TreeNode node = curr.getKey();
                int index = curr.getValue();
                last = index; // Update last node index

                if (node.left != null)
                    q.offer(new Pair<>(node.left, 2 * index + 1));

                if (node.right != null)
                    q.offer(new Pair<>(node.right, 2 * index + 2));
            }

            ans = Math.max(ans, last - first + 1);
        }

        return ans;
    }
}