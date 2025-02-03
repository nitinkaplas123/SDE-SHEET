Solution 1-:
Steps-:
0)same as max chain length.
1)Find the max no. of cells with non-overlapping.
2)n-maxx is the min no. of cells to delete to make list non-overlapping.


Time->O(Nlog(n))
Code-:
static bool comp(vector<int>&a,vector<int>&b)
{
        return a[1]<b[1];
}
int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n=intervals.size();
        sort(intervals.begin(),intervals.end(),comp);

        int count=1;
        int prev=intervals[0][1];
        for(int i=1;i<n;i++)
        {
             if(intervals[i][0]>=prev)
             {
                count++;
                prev=intervals[i][1];
             }
        }
        return (n-count);
}