Steps-:
1)make vector v of pair -> value,index.
2)sort the vector v. 
3)swap actual index with i if its not match. 
4)return count;

Code-:
int minSwaps(vector<int>& arr) {
    int n=arr.size();
    vector<pair<int,int>>v;
    for(int i=0;i<n;i++)
    {
            v.push_back({arr[i],i});
    }
    sort(v.begin(),v.end());
    int count=0;
        
    int i=0;
    while(i<n)
    {
        int index=v[i].second;
        int val=v[i].first;
        if(i!=index)
        {
          swap(v[i],v[index]);
          count++;
        }
        else
        i++;
    }
    return count;
}

Why can the number of swaps never exceed n?
Each cycle involves at most n-1 swaps because each cycle consists of elements that are misplaced, but once an element is placed correctly,
it doesn't participate in any further swaps.
In the worst case, every element might need to be moved around in a cycle, but this would still result in at most n-1 swaps, 
not n swaps or more.