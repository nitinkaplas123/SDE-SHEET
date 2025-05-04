Solution 1:

Steps:
1)Using 2 for loops.


Time Complexity: O(N^2)
Space Complexity: O(1)
Code:
int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        int n=dominoes.size();
        int count=0;
        for(int i=0;i<n;i++)
        {
            int a=dominoes[i][0];
            int b=dominoes[i][1];
            for(int j=i+1;j<n;j++)
            {
                int c=dominoes[j][0];
                int d=dominoes[j][1];
                if((a==c and b==d) or (a==d and b==c))
                count++;
            }
        }
        return count;
}


Solution 2:

Steps:
1)[1, 2] and [2, 1] both become 12
2)Count pairs as you go: each new matching domino forms count += previousCount

Time Complexity: O(N)
Space Complexity: O(N)
Code:
int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        int n=dominoes.size();
        unordered_map<int,int>m;
        int maxx=0;
        int count=0;
        for(int i=0;i<n;i++)
        {
            int mini=min(dominoes[i][0],dominoes[i][1]);
            int maxi=max(dominoes[i][0],dominoes[i][1]);
            int key=mini*10+maxi;
            count+=m[key];
            m[key]++;
        }
        return count;
}