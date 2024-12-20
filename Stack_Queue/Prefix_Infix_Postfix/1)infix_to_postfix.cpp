https://www.geeksforgeeks.org/problems/infix-to-postfix-1587115620/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=infix-to-postfix

Steps-:

Case1-:
If current element is -> a-z || A-Z || 0-9
add it into our answer.

Case2-:
If its opening bracket.
add it into stack.

Case3-:
If its closing bracket.
add all the char from the stack till we reach the opening bracket.
pop the opening bracket too.

Case4-:
Means its a operand now.
now add all the char from the stack to answer if precdance of top>curr.

at the end add the curr into stack.



Case5-:
At last empty all the stack and add it into answer.


str="a+b*(c^d-e)"

i=0 , ch=a , ans="a"         st=[]
i=1 , ch=+ , ans="a"         st=[+]
i=2 , ch=b , ans="ab"        st=[+,*]
i=3 , ch=( , ans="ab"        st=[+,*,(]
i=4 , ch=c , ans="abc"       st=[+,*,(]
i=5 , ch=^ , ans="abc"       st=[+,*,(,^]
i=6 , ch=d , ans="abcd"      st=[+,*,(,^]
i=7 , ch=- , ans="abcd^"     st=[+,*,(,-]
i=8 , ch=e , ans="abcd^e"    st=[+,*,(,-]
i=9 , ch=) , ans="abcd^e-"   st=[+,*]

now empty the stack 
ans="abcd^e-*+"



Code-: Time->O(n)
int prec(char ch)
{
        if(ch=='^')
        return 3;
        else if(ch=='*' || ch=='/')
        return 2;
        else if(ch=='+' || ch=='-')
        return 1;
        else
        return -1;
}

string infixToPostfix(string s) {
        int n=s.length();
        string ans="";
        stack<char>st;
        
        for(int i=0;i<n;i++)
        {
            if((s[i]>='a' and s[i]<='z') || (s[i]>='A' and s[i]<='Z') || (s[i]>='0' and s[i]<='9'))
            ans+=s[i];
            else if(s[i]=='(')
            st.push(s[i]);
            else if(s[i]==')')
            {
                while(!st.empty() and st.top()!='(')
                {
                    ans+=st.top();
                    st.pop();
                }
                if(!st.empty())
                st.pop();
            }
            else
            {
                while(!st.empty() and (prec(st.top())>=prec(s[i])))
                {
                    ans+=st.top();
                    st.pop();
                }
                st.push(s[i]);
            }
        }
        
        while(!st.empty())
        {
            ans+=st.top();
            st.pop();
        }
        return ans;
}