Solution 1:
Steps:
1)Using stack.


Time ->O(N)
Space ->O(N)

Code:
int minLength(string s) 
{
        int n=s.length();
        stack<char>st;
        st.push(s[0]);
        int i=1;
        while(i<n)
        {
            if(!st.empty()  and ((s[i]=='B' and st.top()=='A') || (s[i]=='D' and st.top()=='C')))
            st.pop();
            else
            st.push(s[i]);
            i++;
        }
        return st.size();
}


Solution 2:

Steps:
1)Using simulation stack.  (imaginary stack)

Time ->O(N)
Space ->O(1)
Code:
int minLength(string s) {
        int j = 0;  // Acts as simulated stack top
        for (int i = 0; i < s.length(); ++i) 
        {
            if (j > 0 && ((s[i] == 'B' && s[j - 1] == 'A') || (s[i] == 'D' && s[j - 1] == 'C'))) 
            j--;  // Pop from simulated stack
            else 
            s[j++] = s[i];  // Push onto simulated stack
        }
        return j;
}