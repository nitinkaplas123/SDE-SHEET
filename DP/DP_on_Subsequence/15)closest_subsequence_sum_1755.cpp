Solution 1-:
Steps-:
1)Generate all subset. 
2)When we generate a subset then we take abs diff then update ans accordingly.


Time->O(2*n)
Space ->O(N)
Code-:
void helper(vector<int>& nums,int index,int n,int sum,int goal,int &ans)
{
        if(index==n)
        {
            int diff=abs(sum-goal);
            ans=min(ans,diff);
            return ;
        }
        helper(nums,index+1,n,sum,goal,ans);
        sum+=nums[index];
        helper(nums,index+1,n,sum,goal,ans);
}
int minAbsDifference(vector<int>& nums, int goal) {
        int n=nums.size();
        int ans=INT_MAX;
        int sum=0;
        helper(nums,0,n,sum,goal,ans);
        return ans;
}



Solution 2-:

Code-:
class Solution {
public:
    void helper1(vector<int>&nums,vector<int>&left,vector<int>&right)
    {
        int n=nums.size();
        if(n%2!=0)
        {
           int i;
           for(i=0;i<=n/2;i++){
            left.push_back(nums[i]);
           }

           for(int j=i;j<n;j++){
            right.push_back(nums[j]);
           }
        }
        else{
           int i;
           for(i=0;i<n/2;i++){
            left.push_back(nums[i]);
           }

           for(int j=i;j<n;j++){
            right.push_back(nums[j]);
           }
        }

       
    }

    void helper2(vector<int>&left,int index,int n,int sum,vector<int>&first)
    {
        if(index==n)
        {
            first.push_back(sum);
            return ;
        }
        helper2(left,index+1,n,sum,first);
        sum+=left[index];
        helper2(left,index+1,n,sum,first);
    }
    int minAbsDifference(vector<int>& nums, int goal) {
        int n=nums.size();
        vector<int>left,right;
        helper1(nums,left,right);
        
        vector<int>first,second;
        int sum=0;
        helper2(left,0,left.size(),sum,first);
        helper2(right,0,right.size(),sum,second);

        
        sort(second.begin(),second.end());

        int n1=first.size();
        int n2=second.size();

       

        int res=INT_MAX;
        for(int i=0;i<n1;i++){
            int x=first[i];
            int diff=(goal-x);
            int index=lower_bound(second.begin(),second.end(),diff)-second.begin();
           
             if(index>0)
                res=min(res,abs(goal-second[index-1]-x));
            if(index<second.size())
                res=min(res,abs(goal-second[index]-x));
        }
        return res;
    }
};