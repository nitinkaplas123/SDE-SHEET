Solution 1:

Steps-:


Code: Time->O(N)  Space->O(1)
int peakIndexInMountainArray(vector<int>& arr) {
        int n=arr.size();
        int maxx=arr[0];
        int index=0;
        for(int i=1;i<n;i++)
        {
            if(arr[i]>maxx)
            {
                maxx=arr[i];
                index=i;
            }
        }
        return index;
}



Solution 2:

Steps:
1)Mountain element is element which is greater than its left element and greater then its right element.

Code:

int peakIndexInMountainArray(vector<int>& arr) {
        int n=arr.size();
        int low=0;
        int high=n-1;

        while(low<=high)
        {
            int mid=(low+high)/2;
            if((mid==0 || arr[mid]>arr[mid-1]) && (mid==n-1 || arr[mid]>arr[mid+1]))
            return mid;
            else if(mid!=0 and arr[mid]<arr[mid-1])
            high=mid-1;
            else
            low=mid+1;
        }
        return -1;
}


Solution 3:

Steps:

Code:
int peakIndexInMountainArray(vector<int>& arr) {
        int n=arr.size();
        int low=0;
        int high=n-1;

        while(low<high)
        {
            int mid=(low+high)/2;
            if(arr[mid]<arr[mid+1])
            low=mid+1;
            else
            high=mid;
            
        }
        return low;
}