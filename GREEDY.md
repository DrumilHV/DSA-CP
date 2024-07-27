1. you are given an int arry, you are givn a number k , you have to find k numbers from the array such that diff b/w all of them is max .

- **Brute Force**
- sol: sort the numbers (O(N\*logN))
- now start with diff = 0, check if there are k numbers such that diff b/w atlease k no is >= 0
- now do for diff = 1 and check if atlease k no have diff >=1
- keep doing till you find a diff such that are no k numbers with diff >= k,
- Time complexity O(N\*limit + NlogN) => (N\*limit)
- **Optimal**
- do binary search on the diff, start with diff = 0, to arr[n-1]- arr[0](because you already sorted the arra).
- Time complexity => O(N\*log(limit)+N\*logN)

