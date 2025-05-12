Solution 1:

Steps:
1)For checking all subarrays.
Code:
long long countSubarrays(vector<int>& nums, int k) {
        long long count=0;
        int n=nums.size();
        
        for(int i=0;i<n;i++)
        {
            int num=nums[i];
            if(num==k)
            count++;
            for(int j=i+1;j<n;j++)
            {
                num=num&nums[j];
                if(num==k)
                count++;
            }
        }
        return count;
}


Prev map maximum size will be 32, in prev we have maxx of 32 keys.
Yes — exactly! That's what I mean. ✅

---

### 🔁 To be very clear:

In your loop:

```cpp
unordered_map<int, int> prev;
```

This `prev` map holds all **distinct AND values** of subarrays that **end at the previous index**.

Because of how **bitwise AND works**, the number of different values that can appear in `prev` is **limited**, and **typically doesn't grow with `n`**.

---

### ✅ Why only \~32 entries?

Let’s say all numbers in `nums` are regular 32-bit integers.

* Each time you do `a & b`, some bits may turn from `1` to `0`, but **none will turn from `0` to `1`**.
* So as you AND more numbers, the result gets "smaller" in terms of number of set bits.
* This limits how many unique AND results can appear when you're building all subarrays ending at `i`.

🧠 Think of it this way:

* You start with `nums[i]` (some value, say 29)
* Then you try:

  * `prev_val1 & nums[i]`
  * `prev_val2 & nums[i]`
  * ...
* All these results are **bitwise subsets** of the previous ones.

So the chain of ANDs can only produce a **bounded number of distinct results**, usually no more than the number of bits (i.e., **\~32** for 32-bit integers).

---

### 📌 Summary:

* ✅ Yes, `prev` will have **at most ≈ 32** keys at any point.
* So your loop:

  ```cpp
  for (auto x : prev)
  ```

  runs in **constant time in practice**, not `O(n)`.

That's why your algorithm runs in **`O(n * W)`**, where `W` is usually ≤ 32.

Would you like a short example showing how the number of keys in `prev` stays small?



Solution 2:

Steps:
1)By doing same checking all subarray but here we did optimisation.

[1,9,9,7,4]
     i 

At pointer i, 
we fill all the subarrays distinct key with its frequency using (i-1)th (store key,freq)

Dry run:

why 32 is the size of prev map 
Bcz:

suppose we have a number -> which is in the form of 0s & 1s.

and we are doing bitwise and 
which means we are converting 1->0

but we cannot do 0->1 
as its a bitwise and.

so in prev map max we have 32 distinct interger, so our size of prev map will be of 32.


Time Complexity: O(N*32)
Space Complexity: O(32)

Code:
long long countSubarrays(vector<int>& nums, int k) {
       long long count = 0;
       int n = nums.size();
       unordered_map<int, int> prev;
    
       for (int i = 0; i < n; i++) {
        unordered_map<int, int> curr;
        
        // Traverse through prev to compute the current subarray AND results
        for (auto& [key, freq] : prev) {
            int bitwise = key & nums[i];
            curr[bitwise] += freq;
        }
        
        // Include the current element as a subarray
        curr[nums[i]]++;

        // If k exists in current subarrays, add the count
        if (curr.find(k) != curr.end()) {
            count += curr[k];
        }

        // Swap curr and prev instead of copying
        swap(prev,curr);
    }
    return count;
}