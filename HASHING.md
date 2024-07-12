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
     exists then add ans+=
