Note -:
[1,2,3] -:

[1,2,3]
[1,3,2]
[2,1,3]
[2,3,1]
[3,1,2]
[3,2,1]

1)Now if nums ->[3,2,1] then what should be the next permutation of it. 
  there is no element after that.
  so first elements are the next permutation of it.



Solution 1-:
Steps-:
1)Generate all permutation of given array.
2)store it in a set of vector because [1,1,5] -> like this type of examples will generate duplicates array.
3)now put it into ans vector of vector.
4)search the nums vector in ans vector of vector.
  then assign nums=just next vector values.



Time->O(n*n!)
Code-:
void helper(vector<int>&nums,int index,int n,set<vector<int>>&set)
{
        if(index==n)
        {
            set.insert(nums);
            return ;
        }

        for(int i=index;i<n;i++)
        {
            swap(nums[i],nums[index]);
            helper(nums,index+1,n,set);
            swap(nums[i],nums[index]);
        }
}
void nextPermutation(vector<int>& nums) {
       int n=nums.size();
       set<vector<int>>unique_perms;
       helper(nums,0,n,unique_perms);
       vector<vector<int>> ans(unique_perms.begin(), unique_perms.end());
       int m=ans.size();
       for(int i=0;i<ans.size();i++)
       {
           int index=(i%m);
           if(ans[i]==nums)
           {
              nums=ans[(i+1)%m];
              break;
           }
       }
}



Solution 2-:
Steps-:
1)inbuilt library.

Code-:
void nextPermutation(vector<int>& nums) {
        next_permutation(nums.begin(),nums.end());
}



Solution 3-:
Steps-:
[2,1,5,4,3,0,0]

Observation-:
1) we want to find just greater number than the given element.
2) it means [2,1,5,4,3,0,1]
            [2,1,5,4,3,1,0]

here we dont have these number which i change.
 1. first change i made at last index ->         2154301
 2. first change i made at second last index ->  2154310.

 now tell me which number is next permutation of the given number.
 first number right ?

3)which means i want to change the number in very right side.
  or we can say that i dont want to change the prefix numbers as much i can
  so that i can make next greater element.


  graph -:
   
        5  
          4 
     1       3
                0  0
  2
###1 find the number where the break of mountain is.
 0 1 2 3 4 5 6
[2,1,5,4,3,0,0]

index=1 where the break point we have.


###2 i want to replace the 1 with just greater number than this in right side of it.
    
    case1 -: 2 5 1 4 3 0 0 
    case2 -: 2 4 5 1 3 0 0
    case3 -: 2 3 5 4 1 0 0 

    tell me which number is smallest -> 3 right.

here we run a loop from right side to left side to find the nums[i]>nums[index].

 0 1 2 3 4 5 6          ind
[2,1,5,4,3,0,0]    -> [2,3,5,4,1,0,0]


  
### 3 now -> [2,3] is okay   [5,4,1,0,0] -> i want this number to be smallest.
so just sort it. 

or we know that this is always sorted in reverse order.
so in terms of sort -> just swap the element from left with right.



Note -: this code is also take care of when 
arr is reverse sorted 

arr-> [3,2,1]  -> answer -> [1,2,3]

Step 1 -: index=0 (donot check any if condition here)
Step 2 -: (never ever it swap).
which means till now we can say that its reverse sorted.

Step3 -: sorted the array using low and high pointer.


Time->O(N)
Space->O(1)
Code-:
void nextPermutation(vector<int>& nums) {
        int n=nums.size();
       int index=0;
       for(int i=n-2;i>=0;i--)
       {
          if(nums[i]<nums[i+1])
          {
            index=i;
            break;
          }
       }
       
       for(int i=n-1;i>=0;i--)
       {
           if(nums[i]>nums[index])
           {
              swap(nums[i],nums[index]);
              index++;
              break;
           }
       }
       
       int low=index;
       int high=n-1;
       while(low<high)
       {
           swap(nums[low],nums[high]);
           low++;
           high--;
       }
}
        

