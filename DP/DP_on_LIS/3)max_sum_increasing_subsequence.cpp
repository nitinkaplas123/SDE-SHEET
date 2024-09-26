https://www.geeksforgeeks.org/problems/maximum-sum-increasing-subsequence4749/1

Solution 1-:
Idea-:
1)same as return the length of lis.


Steps-:
1)firstly we make a temp array which is equal to original array.
2)now we run a two loop i and j 
  where i is the pointer where j is from 0 
  we make a update 



int maxSumIS(int arr[], int n)  
{  
	    int temp[n];
	    for(int i=0;i<n;i++)
	    {
	        temp[i]=arr[i];
	    }
	    
	    int ans=0;
	    for(int i=0;i<n;i++)
	    {
	        for(int j=0;j<i;j++)
	        {
	            if(arr[i]>arr[j])
	            temp[i]=max(temp[i],arr[i]+temp[j]);
	        }
	        ans=max(ans,temp[i]);
	    }
	    return ans;
}  


or 


int maxSumIS(int arr[], int n)  
{  
	    int temp[n];
	    for(int i=0;i<n;i++)
	    {
	        temp[i]=arr[i];
	    }
	    
	    int ans=arr[0];
	    for(int i=0;i<n;i++)
	    {
	        for(int j=i+1;j<n;j++)
	        {
	            if(arr[j]>arr[i])
	            temp[j]=max(temp[j],arr[j]+temp[i]);
	            ans=max(ans,temp[j]);
	        }
	    }
	    return ans;
}  