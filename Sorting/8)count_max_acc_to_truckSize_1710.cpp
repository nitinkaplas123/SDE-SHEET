Solution 1:

Steps:
1)Sort acc to unitsPerBoxes to get the max no. of boxes.


Time Complexity: O(nlog(n))
Space Complexity: O(1)
Code:
static bool comp(vector<int>&a,vector<int>&b)
{
        return (a[1]>b[1]);
}
int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        int n=boxTypes.size();
        sort(boxTypes.begin(),boxTypes.end(),comp);

        int ans=0;
        for(int i=0;i<n;i++)
        {
            int numBoxes=boxTypes[i][0];
            int unitsPerBoxes=boxTypes[i][1];
            if(boxTypes[i][0]<=truckSize)
            {
               ans+=(numBoxes*unitsPerBoxes);
               truckSize-=numBoxes;
            }
            else 
            {
                ans+=truckSize*unitsPerBoxes;
                break;
            }
        }
        return ans;
}