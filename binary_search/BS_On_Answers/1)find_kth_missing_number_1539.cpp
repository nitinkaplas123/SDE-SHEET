Solution 1-:
Steps-:
1)Add all the elements in set.
2)Now using count variable when count==k then we return val.


Time->O(N)
Space->O(N)

Code-:
int findKthPositive(vector<int>& arr, int k) {
        int n=arr.size();
        unordered_set<int>s;
        for(int i=0;i<n;i++)
        {
            s.insert(arr[i]);
        }

        int val=1;
        int count=0;
        while(1)
        {
            if(s.find(val)==s.end())
            {
              count++;
              if(count==k)
              return val;
            }
            val++;
        }
        return -1;
}


Solution 2-:
Steps-:

eg1. -:
[4,10,20]     k=2
4>k

meaning 4 is greater than k which means 1,2,3 is missing in left side of 4 so we can say that k is the missing number.

eg2.
[5,6,7] k=4
1)5>k means k is my answer which is 4.

eg.2 -:
[2,3,4,7,11]  k=5
1)i=0 -> 2<=k means 2 is present which means k++ -> k=6. now we make my missing number is 6.
2)i=1 -> 3<=k means 3 is present now make k++ ->    k=7.
3)i=2 -> 4<=k means 4 is present now make k++ ->    k=8.
4)i=3 -> 7<=k                                 ->    k=9.
5)i=4 -> return 9.

actual numbers -> [1,2,3,4,5,6,7,8,9,10]   



Time->O(N)
Space->O(1)
Code-:
int findKthPositive(vector<int>& arr, int k) {
        int n=arr.size();
        for(int i=0;i<n;i++)
        {
            if(arr[i]<=k)
            k++;
            else
            return k;
        }
        return k;
}



Solution 3-:
Steps-:
1)compare how many numbers missing with the help of diff of num[i]-i.


 0 1 2 3 4
[2,3,4,7,11]

1)low=0, high=4.
  mid=2.

   missing number from mid to left side is-:
   arr[mid]-(mid+1)
   4-(3)
   1.
  which is 1<k
  so 
  here we store the -:
  num=4.
  left_missing=1.
  go to right side.


2) low=3 high=4
   mid=3.

   arr[mid]-(mid+1)
   7-(4)
   3.
   which means in the left side we have 3 missing number.
   num=7
   left_missing=3
   go to right side -> low=mid+1.

3) low=4 high=4 
   mid=4.

   arr[mid]-(mid+1)
   11-(5)
   6.
   6>k 
   means our answer is on the left side of 11.
   high=mid-1.

Now loop break.
num=7 which is very close to our answer in the left side.
and at 7 we have 3 missing number.
we want k missing number 
so rest we go to right side.

right_missing= k-left_missing.
right_missing => 2.

now num=7 +2 -> 9 
which is our answer.


Time->O(log(n))
Space->O(1)
Code-:
int findKthPositive(vector<int>& arr, int k) {
        int n=arr.size();
        int low=0;
        int high=n-1;
        int left_missing=0;
        int num=0;
        int missing;
        while(low<=high)
        {
            int mid=(low+high)/2;
            missing=arr[mid]-(mid+1);
           
            if(missing<k)
            {
               num=arr[mid];
               left_missing=missing;
               low=mid+1;
            }
            else
            high=mid-1;
        }
        int go_to_right_side=k-left_missing;
        return num+go_to_right_side;
}