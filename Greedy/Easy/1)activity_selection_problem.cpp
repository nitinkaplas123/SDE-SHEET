https://www.geeksforgeeks.org/problems/activity-selection-1587115620/1

Steps-:
1)Sort the array according to end time of meeting.
  why end ?
  because start_time<end_time.
  so i need the smallest end time to starting the meeting or 
  starting the counting part.


 start=> 7 6 2 7 3
 end =>  10 6 10 9 5

 start time o/p -> 1 
 end time o/p   -> 3


Code-: Time->O(Nlog(N)) Space->O(N)
static bool comp(pair<int,int>&a,pair<int,int>&b)
{
        return (a.second<b.second);
}

int activitySelection(vector<int> start, vector<int> end, int n)
{
        vector<pair<int,int>>v;
        for(int i=0;i<n;i++)
        {
            v.push_back({start[i],end[i]});
        }
        
        sort(v.begin(),v.end(),comp);
        
        int end_time=v[0].second;
        int count=1;
        for(int i=1;i<n;i++)
        {
            if(end_time<v[i].first)
            {
                count++;
                end_time=v[i].second;
            }
        }
        return count;
}