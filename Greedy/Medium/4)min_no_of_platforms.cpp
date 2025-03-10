https://www.geeksforgeeks.org/problems/minimum-platforms-1587115620/1

Solution 1-:
Steps-:
1)We have to calculate min no. of platforms needed from arrival and depature of all the trains.
2)Idea is sorted both the arrays.
  why ?
Just focus on timestamp. 
when any trains comes give the platform-> count++;
and when any trains depature free the platform -> count--

for eg. 
arr -> [900,945,955,1100,1500,1800]
dep -> [920,1130,1150,1200,1900,200]
Just focus on timestamp. 
1)Here at 900 train come to platform -> no. of platform used        -> 1 
2)after a 920 trains depature from platform -> no. of platform used -> 0
3) similariyly steps goes...
4) we have to take the max count at every time -> maxx=max(maxx,count);
5) return maxx.


Question -: No two trains used same platform when somebody arrive and at same time somebody came. (arr[i])==dep[j]
At any given time, the same platform cannot be used for both the arrival of one train and the departure of another. 
Therefore, when two trains arrive at the same time, or when one arrives before another departs, 
additional platforms are required to accommodate both trains.

Solution -:
if(arr[i]<=dep[j])
{
    count++;
    i++;
}

-> thats why we are increment the count -> to used new platform when both are equal.


Time->O(Nlog(N))
Space ->O(1)
Code-:
int findPlatform(vector<int>& arr, vector<int>& dep) {
        int n=arr.size();
        sort(arr.begin(),arr.end());
        sort(dep.begin(),dep.end());
        
        int count=0;
        int i=0;
        int j=0;
        int maxx=0;
        while(i<n and j<n)
        {
            if(arr[i]<=dep[j])
            {
                count++;
                i++;
            }
            else
            {
                count--;
                j++;
            }
            maxx=max(maxx,count);
        }
        return maxx;
}



Solution 2-:


arr[i] ->       900      1000


arr[j] ->  800                 1100

if(arr[i]>=arr[j] and dep[j]>=arr[i])
temp++;


Code-:
 int findPlatform(vector<int>& arr, vector<int>& dep) {
       // plat_needed indicates number of platforms
       // needed at a time
       int n=arr.size();
       int ans = 1;
    
       // Run a nested for-loop to find the overlap
       for (int i = 0; i < n; i++) {
    
           // Initially one platform is needed
           int temp = 1;
           for (int j = 0; j < n; j++) {
               if (i != j)
                   // Increment plat_needed when there is an
                   // overlap
                   if (arr[i] >= arr[j] && dep[j] >= arr[i])
                       temp++;
           }
    
           // Update the result
           ans = max(temp, ans);
       }
       return ans;
    }