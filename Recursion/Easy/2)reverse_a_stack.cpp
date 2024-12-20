https://www.geeksforgeeks.org/problems/reverse-a-stack/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=reverse-a-stack

Solution 1-:
Steps-:
1)using extra stack 

Code-:
void Reverse(stack<int> &St){
        stack<int>st1;
        while(St.empty()==false)
        {
            int val=St.top();
            St.pop();
            st1.push(val);
        }
        St=st1;
}


Solution 2-:
Steps-:
1)Using recursion 

Code-: Time->O(N^2)
void insert_bottom(stack<int>&st,int x)
{
        if(st.empty()==true)
        {
            st.push(x);
            return ;
        }
        int val=st.top();
        st.pop();
        insert_bottom(st,x);
        st.push(val);
}
    
void helper(stack<int>&st)
{
        if(st.empty()==true)
        return ;
        
        int x=st.top();
        st.pop();
        
        helper(st);
        insert_bottom(st,x);
}
void Reverse(stack<int> &St){
       return helper(St);
}


