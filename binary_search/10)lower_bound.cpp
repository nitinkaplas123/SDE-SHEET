Lower bound is the first occurrence of target element. If element not found index of first element greater than target is returned.

Upper bound is the first occurence of element greater than target element.

More codes: https://github.com/Kanav-Arora/DSA-Cpp

C++ implementation using binary search:

Lower Bound

int lower_bound(vector<int> nums, int target)
{
    int start = 0;
    int end = nums.size()-1;
    int mid = 0;
    while(start<end)
    {
        mid = start  + (end-start)/2;
        if(nums[mid]<target)    start = mid+1;
        else   end = mid;
    }
    return start;
}
Input:
[1,2,3,4,6,6,8,11]
6

Output:
4

Upper Bound

int upper_bound(vector<int> nums, int target)
{
    int start = 0;
    int end = nums.size()-1;
    int mid = 0;
    while(start<end)
    {
        mid = start  + (end-start)/2;
        if(nums[mid]<=target)    start = mid+1;
        else   end = mid;
    }
    return start;
}

Input:
[1,2,3,4,6,6,8,11]
6

Output:
6





Solution 1-:
Problem Statement

Sample Input 1:
6
1 2 2 3 3 5
0

Sample Output 1:
0


Explanation Of Sample Input 1 :
Index '0' is the smallest index such that 'arr[0]' is not less than 'x'.


Sample Input 2:
6
1 2 2 3 3 5
2


Sample Output 2:
1


Sample Input 3:
6
1 2 2 3 3 5
7


Sample Output 3:
6


Expected Time Complexity:
Try to do this in O(log(n)).

Solution 1-:
Steps-:
1)Using inbuilt function 

Code-:
int lowerBound(vector<int> arr, int n, int x) {
	return lower_bound(arr.begin(),arr.end(),x)-arr.begin();
}


Solution 2-:

Code-:
int lowerBound(vector<int> arr, int n, int x) {
	int ans=0;
	int low=0;
	int high=n-1;

	while(low<=high)
	{
		int mid=(low+high)/2;
		if(arr[mid]==x)
		{
			ans=mid;
            high=mid-1;
		}
		else if(arr[mid]>x)
		high=mid-1;
		else
		{
			ans=mid+1;
			low=mid+1;
		}
		
	}
	return ans;
}