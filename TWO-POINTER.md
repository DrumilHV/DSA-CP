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
3. [TWO-SUM](https://leetcode.com/problems/two-sum/)

- sort
- two pointers, one at begnning other at end.
- if sum is less than target, move left pointer to right
- if sum is greater than target, move right pointer to left

```cpp
vector<pair<int,int>> vec;
   int n = nums.size();
   for(int i = 0;i<nums.size();i++){
      vec.push_back({nums[i],i});
   }
   sort(vec.begin(),vec.end());
   int i = 0;
   int j = n-1;
   while(i<j){
      int sum = vec[i].first + vec[j].first;
      if(sum==target){
         return {vec[i].second,vec[j].second};
      }
      else if(sum<target){
         i++;
      }
      else{
         j--;
      }
   }
return {-1,-1};
```

3. Find the first and last Occurance of a number in given array.

- use binary search,
- first Occ: when arr[mid]==target, ans = mid, end = mid-1;
- last Occ: when arr[mid]==target, ans = mid, start = mid+1;

```cpp
int firstOcc(vector<int> nums, int target){
   int ans = -1;
   int e = nums.size()-1;
   int s = 0;
   int mid;
   while(s<=e){
      mid = s + (e-s)/2;
      if(target == nums[mid]){
         ans = mid;
         e = mid -1;
      }
      else if(target < nums[mid]){
         e = mid -1;
      }
      else if(target > nums[mid]){
         s = mid + 1;
      }
   }
   return ans;
}
int lastOcc(vector<int> nums, int target){
   int ans = -1;
   int e = nums.size()-1;
   int s = 0;
   int mid;
   while(s<=e){
      mid = s + (e-s)/2;
      if(target == nums[mid]){
         ans = mid;
         s = mid + 1;
      }
      else if(target < nums[mid]){
         e = mid -1;
      }
      else if(target > nums[mid]){
         s = mid + 1;
      }
   }
   return ans;
}
```
