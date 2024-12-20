pair<int, int> getFloorAndCeil(vector<int> &a, int n, int x) {
	//floor
	int low=0;
	int high=n-1;
	int ans1=-1;
	while(low<=high)
	{
		int mid=(low+high)/2;
		if(a[mid]==x)
		{
			ans1=a[mid];
			break;
		}
		else if(a[mid]<x)
		{
          ans1=a[mid];
		  low=mid+1;
		}
		else
		high=mid-1;
	}
    
    //ceil
	low=0;
	high=n-1;
	int ans2=-1;
	while(low<=high)
	{
		int mid=(low+high)/2;
		if(a[mid]==x)
		{
			ans2=a[mid];
			break;
		}
		else if(a[mid]<x)
		low=mid+1;
		else
		{
			ans2=a[mid];
			high=mid-1;
		}
	}
	return {ans1,ans2};
	
}