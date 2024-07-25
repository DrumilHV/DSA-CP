1. find maximum subseq sum , such that no two elements are adjcent in the array.[HOUSE ROBBER-I](https://leetcode.com/problems/house-robber/description/)
   - sol: make a dp array,
   - dp[0] = max(0, arr[0]), dp[1] = max(dp[0], arr[1]);
   - for 2.....n
   - dp[i] = max(dp[i-1], dp[i-2] + arr[i])
   - return dp[n-1];
   - time: O(n), space: O(n)
2. [HOUSE ROBBER-II](https://leetcode.com/problems/house-robber-ii/description/)

- same as above but you must do it twice
  - once with index 0 to n-2,
  - once with index 1 to n-1,

```cpp
   dp1[0] = nums[0];
   dp1[1]=max(nums[0], nums[1]);
   dp2[0]=nums[1];
   dp2[1]=max(nums[1], nums[2]);
   for(int i=2; i<n; i++){
      dp1[i]=max(dp1[i-1], dp1[i-2]+nums[i]);
      dp2[i]=max(dp2[i-1], dp2[i-2]+nums[i+1]);
   }
   return max(dp1[n-1], dp2[n-1]);
```

3. given an number arr, return true if given there is stricly incresing sub sequence
   - eg , [ 18 5 4 3 2 1 8 10] => [3,8,10] ,[1, 8, 10]
   - BRUTE FORCE:
   - 3 for loops.
   - OPTIMIZED:
   - for every index find if right side has num > num[i] and left side has a num lesser than num[i]
   - time complexity : O(N^2);
   - **MOST OPTIMAL**
   - keep suffix max, and prefix min -> so you can compare max in O(1) for ever index,
   - time complexity: O(N);
4. Frog Jump: a frog can jump either 1 stone or 2 stones, the cost of jumping one stone (i to j) is abs(arr[i]-arr[j]), find the min cost for reaching the end.
   - make a dp arr, dp[0] = 0 (you are standing on it so cost = 0);
   - dp[1] = abs(arr[0]-arr[1]);
   - for 2 to n
   - dp[i] = min(abs(arr[i] - arr[i - 1]) + dp[i - 1], abs(arr[i] - arr[i - 2]) + dp[i - 2]);
   - return dp[n-1];
   - time: O(n), space: O(n);
5. **Frong Jump 2**: you can make a jump of k stones at once.
   - make a dp arr, dp[0] = 0
   ```cpp
    dp[0] = 0;
    for (int i = 1; i < n; i++){
        dp[i] = INT_MAX;
        for(int j = 1;j<=k;j++){
            if(i-j < 0 ) break;
            dp[i] = min(abs(jumps[i] - jumps[i - j]) + dp[i-j], dp[i]);
        }
    }
   ```
   - you just start from 1 , till k , dont handel cases manually, insted go for loop
   - make a max, and try to get the min out of it .
   - time: O(n\*k), space: O(n);
6. Maximum sum of two sub arrays. You can choose an index i from any one of the array but then you can't choose index i-1 from any of the arrays

Array 1(a1) : {1,5,3,21234}
Array 2(a2) : {-4509,200,3,40}
Answer:- (200+21234=21434)

- **First observe and make a dp array yourself**
  - dp[0] = 1
  - dp[1] = 200
  - dp[2] = 200
  - dp[3] = 21234+200
  - dp[3]=max(max(a1[3],a2[3])+dp[1],dp[2])

```cpp
for(i = 1;i<n;i++){
   dp[i] = max(max(a1[i], a2[i])+dp[i-2], dp[i-1]);
}
```

7. You have to taravell from city 1 to city N , you only have 2 flights to city i + 1 , i + 3, the cost is abs(arr[i]-arr[j]), find the min cost to reach city N (1 based indexing);

- do observtion ,and make dp array yourself.
- eg: [4, 12, 13, 18, 10, 12]
  - dp[1] = 0
  - dp[2] = abs(arr[1]-arr[2]);
  - dp[3] = abs(arr[2]-arr[3])+dp[2]
- for (int i = 4; i <= n; ++i) {
  dp[i] = min(abs(cost[i] - cost[i - 1]) + dp[i - 1], abs(cost[i] - cost[i - 3]) + dp[i - 3]);
