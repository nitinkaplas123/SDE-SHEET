Solution 1:


heaters = [1,4]
houses = [1,2,3,4]

1            4
 
1)house1 -> 1
  for house1 -> 1 whose the heater u want 
  left_closest->1 
  right_cloest->4

  for house1 -> abs(1-1)=0
             -> abs(1-4)=3

  so house1 -> 0 

2) house2->2

1           4

for house2 -> 2 whose the heater u want 
  left_closest->1 
  right_cloest->4

  -> abs(1-2)=1
  -> abs(4-2)=2

   so house2 -> 1 


3) house3->3

1           4

for house3 -> 3 whose the heater u want 
  left_closest->1 
  right_cloest->4

  -> abs(1-3)=2
  -> abs(4-3)=1

   so house3 -> 1 

4) house4->4

1           4

for house4 -> 4 whose the heater u want 
  left_closest->1 
  right_cloest->4

  -> abs(1-4)=3
  -> abs(4-4)=0

   so house4 ->0

Take all the houses radius-> {0,1,1,0}
take max from all.

Output is 1.






Time Complexity: O(N^2)
Space Complexity: O(1)
Code:
int findRadius(vector<int>& houses, vector<int>& heaters) {
        int n1=houses.size();
        int n2=heaters.size();
        
        int minRadius=INT_MIN;
        for(int i=0;i<n1;i++)
        {
           int minDist=INT_MAX;
           for(int j=0;j<n2;j++)
           {
              minDist=min(minDist,abs(houses[i]-heaters[j]));
           }
           minRadius=max(minRadius,minDist);
        }
        return minRadius;
}


Solution 2:

heaters[] = [1,4]

houses[] =  {1,2,3}



Steps:
1) for house1 -> find the left side clearest heaters.
              -> find the right side clearest heaters.
   choose the one whose abs distance bw both one is less.

   store the values.

2) do same for all.

  take max of all 

  return maxx.

Time Complexity: O(N1*(log(n2)+log(n2)))
Space Complexity:O(1)

Code:

int ceilOfVal(vector<int>&heaters,int val)
{
        int n=heaters.size();
        int low=0;
        int high=n-1;
        int ans=heaters[0];
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(heaters[mid]==val)
            return val;
            else if(heaters[mid]>val)
            {
                ans=heaters[mid];
                high=mid-1;
            }
            else
            low=mid+1;
        }
        return ans;
}
int floorOfVal(vector<int>&heaters,int val)
{
        int n=heaters.size();
        int low=0;
        int high=n-1;
        int ans=heaters[0];
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(heaters[mid]==val)
            return val;
            else if(heaters[mid]<val)
            {
                ans=heaters[mid];
                low=mid+1;
            }
            else
            high=mid-1;
        }
        return ans;
}
int helper(vector<int>&heaters,int val)
{
        int n = heaters.size();
        int right=ceilOfVal(heaters,val);
        int left=floorOfVal(heaters,val);
        
        int diffLeft=abs(left-val);
        int diffRight=abs(right-val);
        return min(diffLeft,diffRight);
}
int findRadius(vector<int>& houses, vector<int>& heaters) {
        int n1=houses.size();
        int n2=heaters.size();
        sort(heaters.begin(),heaters.end());
        
        int ans=INT_MIN;
        for(int i=0;i<n1;i++)
        {
            int val=helper(heaters,houses[i]);
            ans=max(ans,val);
        }
        return ans;
}



Solution 3:

Steps:
1)using lower_bound.
2)lower_bound gives the iteartor to the value if the target is present else just greater
  than the target.

Time Complexity -:O(N1*log(N2))
Space ->O(1)
Code:
int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(heaters.begin(), heaters.end());

        int maxDist = 0;
        for (int house : houses) {
            // Use lower_bound to find the first heater not less than house
            auto rightIt = lower_bound(heaters.begin(), heaters.end(), house);

            int distRight = (rightIt != heaters.end()) ? abs(*rightIt - house) : INT_MAX;
            int distLeft = (rightIt != heaters.begin()) ? abs(*(rightIt - 1) - house) : INT_MAX;

            int nearest = min(distLeft, distRight);
            maxDist = max(maxDist, nearest);
        }
        return maxDist;
}