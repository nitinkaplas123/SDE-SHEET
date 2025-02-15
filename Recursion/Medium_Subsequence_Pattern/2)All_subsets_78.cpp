Code-: Time0->O(2^n)*n   -> 2^n for recursive calls and at each recursive calls we store v1 into v which takes o(n) TIME 
       Space->O(2^n)*n 

void helper(vector<int>&nums,int index,int n,vector<vector<int>>&v,vector<int>v1)
{
        if(index==n)
        {
            v.push_back(v1);
            return ;
        }

        //not included
        helper(nums,index+1,n,v,v1);
        
        //included
        v1.push_back(nums[index]);
        helper(nums,index+1,n,v,v1);
}

vector<vector<int>> subsets(vector<int>& nums) {
          int n=nums.size();
          vector<vector<int>>v;
          vector<int>v1;
          int index=0;
          helper(nums,index,n,v,v1);
          return v;
}


explanation -:

Great question! Let's address why we don't explicitly consider the time complexity for every node in the recursion tree and instead focus on the total number of recursive calls and the work done at each call.

Recursion Tree for Generating Subsets
Let's look at a part of the recursion tree you've mentioned, and clarify how the time complexity is calculated.

                           []
                        /      \
                [1]             []
               /    \           /    \
          [1, 2]   [1]   [2]       []
         /    \    /   \   /   \    /   \
    [1, 2, 3] [1, 3] [1, 2] [1] [2, 3] [2] [3] []
This tree represents all the possible subsets of a set of size 3, for example, nums = [1, 2, 3].

Recursion Breakdown:
At each level of the tree: We either include or exclude the element at the current index.
Leaf nodes (at depth n) represent the subsets we’ve formed at the base case, where index == n (i.e., all elements have been processed). At each of these leaf nodes, we will add the subset to the result list.
Time Complexity Analysis — Focusing on the Leaf Nodes and Work Done:
We don't explicitly need to consider the entire structure of the recursion tree when analyzing time complexity. Instead, we focus on:

The total number of recursive calls (or subproblems).
The work done in each recursive call.
Here’s how we break it down:

1. Number of Recursive Calls (Subproblems)
The key observation is that there are 
2
n
2 
n
  subsets of an array of size 
n
n. For each element in the array, we have two choices: either include it in the current subset or exclude it. This leads to 
2
n
2 
n
 possible combinations, corresponding to the number of leaf nodes in the recursion tree.

Each node in the recursion tree represents a decision point where you either include or exclude an element.
At each leaf node, you have reached a valid subset.
The total number of recursive calls is therefore 
2
n
2 
n
 , because there are 
2
n
2 
n
  subsets in total, and the recursion tree has 
2
n
2 
n
  leaf nodes at depth n.

2. Work Done at Each Recursive Call
The key here is the work done at each recursive call. At each base case (i.e., when index == n), the algorithm:

Appends the current subset (v1) to the result list v.
Now, let’s think about the time complexity at each of these calls:

Each subset that is generated at the leaf nodes can have at most n elements (since there are n elements in nums).
The work done at each base case is to append the current subset to the result, which requires copying the subset into the result list v.
Copying a subset of size k to v takes O(k) time. In the worst case, a subset can have up to n elements. Therefore, at each leaf node, the time complexity for appending the subset is O(n).

3. Total Time Complexity Calculation
Now, we can calculate the total time complexity by considering the number of calls and the work done at each call:

There are 
2
n
2 
n
  recursive calls (or subproblems) because there are 
2
n
2 
n
  subsets.
For each of the 
2
n
2 
n
  recursive calls, the work done at the leaf nodes (base cases) is 
O
(
n
)
O(n), because each subset can have up to n elements, and copying the subset takes 
O
(
n
)
O(n) time.
Therefore, the total time complexity is:

Time complexity
=
O
(
2
n
⋅
n
)
Time complexity=O(2 
n
 ⋅n)
Why Not Consider Every Node in the Tree?
In the recursion tree, non-leaf nodes (nodes before reaching depth n) don’t actually do much work — they just recurse deeper into the tree. These non-leaf nodes correspond to decisions like "include nums[i]" or "exclude nums[i]". But they do not contribute to the overall time complexity directly; only the work done at the leaf nodes (where the recursion stops) matters for calculating the time complexity.
Each recursive call (whether it is at a non-leaf node or a leaf node) has constant overhead (i.e., checking whether to include/exclude an element), but the significant work happens at the leaf nodes, where subsets are appended to the result.
So, the work done in non-leaf nodes does not contribute significantly to the overall time complexity because:

They do not append subsets to the result list.
They simply make recursive calls without adding much computational overhead (other than making a binary choice of whether to include or exclude an element).
Summary of Time Complexity:
Number of recursive calls: 
2
n
2 
n
  because there are 
2
n
2 
n
  possible subsets.
Work done at each base case (leaf node): 
O
(
n
)
O(n) to copy the subset to the result list.
Thus, the total time complexity is:

O(2n⋅n) O(2 n ⋅n)
This is the overall time complexity of the algorithm for generating all subsets of the input array nums.

Space Complexity:
The space complexity arises from:

The recursion stack, which goes up to a depth of 
n
n (since each recursive call moves to the next index).
The space needed to store the result, which contains all 2n2 n
  subsets, and each subset takes
O(n)
O(n) space.
Therefore, the total space complexity is:

O(2n⋅n+n)=O(2n⋅n)O(2 n ⋅n+n)=O(2 n ⋅n)



Solution 2-:
Steps-:
1)Using bitwise 

n=3  p=2^n -> 8 

0   -> 000
1   -> 001 
2   -> 010
3   -> 011
4   -> 100
5   -> 101
6   -> 110
7   -> 111


Code-: Time->O(2^n*n)
vector<vector<int>> subsets(vector<int>& nums) {
        int n=nums.size();
        int p=pow(2,n);
        vector<vector<int>>v(p);
        
        for(int i=0;i<p;i++)
        {
            for(int j=0;j<n;j++)
            {
                if((1<<j) & i)
                v[i].push_back(nums[j]);
            }
        }
        return v;
}



