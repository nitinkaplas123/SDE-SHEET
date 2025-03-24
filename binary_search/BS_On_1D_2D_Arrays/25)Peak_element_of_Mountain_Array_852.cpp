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

class Solution {
public:
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
};