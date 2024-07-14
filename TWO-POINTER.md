1. find the # sub array sum<=k.
   - make 2 pointers , i =0 , j = 0 and sum = 0;
   - keep moving j and adding sum+=arr[j];
   - while(sum>=k) {sum -= arr[i]; i++;}
   - count += (j-i+1);[because all elements are a sub array of its own, and when we j - i + 1 for all then the previous sub arrays are not counted in this only current are counted , provious ones were added when we previously did j - i + 1];
2. [Longest Continuous Subarray With Absolute Diff <= k](https://leetcode.com/problems/longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit/description/) (Same as find the find good sub arrays given length [l...r], array is good if diff b/w max and min in it is at most k)
   - <span style="color:red"> the min diff is the diff in a sub array is diff b/w max and min of sub arr and min</span>
   - make 2 pointers , i =0 , j = 0 and diff = 0
   - use multset to keep elements in sorted order;
   - do the usual tow pointer , while(j < n){ ... while (diff > k) { i++, }}
   - but here now add multiset
   - insert element in outer loop
   - if diff>k (remove m)
