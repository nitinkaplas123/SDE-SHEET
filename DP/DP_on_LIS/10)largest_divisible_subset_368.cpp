Question -:
Largest divisible subset -> 


1)Arr[]={1,2,3}
Subset -:
1)order doesnot matter 

{1},{1,2},{3,1}

Subsequence -:
1)order does matter.
{1},{1,2},{1,3}.

2)Question said return the subset of elements whose every pair satisfied the condition -> {nums[i]%nums[j]==0 || nums[j]%nums[i]==0}.
eg [1,2,4,8]
1-> pairs with {2,4,8}   ->  {1,2},{1,4},{1,8} 
2-> pairs with {4,8}    ->   {2,4},{2,8}
4 ->           {8}     ->    {4,8}

means every element -> pairs with (n-1) elements -> it should satisfied the condition.



Steps-:
1) Sorting the array makes -:
  1.Longest divisible subset -> longest divisible subsequence 
  2. [1,2,4,8]
   
   if i check 4 is divisble by 2. 
   then automatically i can say that 4 is also divisible by 1.

   Similarily -:
   if 8 is divisible by 4 then 8 is also divisible by 4 and 1. -> No need to check that.

2)Do the same steps what we did in printing the lis.
  if(nums[i]>nums[j])
  changes to 

  if(nums[i]%nums[j]==0)

3)hash array where we store the paths of lis.
4)backtrack the hash array to get the lds.



Time->O(N^2)
Space->O(n)
Code-:
vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<int>temp(n,1);
        vector<int>hash(n);
        for(int i=0;i<n;i++){
            hash[i]=i;
        }
        
       
        int maxx=1;
        int index=0;
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if((nums[i]%nums[j]==0))
                {
                    if(temp[i]<1+temp[j])
                    {
                      temp[i]=1+temp[j];
                      hash[i]=j;
                    }
                }
            }
            if(maxx<temp[i])
            {
                maxx=temp[i];
                index=i;
            }
        }
        vector<int>ans;
        ans.push_back(nums[index]);
        while(hash[index]!=index)
        {
            index=hash[index];
            ans.push_back(nums[index]);
        }
        
        reverse(ans.begin(),ans.end());
        return ans;
    }