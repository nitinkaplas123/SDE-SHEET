Solution 1-:
Steps-:
1)make all the strings which we can make by having * 
Case1-:
if s[index]=='*'
1. not included.
2. add "(".
3. add ")".

Case2-:
if(s[index]!='*')
add whatever value we have.


Time-> O(3^n*n) -> if the len is n then worst case we have whole string of * which means 3^n and at each string we are calling isValid.
     -> O(3^n*n)
Code-:
bool isValid(string &s) {
        int n=s.length();
        stack<char>st;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='(' || s[i]=='[' || s[i]=='{')
            st.push(s[i]);
            else
            {
                if(st.empty())
                return false;
                else if((st.top()=='(' and s[i]==')') || 
                        (st.top()=='[' and s[i]==']') ||
                        (st.top()=='{' and s[i]=='}'))
                st.pop();
                else
                return false;
            }
        }
        return (st.empty());
}
void helper(string &s,int index,int n,string str,bool &ans)
{
        if(index==n)
        {
           if(isValid(str))
           {
              ans=true;
           }
           return ;
        }
        
        if(s[index]!='*')
        helper(s,index+1,n,str+s[index],ans);
        else
        {
            helper(s,index+1,n,str,ans);
            helper(s,index+1,n,str+'(',ans);
            helper(s,index+1,n,str+')',ans);
        }
}
bool checkValidString(string s) {
        int n=s.length();

        int index=0;
        string str="";
        bool ans=false;
        helper(s,index,n,str,ans);
        return ans;
}




Solution 2-:

PreRequistes -:
If we have only () this type of brackets.
and someone ask we check its valid parathesis or not.

int count=0
Solution -:
1)if its opening bracket -> count++;
2)if its closing bracket -> count--;
3)at the end of loop if count==0 which means both cancel out each other which means its a valid parathesis.

Check this case -> ())(
1) count=1
2) count=0
3) count=-1   -> here if we return false beacuse its mismatch. 
4) count=0 

here if we see its shows me its valid parathesis. 
but its not.

Note -: if the middle of loop traversing if count<0 which means its invalid. return false immediately.



Steps-:
1)Here we make all possible strings and we are using count variable as well.
2) 
if (index==n)
{
    if(count==0) return true;
    else return false.

}
3) s[index]=='*'
Three cases -:
1. when s[index]='('
   count++;
2. when s[index]=')'
   count--;
3. else 
   count.

4)at any step if its return true then we will return true.


Time->O(3^n).
Code-:
bool helper(string &s,int index,int n,int count)
{
        if(index==n)
        {
           if(count==0) return true;
           return false;
        }
        if(count<0) return false;

        if(s[index]=='(')
        return helper(s,index+1,n,count+1);
        else if(s[index]==')')
        return helper(s,index+1,n,count-1);
        else
        {
           return (helper(s,index+1,n,count+1) || 
                   helper(s,index+1,n,count-1) || 
                   helper(s,index+1,n,count)
                   );
        }
}
bool checkValidString(string s) {
        int n=s.length();
        int count=0;
        return helper(s,0,n,count);
}




Solution 3-:
Steps-:
1)using memo 


Time->O(N^2)
Space->O(N^2)
Code-:
bool helper(int memo[101][101],string &s,int index,int n,int count)
{
        if(index==n)
        {
           if(count==0) return true;
           return false;
        }
        if(count<0) return false;

        if(memo[index][count]!=-1) return memo[index][count];

        if(s[index]=='(')
        return memo[index][count]=helper(memo,s,index+1,n,count+1);
        else if(s[index]==')')
        return memo[index][count]=helper(memo,s,index+1,n,count-1);
        else
        {
           return memo[index][count]=(helper(memo,s,index+1,n,count+1) || 
                   helper(memo,s,index+1,n,count-1) || 
                   helper(memo,s,index+1,n,count)
                   );
        }
}
bool checkValidString(string s) {
        int n=s.length();
        int count=0;
        int memo[101][101];
        memset(memo,-1,sizeof(memo));
        return helper(memo,s,0,n,count);
}



Solution 4-:
Steps-:
1)instead of count -> here we make range -> from mini to maxi.
mini=0,maxi=0
Case1-:
if(opening)
mini+=1
maxi+=1

Case2-:
if(closing)
mini-=1;
maxi-=1;

Case3-:
if(*)
three -> -1,0,+1

mini-=1;
maxi+=1;



1)
Now any point we check -> if mini is -ve we make it 
mini=0.

because remember the case of three recursive call. -> at any point if count<0 is negative we return false so that case.
similarly here we ignore that case 
that why if mini<0 
mini=0;

2)At any point if maxi<0 means return false. if cannot match it.
eg, 

]()

if start from closing which make my maxi=0 -> maxi->-1.
never ever we can make this a valid parathesis.


At the end of loop 
if mini==0 -> which means there is a case when its balanaced the string. 

return (mini==0).


Time->O(N)
Space->O(1)
Code-:
bool checkValidString(string s) {
        int n=s.length();
        int mini=0;
        int maxi=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='(')
            {
              mini=1+mini;
              maxi=1+maxi;
            }
            else if(s[i]==')')
            {
                mini-=1;
                maxi-=1;
            }
            else 
            {
                mini=mini-1;
                maxi=1+maxi;
            }
            if(mini<0) mini=0;
            if(maxi<0) return false;
        }
        return (mini==0);
}