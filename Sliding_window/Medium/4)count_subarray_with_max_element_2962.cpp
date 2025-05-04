Solution 1:

Steps:
1)Find the maxx element.
2)Using sliding window we find the count of subarrays.

for eg. 
 i     j
 0 1 2 3 4
[1,3,2,3,3]   k=2
when i=0, j=3 maxCount=2 
means -: [1,3,2,3] this is the subarray we have.
but if this subarray has maxCount=2, 
infuture all the elements are also creating the subarray whose maxCount>=k

which concludes:
1)[1,3,2,3] 
2)[1,3,2,3,3]

Dry run 
1)i=0; j=0;

 j
 0 1 2 3 4
[1,3,2,3,3]
 i 

maxCount=0
ans=0

j++ 

2)i=0, j=1 

   j
 0 1 2 3 4
[1,3,2,3,3]
 i 

maxCount=1
ans=0

j++ 

3)i=0, j=2 
     j
 0 1 2 3 4
[1,3,2,3,3]
 i 

maxCount=1
ans=0

4)i=0, j=3

       j
 0 1 2 3 4
[1,3,2,3,3]
 i 

maxCount=2
ans+=(n-j)   which means all the elements after j is also contributing the subarrays.
ans=2 

5) i=1, j=3 
   
       j
 0 1 2 3 4
[1,3,2,3,3]
   i 

maxCount=2
ans+=(n-j)   
ans=2+2=4 

6) i=2, j=3 
   
       j
 0 1 2 3 4
[1,3,2,3,3]
     i 

maxCount=1
ans=2+2=4 

7) i=2, j=4 
   
         j
 0 1 2 3 4
[1,3,2,3,3]
     i 

maxCount=2
ans+=(n-j)   
ans=4+1=5

8) i=3, j=3 
   
         j
 0 1 2 3 4
[1,3,2,3,3]
       i 

maxCount=2
ans+=(n-j)   
ans=5+1=6

9)i=4, j=3 
   
         j
 0 1 2 3 4
[1,3,2,3,3]
         i 

maxCount=1
 
ans=6
j++ 

Out of the loop

O/p -: 6.

Time Complexity : O(N)
Space Complexity: O(N)

Code:
long long countSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        int maxi=0;
        for(int i=0;i<n;i++)
        {
            maxi=max(maxi,nums[i]);
        }

        long long ans=0;
        long long maxCount=0;
        int i=0;
        int j=0;
        while(j<n)
        {
            if(nums[j]==maxi)
            maxCount++;
            while(maxCount>=k)
            {
               ans+=(n-j);
               if(nums[i]==maxi)
               maxCount--;
               i++;
            }
            j++;
        }
        return ans;
}