Solution 1:


Time->O(2^n*n)
Code:
bool isPalindrome(string str)
{
        string str1=str;
        reverse(str.begin(),str.end());
        return (str1==str);
}
int helper(string s,int index,int n)
{
        if(index==n) return 0;
        int minCuts=INT_MAX;

        string str="";
        int cuts=0;
        for(int i=index;i<n;i++)
        {
            str+=s[i];
            if(isPalindrome(str))
            cuts=1+helper(s,i+1,n);

            minCuts=min(minCuts,cuts);
        }
        return minCuts;
}
int minCut(string s) {
        int n=s.length();
        int res=helper(s,0,n);
        return res-1;
}





Solution 2:

Steps-:
1)Using memo 


Code-:
bool isPalindrome(string s,int i,int j)
{
        while(i<j)
        {
            if(s[i]!=s[j]) return false;
            else
            {
                i++;
                j--;
            }
        }
        return true;
}
int helper(vector<int>&memo,string &s,int index,int n)
{
        if(index==n) return 0;
        if(memo[index]!=-1) return memo[index];

        int minCuts=INT_MAX;
      
        int cuts=0;
        for(int i=index;i<n;i++)
        {
            if(isPalindrome(s,index,i))
            cuts=1+helper(memo,s,i+1,n);

            minCuts=min(minCuts,cuts);
        }
        return memo[index]=minCuts;
}
int minCut(string s) {
        int n=s.length();
        vector<int>memo(n+1,-1);
        int res=helper(memo,s,0,n);
        return res-1;
}





Solution 3:  Time ->O(N^3)

Steps:
1)All steps are same instead we are checking at every range of s(index,i) is this palindrome which makes complexity O(N^3)


bool isPalindrome(string s,int i,int j)
{
    while(i<j)
    {
        if(s[i]!=s[j]) return false;
        else
        {
            i++;
            j--;
        }
    }
    return true;
}
    
int minCut(string s) 
{
    int n=s.length();
    vector<int>memo(n+1,-1);
    // int res=helper(memo,s,0,n);
    // return res-1;
    memo[n]=0;

    for(int i=n-1;i>=0;i--)
    {
        int minCuts=INT_MAX;
        int cuts=0;
        for(int j=i;j<n;j++)
        {
        if(isPalindrome(s,i,j))
        cuts=1+memo[j+1];

        minCuts=min(minCuts,cuts);
        }
        memo[i]=minCuts;
    }
    return memo[0]-1;
}
  


Solution 4: 

Steps: 
1)Instead we are checking isPalidrome for every range of s (index,i) 
  we are precomputing all the range like which is palindrome or not. 



Code: 
Time ->O(N^2) 
Space ->O(N^2)
void fillPalindrome(vector<vector<bool>>&isPalindrome,string &s,int n)
{
    for(int i=0;i<n;i++)
    {
        isPalindrome[i][i]=true;
    }

    for(int i=n-2;i>=0;i--)
    {
        for(int j=i+1;j<n;j++)
        {
            if(s[i]==s[j])
            {
                if(j-i==1 || isPalindrome[i+1][j-1]==1)
                isPalindrome[i][j]=true;
                else
                isPalindrome[i][j]=false;
            }
            else
            isPalindrome[i][j]=0;
        }
    }
}
   
int minCut(string s) 
{
    int n=s.length();
    vector<int>memo(n+1,-1);
    memo[n]=0;

    vector<vector<bool>>isPalindrome(n,vector<bool>(n,false));
    fillPalindrome(isPalindrome,s,n);


    for(int i=n-1;i>=0;i--)
    {
        int minCuts=INT_MAX;
        int cuts=0;
        for(int j=i;j<n;j++)
        {
            if(isPalindrome[i][j]==true)
            {
                cuts=1+memo[j+1];
                minCuts=min(minCuts,cuts);
            }
        }
        memo[i]=minCuts;
    }
    return memo[0]-1;
}