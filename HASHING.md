1. find the equal array elements with k distance or less,

- eg: [1,2,3,1,3,2] , k = 2, ans = 3

- sol:
  - make a hashmap, store the last frequency of all elements
  - check if the curr idx - map[arr[i]] <= k return k
  - update map[arr[i]] = i;

2. TWO sum: find the elements in array such that arr[i]+arr[j] == k and i < j;

- sol:
  - make a hashmap, > as you insert elements keep start seeing if k - arr[i] <span style="color:red"> before this element </span>, exists in hashmap or not , if not then add map[arr[i]]++
  - if you find the complementary element then <span style="color:green"> add its frquency to the possible soln.</span>

3. find the elements such that abs(arr[i]-arr[j])==k

   - make a hash map
   - add elements in it , find if you find
     ans+= (arr[j]+k) + (arr[j]-k) <span style="color:red"> [BECAUSE ABS(ARR[I]-ARR[J])==K => ARR[I]-ARR[J]==K || ARR[J]-ARR[I]==K => ARR[J]+K == ARR[I] || ARR[J]-K==ARR[I]]</span>

4. find the sum of all elements in a given array [l, r], where we have a list of a vectors<vector<int>> ranges,
   - sol: if we do a simple for loop for(i = l ; i<=r ;i++ ){//...}, it will take O(n\*q) as we have to do it for all ranges in the given query.
   - optimized: make a prefix array, when you get ranger [l,r], do total - prefix[l]-(total-prefix[r]) (or prefix [r]-prefix[l-1]);
5. count the number of subarrays with sum = k;
   - sol: make a hashmap, store the sum of all elements till that index, and check if the current sum -k has appeard even once then add it count to the ans.
   - record all the sums in the array and continue.
6. Largest Subarray sum with given sum k.
   - keep adding to prefix sum, in single var
   - add a prefix sum only once , if you find it second time , do not update it as we want longest sub arr, key : prefix sum , value: index
   - if prefix sum - k is in hashmap, the the length of the longest sub aray is idx - mp[k-prefixSum] + 1;
7. Same as above but shortest
   - always update the prefix sum index.
8. find the max Distance between same numbers.
   - sol: make a hashmap, store the index of the element only if it comes first time.
   - if you find the same element again, then check if the distance between the two is greater than maxD and update it.
