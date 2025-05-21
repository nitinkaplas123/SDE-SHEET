Question-:
case 1-:
1)asterids means if we have two number having same value but having different sign.
  means first number  ->  5
        second number -> -5 
  cancel each other.

case 2-:
1)asterids means if we have two number 
  means first number  ->  5
        second number -> -12
  then remove the smallest value from the array.
  ignore the sign value while comparing.
  means here -> 5 is the smallest so we have to delete the 5.

Steps-:
Case1-: +ve element
1)if current element is +ve add it into the stack.

Case2-: -ve element
   Case1-:
   1)if st.top element is +ve and current element>st.top() 
     it means st.top() element is smallest so we remove it from the stack.
   Case2-:
   1)if st.top()==current element 
     st.pop() the element (in this case we have to pop both the elements)
     
   Case3-:
       
       TestCase-:  [-5,-10,-15]
       Case1-:
       if this is the first element which we are traversing now.
       -: add it into the stack.
       Case2-:
       we know that current element is -ve 
       there may be chance st.top() element is also -ve.

       so in both the case we have to add the current element into the stack.

Code-:
vector<int> asteroidCollision(vector<int>& asteroids) {
        int n=asteroids.size();
        stack<int>st;

        for(int i=0;i<n;i++)
        {
            if(asteroids[i]>0)
            st.push(asteroids[i]);
            else
            {
                // stack element less than current element 
                while(!st.empty() and st.top()>0 and st.top()<abs(asteroids[i]))
                {
                    st.pop();
                }
                
                // both equal 
                if(!st.empty() and st.top()== abs(asteroids[i]))
                st.pop();
                else
                {
                    if(st.empty() || st.top()<0 )
                    st.push(asteroids[i]);
                }
            }
        }

        vector<int>ans;
        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }