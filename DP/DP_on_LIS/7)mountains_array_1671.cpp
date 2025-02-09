Reference -> mik video
Task-:
1)find the min no. of removals to make array a mountains array -> first increasing then decreasing.
2)So if i find the maxx len of mountain array then return (n-max_len);
Steps-:
1)Find the max bitonic subsequence.
2) return n-maxx;  


Time->O(N^2)
Space->O(N)
Code-:
int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();

        vector<int> LIS(n, 1);
        vector<int> LDS(n, 1);

        for(int i = 0; i < n; i++) 
        {
            for(int j = i-1; j >= 0; j--) 
            {
                if(nums[i] > nums[j]) 
                LIS[i] = max(LIS[i], LIS[j] + 1);
            }
        }

        
        for(int i = n-1; i >= 0; i--) {
            for(int j = i+1; j < n; j++) {
                if(nums[i] > nums[j]) {
                    LDS[i] = max(LDS[i], LDS[j] + 1);
                }
            }
        }

        int maxx=1;
        for(int i = 0; i < n; i++) 
        { 
            if(LIS[i] > 1 && LDS[i] > 1)
            maxx=max(maxx,LIS[i]+LDS[i]-1);
        }
        return n-maxx;
}