Steps-:
Case1-:
1)If opening bracket add the index into stack.

Case2-:(Closing bracket)
1)if anything is there in stack obvious its opening and my current is closing then my current is cancel the opening in stack.
  so we pop the stack.
  Case1. 
  if anything there is in stack 
  so ans=max(ans,i-st.top());

  Case2 -:
  if stack is empty the index variable is helping me.
  ans=max(ans,i-index).


Time->O(N)
Space->O(N)
Code-:
int longestValidParentheses(string s) {
        int n=s.length();
        stack<int>st;
        int ans=0;
        int index=-1;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='(')
            st.push(i);
            else 
            {
                if(!st.empty())
                {
                    st.pop();
                    if(!st.empty())
                    ans=max(ans,i-st.top());
                    else
                    ans=max(ans,i-index);
                }
                else
                index=i;
            }
        }
        return ans;
}