Solution 1-:
Steps-:
1)push the newInterval into list of intervals.
2)Sort the intervals list.
3)Now using merge overlap question we can do the same things here.


Time->O(Nlog(N))
Space->O(1)
Code-:
vector<vector<int>> insert(vector<vector<int>>& intervals,vector<int>& newInterval) {
        intervals.push_back(newInterval);

        sort(intervals.begin(),intervals.end());
        vector<vector<int>>v;
        int n=intervals.size();

        v.push_back(intervals[0]);
        for(int i=1;i<n;i++)
        {
            if(intervals[i][0]<=v.back()[1] and v.back()[1]<=intervals[i][1])
            v.back()[1]=intervals[i][1];
            else if(intervals[i][0]>v.back()[1])
            v.push_back(intervals[i]);
            else
            continue;
        }
        return v;
}


Solution 2-:
Steps-:

Case1 -:
intervals-> [[1,3]]         newInterval-> [4,6] 

1->3    and 4->6 
if(intervals[i][1]<newIntervals[0])
which means 
add 1->3 in list.

[1,3]


Case2 -: 
intervals-> [[1,3],[10,15]]         newInterval-> [4,6] 

10->15       4->6 
here we break the loop where i=1

1)push newIntervals 
2)then traverse over the pending loop.

[1,3],[4,6],[10,15]


Case3 -:
intervals-> [[1,3],[6,9]]         newInterval-> [4,6] 

6->9        4->6
which means there is overlapping.
so update newIntervals[0] =min(intervals[i][0],newInterval[0])
          newIntervals[1]= max(intervals[i][1],newInterval[1])

continue the loop.



Code-:
vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>>ans;
        int n=intervals.size();

        int i=0;
        while(i<n)
        {
            if(intervals[i][1]<newInterval[0])
            ans.push_back(intervals[i]);
            else if(intervals[i][0]>newInterval[1])
            break;
            else
            {
                newInterval[0]=min(newInterval[0],intervals[i][0]);
                newInterval[1]=max(newInterval[1],intervals[i][1]);
            }
            i++;
        }

        
        ans.push_back(newInterval);
        while(i<n)
        {
            ans.push_back(intervals[i++]);
        }
        return ans;
}