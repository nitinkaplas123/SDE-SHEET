https://www.interviewbit.com/problems/nearest-smaller-element/

Steps-:
1)same idea as of next greater element.

Code-: Time->O(N) Space->O(N)
vector<int> Solution::prevSmaller(vector<int> &A) {
    int n=A.size();
    vector<int>v;
    stack<int>st;
    st.push(A[0]);
    v.push_back(-1);
    int i=1;
    while(i<n)
    {
        if(st.empty()==false and st.top()<A[i])
        {
            v.push_back(st.top());
            st.push(A[i]);
            i++;
        }
        else if(st.empty()==true)
        {
            v.push_back(-1);
            st.push(A[i]);
            i++;
        }
        else
        st.pop();
    }
    return v;
}