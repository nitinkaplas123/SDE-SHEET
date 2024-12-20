Solution 1-:
Steps-:
1)here we use 2 pointer approach.
2)as we know in question we can use atmost 2 bakset and any no. of fruits in it. so we use hashmap for it.
3)high index will add the value into hashmap and store the ans in variable.
4)if the size  of map ==3 which means we have to remove the 1 size with the help of low pointer.
5)same steps going on and store the ans.


Code-: Time->O(2*N) Space->O(3) or O(N)
int totalFruit(vector<int>& fruits) {
        int n=fruits.size();

        unordered_map<int,int>m;
        int low=0;
        int high=0;
        int ans=0;
        while(high<n)
        {
            m[fruits[high]]++;
            while(m.size()==3)
            {
                 m[fruits[low]]--;
                 if(m[fruits[low]]==0)
                 m.erase(fruits[low]);

                 low++;
            }
            
            ans=max(ans,high-low+1);
            high++;
        }
        return ans;
}