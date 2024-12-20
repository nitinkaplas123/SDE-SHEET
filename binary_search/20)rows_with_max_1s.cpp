Question -:https://practice.geeksforgeeks.org/problems/row-with-max-1s0023/1

Solution 1-:
Steps-:
1)As we know rows are in sorted order we can use lower and upper bound.

Test case-:
{0, 1, 1, 1},   lower=1     upper=4   total no. of 1s=> 4-1=>3 
{0, 0, 1, 1},   lower=2     upper=4   total no. of 1s=> 4-2=>2
{1, 1, 1, 1},   lower=0     upper=4   total no. of 1s=> 4-0=>4
{0, 0, 0, 0}}   lower=4     upper=4   total no. of 1s=> 4-4=>0


 
Code-: Time->O(nlogn)
	int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
	    int ans=0;
	    int index=-1;
	    for(int i=0;i<n;i++)
	    {
	       int val1=upper_bound(arr[i].begin(),arr[i].end(),1)-arr[i].begin();
	       int val2=lower_bound(arr[i].begin(),arr[i].end(),1)-arr[i].begin();
	       int res=val1-val2;
	       if(ans<res)
	       {
	           ans=res;
	           index=i;
	       }
	    }
	    return index;
	}





Solution 2-:
Steps-:
1)Start from top right.


Code-: Time->O(N+M)
int rowWithMax1s(vector<vector<int>> &arr) 
{
        int n=arr.size();
        int m=arr[0].size();
        int i=0;
        int j=m-1;
        int index=0;
        while(i<n and j>=0)
        {
            if(arr[i][j]==1)
            {
                index=i;
                j--;
            }
            else
            i++;
        }
        return index;
}