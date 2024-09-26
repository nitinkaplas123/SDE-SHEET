https://www.geeksforgeeks.org/problems/minimum-number-of-deletions-to-make-a-sorted-sequence3248/0


Steps-:
1)Find the lis.
2)return n-lis;

Code-:  Time->O(Nlog(N)) Space->O(1)
void helper(vector<int>&v,int val)
{
        int n=v.size();
        int low=0;
        int high=n-1;
        int index;
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(v[mid]<val)
            low=mid+1;
            else
            {
                index=mid;
                high=mid-1;
            }
        }
        v[index]=val;
}

int lengthOfLIS(int nums[],int n) {
       
        vector<int>v;
        v.push_back(nums[0]);

        for(int i=1;i<n;i++)
        {
            if(nums[i]>v.back())
            v.push_back(nums[i]);
            else
            helper(v,nums[i]);
        }
        return v.size();
}

int minDeletions(int arr[], int n) 
{ 
	    int lis=lengthOfLIS(arr,n);
	    return n-lis;
} 