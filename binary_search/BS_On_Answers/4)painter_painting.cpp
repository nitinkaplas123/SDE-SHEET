https://www.naukri.com/code360/problems/painter-s-partition-problem_1089557?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTabValue=SUBMISSION

Solution 1-:
Steps:
1)Same as previous.

Time->O(Nlog(sum-maxxVal))
Space=>O(1)
Code:
bool isValid(vector<int>&board,int k,int mid)
{
    int count=1;
    int val=board[0];
    for(int i=1;i<board.size();i++)
    {
        val+=board[i];
        if(val>mid)
        {
            count++;
            val=board[i];
        }
    }
    return (count<=k);
}
int findLargestMinDistance(vector<int> &boards, int k)
{
    int n=boards.size();
    int maxxVal=boards[0];
    int sum=boards[0];
    for(int i=1;i<n;i++)
    {
        maxxVal=max(maxxVal,boards[i]);
        sum+=boards[i];
    }

    int low=maxxVal;
    int high=sum;
    int ans=-1;
    while(low<=high)
    {
        int mid=(low+high)/2;
        if(isValid(boards,k,mid))
        {
            ans=mid;
            high=mid-1;
        }
        else
        low=mid+1;
    }
    return ans;
}