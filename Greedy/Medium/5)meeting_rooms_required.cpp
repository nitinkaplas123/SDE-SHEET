https://www.geeksforgeeks.org/problems/attend-all-meetings-ii/1

Solution 1-:
Steps-:
1)using same idea as previous question.
2)here when any starting time of meeting = any ending time of meeting.
  here we can use the same room. 

  So thats why -:
   if(arr[i]<dep[j])
   {
                count++;
                i++;
   }
when total equal we go to else case -> here we are not making the new meeting room for the same.



Time->O(Nlog(n))
Code-:
int minMeetingRooms(vector<int> &arr, vector<int> &dep) {
        int n=arr.size();
        sort(arr.begin(),arr.end());
        sort(dep.begin(),dep.end());
        
        int count=0;
        int i=0;
        int j=0;
        int maxx=0;
        while(i<n and j<n)
        {
            if(arr[i]<dep[j])
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