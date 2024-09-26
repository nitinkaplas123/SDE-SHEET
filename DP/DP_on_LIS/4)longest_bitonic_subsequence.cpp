https://www.geeksforgeeks.org/problems/longest-bitonic-subsequence0824/1



Bitonic -:
A subsequence of array is called Bitonic if it is first strictly increasing, then strictly decreasing. 
Return the maximum length of bitonic subsequence.

Note-: 
A strictly increasing only or a strictly decreasing sequence only should not be considered as a bitonic sequence.
which means if our array is sorted or reverse sorted then we have to return 0 bcz strictly increasing or strictly decreasing is not consider
as bitonic subsequence.


Steps-:
1)vector<int>v1 -> where we storing the  increaing ->lis.
2)vector<int>v2 -> where we storing the  decreasing ->lds.
3)now run a loop 
  for(int i=0;i<n;i++)
  {
	if(v1[i]>1 and v2[i]>1)
	ans=max(ans,v1[i]+v2[i]-1);
  }
  
  at point i -> we see the lis from ->v1[i];
  at point i-> we see the  lds from ->v2[i];
  means at same point we see the incresing subsequence from v1[i] which is from i to left side.
                                 decresing subsequence from v2[i] which is from i to right side.

  so i will be using 2 times thats why we have to do (-1).
   ans=max(ans,v1[i]+v2[i]-1);                     


4) Note point is donot consider the whole array is strictly increasing or strictly decreasing. 
   in this case return 0;

  eg. 
  arr[]={1,2,3,4,5}

  lis ->{1,2,3,4,5}
  lds ->{1,1,1,1,1}


  eg.
  arr[]={5,4,3,2,1}

  lis->{1,1,1,1,1}
  lds->{5,4,3,2,1}

  in both cases we have one length either in sorted or reverse sorted. 
  this 2 cases we dont have to considered.
  thats why  
  if(v1[i]>1 and v2[i]>1)
  only in this case we have to update the ans.



eg. 
6
arr[]={1, 4, 2, 7, 9, 10}
lis[]={1, 2, 2, 3, 4, 5}
lds[]={1,2,1,1,1,1}

at any point we got (v1[i]==1 or v2[i]==1) that point is not bitonic. thats it.
 
Your Code's output is: 
5
It's Correct output is: 
3


here i am fail bcz i am thinking if whole array is sorted and reverse sorted thats where we have to return 0 -> thats not bitonic .
so 

if in middle of pointer i -> if we see that particular point we see all increaing v1[i]>1 and same point we have v2[j]=1 means 
we have not consider that point 
or vice versa.

void helper(vector<int>&nums,vector<int>&v1)
	{
	    int n=nums.size();
	    int temp[n];
	    for(int i=0;i<n;i++)
	    {
	        temp[i]=1;
	    }
	    
	    v1.push_back(temp[0]);
	    for(int i=1;i<n;i++)
	    {
	        for(int j=i-1;j>=0;j--)
	        {
	            if(nums[i]>nums[j])
	            temp[i]=max(temp[i],1+temp[j]);
	        }
	        v1.push_back(temp[i]);
	    }
	}

    int LongestBitonicSequence(int n, vector<int> &nums) {
	   vector<int>v1;
	   vector<int>v2;
	   helper(nums,v1);
	 
	   reverse(nums.begin(),nums.end());
	   helper(nums,v2);
	   reverse(v2.begin(),v2.end());
	   int ans=0;
	   for(int i=0;i<n;i++)
	   {
	       if(v1[i]>1 and v2[i]>1)
	       ans=max(ans,v1[i]+v2[i]-1);
	   }
	   return ans;
    }