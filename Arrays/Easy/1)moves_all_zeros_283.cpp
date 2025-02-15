Code-:
void moveZeroes(vector<int>&arr) {
        int n=arr.size();
        int index=-1;
        for(int i=0;i<n;i++)
        {
            if(arr[i]!=0)
            {
                index++;
                swap(arr[i],arr[index]);
            }
        }
}