class StockSpanner {
public:
    stack<pair<int,int>>st;
    int i=-1;
    StockSpanner() {
        
    }
    
    int next(int price) {
        i++;
        int res;
        if(st.empty())
        {
            st.push({i,price});
            return i+1;
        }
        else
        {
            while(!st.empty() and st.top().second<=price)
            {
                st.pop();
            }
            if(!st.empty())
            res=i-st.top().first;
            else
            res=i+1;
            st.push({i,price});
            return res;
        }
    }
};