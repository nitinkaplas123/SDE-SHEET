Solution 1-:
Steps-:
1)using 2 for loop.

Time->O(N^2)
Space->O(1)

Code-:
int reversePairs(vector<int>& nums) {
        int n=nums.size();
        int count=0;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(nums[i]>(long long)2*nums[j])
                count++;
            }
        }
        return count;
}



Solution 2-:
Steps-:
1)Here we can compare the question of count inversion its also same as that.
2)difference is count inversion -> nums[i]>nums[j].     -> Here merge function will sort the subarray and count the inversion.
  Here -:
  nums[i]>(2*nums[j])

3)Due to this we cannot do both task in a single merge function -> its not working -> u can check as well.
Solution -:
1) MergeSort(low,mid).
2) MergeSort(mid+1,high).
3) countPairs(arr,low,mid,high). -> count the inversions.
4) now merge(arr,low,mid,high) -> means sort the subarrays whos count is already added.


CountPairs Code-:

int countPairs(vector<int>& arr, int low, int mid, int high) 
{
       int right=mid+1;
       int count=0;
       for(int i=low;i<=mid;i++)
       {
           while(right<=high and arr[i]>(long long) 2*arr[right])
           {
              right++;
           }
           count+=(right-(mid+1));
       }
       return count;
}

 0 1 2 
[3,4,1]

low=0 
mid=1
high=2
         3 4                5  
left -> [3,4]     right -> [1]




1. run a loop from i=low;i<=high -> which is for left array.
   i=3

   right=5 
   right=6 
   its stops here 

   count+=(where right stops - from where its start)
   count+=(right-(mid+1));

   count=0+(6-(5))
   count=1.

2. i=4 
   right=6 

   so while loop donot run 

   count+=(6-(5))
   count=1+(1)
   count=2.



Time->O(Nlog(n))
Space->O(N)
Code-:
void merge(vector<int>&arr,int low,int mid,int high)
{
        int n1=mid-low+1;
        int n2=high-mid;
        vector<int>left(n1);
        vector<int>right(n2);
        
        for(int i=0;i<n1;i++)
        {
            left[i]=arr[low+i];
        }
        for(int i=0;i<n2;i++)
        {
            right[i]=arr[mid+1+i];
        }
        
        int k=low;
        int i=0;
        int j=0;
        int count=0;
        while(i<n1 and j<n2)
        {
            if(left[i]>=right[j])
            {
                arr[k++]=right[j++];
            }
            else
            arr[k++]=left[i++];
        }
        
        while(i<n1)
        {
            arr[k++]=left[i++];
        }
        
        while(j<n2)
        {
            arr[k++]=right[j++];
        }
       
}   
int countPairs(vector<int>& arr, int low, int mid, int high) 
{
       int right=mid+1;
       int count=0;
       for(int i=low;i<=mid;i++)
       {
           while(right<=high and arr[i]>(long long) 2*arr[right])
           {
              right++;
           }
           count+=(right-(mid+1));
       }
       return count;
}
int mergeSort(vector<int>&nums,int low,int high)
{
        int count=0;
        if(low<high)
        {
            int mid=(low+high)/2;
            count+=mergeSort(nums,low,mid);
            count+=mergeSort(nums,mid+1,high);
            count+=countPairs(nums,low,mid,high);
            merge(nums,low,mid,high);
        }
        return count;
}
int reversePairs(vector<int>& nums) {
        int low=0;
        int high=nums.size()-1;
        return mergeSort(nums,low,high);
}