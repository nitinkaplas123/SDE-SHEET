https://www.geeksforgeeks.org/problems/sort-a-stack/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=sort-a-stack

Steps-:
1)first go to bottom when we left with 1 element using helper function. 
2)then using sorting function we sort one by one. 

Code-: Time->O(N^2)
void sorting(stack<int>&st,int x)
{
    if(st.size()==0 || st.top()<x)
    {
        st.push(x);
        return ;
    }
    
    int val=st.top();
    st.pop();
    sorting(st,x);
    st.push(val);
}
void helper(stack<int>&st)
{
    if(st.size()==0)
    return ;
    
    int x=st.top();
    st.pop();
    helper(st);
    sorting(st,x);
}
void SortedStack :: sort()
{
   return helper(s);
}