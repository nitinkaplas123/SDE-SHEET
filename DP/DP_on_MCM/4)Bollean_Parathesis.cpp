https://www.geeksforgeeks.org/problems/boolean-parenthesization5610/1

Solution 1:
Steps:
1) i=0 j=n-1 (where we have to traverse).
2) partition on &,|,^ which is start from k=i+1 till k=j-1 and have 2 gap bw so k+=2.
3) Now we have to count the total possbile ways when expression is true.
4) We partition the string using k at k position we separate in two ways 
   left and right 
   
   f(i,j)
   left=f(i,k-1) 
   right=f(k+1,j)

Now we have to calculate left_true, left_false , right_true , right_false.
for that we pass isTrue in f function.

f(s,i,j,isTrue)
{
           int LT=helper(s,i,k-1,1);
           int LF=helper(s,i,k-1,0);
           int RT=helper(s,k+1,j,1);
           int RF=helper(s,k+1,j,0);
}


// when bw left and right we have ^
if(s[k]=='^')
{
    if(isTrue==1)            // if u want isTrue=1
    count+= LT*RF + LF*RT;
    else
    count+=LT*RT + LF*RF;    // isTrue=0
}


// bw left and right we have & 
else if(s[k]=='&')
{
    if(isTrue==1)
    count+= LT*RT;
    else 
    count+=LT*RF + LF*RT + LF*RF;
}



// between left and right we have | 
else
{
    if(isTrue==1)
    count+= LT*RT + LT*RF + LF*RT;
    else
    count+= LF*RF;
}



// Base case 1
// if(i>j) cross each other 
return 0


//Base case 2 
if(i==j)
{
    if(isTrue==1) return (s[i]=='T')    // means we u want isTrue=1 then check if (s[i]=='T) return 1 else return 0.
    else 
    return (s[i]=='F')    // means we u want isTrue=0 then check if (s[i]=='F) return 1 else return 0.
}



int helper(string &s,int i,int j,int isTrue)
{
       if(i>j) return 0;
       if(i==j)
       {
           if(isTrue==1) 
           return (s[i]=='T');
           else
           return (s[i]=='F');
       }
       
       int count=0;
       for(int k=i+1;k<=j-1;k+=2)
       {
           int LT=helper(s,i,k-1,1);
           int LF=helper(s,i,k-1,0);
           int RT=helper(s,k+1,j,1);
           int RF=helper(s,k+1,j,0);
           
           if(s[k]=='^')
           {
               if(isTrue==1)
               count+= LT*RF + LF*RT;
               else
               count+=LT*RT + LF*RF;
           }
           
           else if(s[k]=='&')
           {
               if(isTrue==1)
               count+= LT*RT;
               else 
               count+=LT*RF + LF*RT + LF*RF;
           }
           
           else
           {
               if(isTrue==1)
               count+= LT*RT + LT*RF + LF*RT;
               else
               count+= LF*RF;
           }
       }
       return count;
}
int countWays(string &s) {
        int n=s.length();
        int isTrue=1;
        return helper(s,0,n-1,isTrue);
}




Solution 2:

Steps-:
1)Using memo 

Code-:
int helper(int memo[2][101][101],string &s,int i,int j,int isTrue)
{
       if(i>j) return 0;
       if(i==j)
       {
           if(isTrue==1) 
           return (s[i]=='T');
           else
           return (s[i]=='F');
       }
       
       if(memo[isTrue][i][j]!=-1) return memo[isTrue][i][j];
       
       int count=0;
       for(int k=i+1;k<=j-1;k+=2)
       {
           int LT=helper(memo,s,i,k-1,1);
           int LF=helper(memo,s,i,k-1,0);
           int RT=helper(memo,s,k+1,j,1);
           int RF=helper(memo,s,k+1,j,0);
           
           if(s[k]=='^')
           {
               if(isTrue==1)
               count+= LT*RF + LF*RT;
               else
               count+=LT*RT + LF*RF;
           }
           
           else if(s[k]=='&')
           {
               if(isTrue==1)
               count+= LT*RT;
               else 
               count+=LT*RF + LF*RT + LF*RF;
           }
           
           else
           {
               if(isTrue==1)
               count+= LT*RT + LT*RF + LF*RT;
               else
               count+= LF*RF;
           }
       }
       return memo[isTrue][i][j]=count;
}
int countWays(string &s) {
        int n=s.length();
        int isTrue=1;
        int memo[2][101][101];
        memset(memo,-1,sizeof(memo));
        return helper(memo,s,0,n-1,isTrue);
}