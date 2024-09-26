Steps-:
1)Here g is the greed factor where we have n children ka greed factor which is g[i].
2) here s is the size of cookies.

Case1-:
we got the sizeof cookies which we want.
if s[j]>=g[i]  
{
    count++;
    i++;
    j++;
}

Case2-:
else go to bigger size of cookies.


int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());

        int count=0;
        int i=0;
        int j=0;
        int n=g.size();
        int m=s.size();
        while(i<n and j<m)
        {
            if(s[j]>=g[i])
            {
                count++;
                i++;
                j++;
            }
            else
            j++;
        }
        return count;
    }