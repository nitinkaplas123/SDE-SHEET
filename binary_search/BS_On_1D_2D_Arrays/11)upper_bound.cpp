Solution 1-:
Steps-:
1)Using inbuilt function 

Code-:
int upperBound(vector<int> &arr, int x, int n){
	return upper_bound(arr.begin(),arr.end(),x)-arr.begin();	
}


Solution 2-:
Steps-:
1)Using binary search
2)If arr[mid]<=target
  means our ans=mid+1 
            low=mid+1;
3)If arr[mid]>target
  ans=mid.
  high=mid-1;




Code-:
int upperBound(vector<int> &arr, int x, int n){
	int low=0;
	int high=n-1;
    
	int ans=0;
	while(low<=high)
	{
		int mid=(low+high)/2;
		if(arr[mid]<=x)
		{
           ans=mid+1;
		   low=mid+1;
		}
		else if(arr[mid]>x)
		{
			ans=mid;
			high=mid-1;
		}
	}
	return ans;
}