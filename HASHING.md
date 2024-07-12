1. find the equal array elements with k distance or less,

- eg: [1,2,3,1,3,2] , k = 2, ans = 3

- sol:
  - make a hashmap, store the last frequency of all elements
  - check if the curr idx - map[arr[i]] <= k return k
  - update map[arr[i]] = i;
