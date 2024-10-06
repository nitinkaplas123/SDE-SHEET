Solution 1-:
Steps-:
1)here we use 2 for loops

Code-: Time->O(n2) Space->O(1)
vector <int> calculateSpan(int price[], int n)
{
       vector<int>v;
       v.push_back(1);
       for(int i=1;i<n;i++)
       {
           int j;
           for(j=i-1;j>=0;j--)
           {
               if(price[j]>price[i])
               {
                   v.push_back(i-j);
                   break;
               }    
           }
           if(j==-1)
           v.push_back(i+1);
       }
       return v;
}


Solution 2-:
Steps-:
1)here we use stack to store index 
2)there are 3 cases-:
  1. if prev element<=curr element  then pop the index from stack.
  2. if stack is empty means all prev element is smaller than current so its range is [i+1] means current_index+1
  3. else means st.top()>curr element so (v.push_back(curr_index-st.top()))
     at every step we add index into stack/

Code-: Time->O(n) Space->O(N)
vector <int> calculateSpan(int price[], int n)
{
       vector<int>v;
       v.push_back(1);
       stack<int>st;
       st.push(0);
      
       for(int i=1;i<n;i++)
       {
           while(st.empty()==false and price[st.top()]<=price[i])
           {
               st.pop();
           }
           if(st.empty()==false)
           v.push_back(i-st.top());
           else
           v.push_back(i+1);
           
           st.push(i);
       }
       return v;
}
    