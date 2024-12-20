Question link-:
https://www.geeksforgeeks.org/find-position-element-sorted-array-infinite-numbers/

Solution 1-:
Steps-:
1)As we know its sorted array so we traverse from starting and there is two cases-:
  1. If we find the element then return its index.
  2. If the current element is greater than given element then it means the search element is not present.


Code-: Time->O(pos)  position where we have the search element
int find_elemet(vector<int>nums,int x)
{
    int i=0;
    while(1)
    {
        if(nums[i]==x)
        return i;
        if(nums[i]>x)
        return -1;
        
        i++;
    }
    return 1;
}


Solution 2-:
Steps-:
1)Here low=0 high=1  here we check the 0th position explicity because we have to double the high so if high=0
  and we double it then it should be same.  2*0 =>0

2)Here low and high is the position in bw our search element is prsent.
3)Three cases-:
  1. If arr[high]<x
     then it means at pos high the element is  smaller so we do
     low=high
     high=2*high
  2. If arr[high]==x
     then return high
  3. this means our search element is in middle of low and high position.


Code-:
#include <bits/stdc++.h>
using namespace std;

int binarySearch(vector<int>arr,int low,int high,int x)
{

    while(low<=high)
    {
        int mid=(low+high)/2;
        if(arr[mid]==x)
        return mid;
        else if(arr[mid]<x)
        low=mid+1;
        else
        high=mid-1;
    }
    return -1;
}
int helper(vector<int>v,int x)
{
    // 0th position case
    if(v[0]==x) return 0;
    
    int low=0;
    int high=1;
    // make high and low in bw of search element
    while(v[high]<x)
    {
        low=high;
        high=2*high;
    }
    
    // if v[high]==x
    if(v[high]==x)  return high;
    
    return binarySearch(v,low+1,high-1,x);
}
int main()
{
	vector<int>v{1,10,15,20,40,60,80,100,200,500,1000};
	int x=20;
	cout<<helper(v,x);
}

