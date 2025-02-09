Solution 1-:
Steps-:
1)Here we are using visited array and v as a vector.
2)We have to do in deep of n element             -> index 0 to n
and at each call we have to traverse whole array -> i=0;i<n

3)index help me to take all the values in per permutation.
4) i=0;i<n help me to choose every value.
5)Make a tree diagram of it.




[1,2,3]

                            []
          /         |         \
        [1]       [2]       [3]      → n choices
      /    \      /    \     /    \
  [1,2]  [1,3] [2,1] [2,3] [3,1] [3,2]  → (n-1) choices
     |       |     |      |     |      |
 [1,2,3] [1,3,2] [2,1,3] [2,3,1] [3,1,2] [3,2,1]  → (n-2) choices

Each node in the recursion tree represents a function call, and the number of calls follows:

n+(n-1)+(n-2)+...+1=O(n!)
n+(n−1)+(n−2)+...+1=O(n!)
This is because:

The first call makes n recursive calls.
The second level makes (n-1) calls per previous call.
The third level makes (n-2) calls per previous call, and so on.
Since we reach n! leaves, the number of function calls is O(n!)

Time->O(n!*n)
Space->O(n)
Code-:
void helper(vector<int>&nums,int index,int n,vector<int>&v,vector<bool>&visited,vector<vector<int>>&ans)
{ 
        if(index==n)
        {
            ans.push_back(v);
            return ;
        }
        for(int i=0;i<n;i++)
        {
            if(visited[i]==false)
            {
                visited[i]=true;
                v.push_back(nums[i]);
                helper(nums,index+1,n,v,visited,ans);
                visited[i]=false;
                v.pop_back();
            }
        }
}
vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        int n=nums.size();

        int index=0;
        vector<int>ds;
        vector<bool>visited(n,false);
        helper(nums,index,n,ds,visited,ans);
        return ans;
}



Solution 2-:
Steps-:
1)using swapping of nums[index],nums[i].

2)here index -> 0 to n.
3)i=index;i<n. 

Diagram-:


                            [1,2,3]
                /              |               \
          [1,2,3]          [2,1,3]          [3,2,1]
           /     \           /     \          /     \
     [1,2,3]  [1,3,2]  [2,1,3]  [2,3,1]  [3,2,1]  [3,1,2]



Time->O(n!*n)   -> recursive call ->O(n!)  loop in each call ->O(n) -> O(n*n!).
Space->O(n)
Code-:
void helper(vector<int>&nums,int index,int n,vector<vector<int>>&ans)
{
        if(index==n)
        {
            ans.push_back(nums);
            return ;
        }
        for(int i=index;i<n;i++)
        {
            swap(nums[i],nums[index]);
            helper(nums,index+1,n,ans);
            swap(nums[i],nums[index]);
        }
}
vector<vector<int>> permute(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>ans;
        int index=0;
        helper(nums,index,n,ans);
        return ans;
}