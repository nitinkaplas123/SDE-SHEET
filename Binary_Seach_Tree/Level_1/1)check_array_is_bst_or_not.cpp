https://www.geeksforgeeks.org/problems/binary-search-trees/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=binary-search-trees


Code-:
bool isBSTTraversal(vector<int>& arr) {
       int n=arr.size();
       for(int i=1;i<n;i++)
       {
           if(arr[i]<=arr[i-1])
           return false;
       }
       return true;
}