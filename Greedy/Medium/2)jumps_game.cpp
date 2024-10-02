https://www.geeksforgeeks.org/problems/minimum-number-of-jumps-1587115620/1

int minJumps(vector<int>& arr) {
       int n=arr.size();
       if(arr[0]==0) return -1;
       int jumps=1;
       int steps=arr[0];
       int max_reach=arr[0];
       
       for(int i=1;i<n-1;i++)
       {
           max_reach=max(max_reach,i+arr[i]);
           if(max_reach==i) return -1;
           
           steps--;
           if(steps==0)
           {
               jumps++;
               steps=max_reach-i;
           }
       }
       return jumps;
    }