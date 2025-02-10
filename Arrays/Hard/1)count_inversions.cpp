Solution 1-:

Code-:
int inversionCount(vector<int> &arr) {
        int n=arr.size();
        int count=0;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(arr[i]>arr[j])
                count++;
            }
        }
        return count;
}


Solution 2-:
Steps-:
1)using merge sort.
2) count+= left_side 
   count+= right_side.
   count+= merge();

   means   0 1 2 3 4
   arr -> [2,4,1,3,5]

    low=0,high=4 , mid=2.

   count=0;
1. count+=mergeSort(arr,low,mid)    -> means f(0,2) 
2. count+=mergeSort(arr,mid+1,high) -> means f(3,4)
3. count+=merge(arr,low,mid,high)   -> means f(0,2,4)



Time->O(Nlog(N))
Space->O(N)
Code-:
int merge(vector<int>&arr,int low,int mid,int high)
{
        int n1=mid-low+1;
        int n2=high-mid;
        int left[n1];
        int right[n2];
        
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
            if(left[i]>right[j])
            {
                count+=(n1-i);
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
        return count;
}
int mergeSort(vector<int>&arr,int low,int high)
{
        int count=0;
        if(low<high)
        {
            int mid=(low+high)/2;
            count+=mergeSort(arr,low,mid);
            count+=mergeSort(arr,mid+1,high);
            count+=merge(arr,low,mid,high);
        }
        return count;
}
int inversionCount(vector<int> &arr) {
        int n=arr.size();
        return mergeSort(arr,0,n-1);
}