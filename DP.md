1. find maximum subseq sum , such that no two elements are adjcent in the array.
   - sol: make a dp array,
   - dp[0] = max(0, arr[0]), dp[1] = max(dp[0], arr[1]);
   - for 2.....n
   - dp[i] = max(dp[i-1], dp[i-2] + arr[i])
   - return dp[n-1];
   - time: O(n), space: O(n)
2. given an number arr, return true if given there is stricly incresing sub sequence
   - eg , [ 18 5 4 3 2 1 8 10] => [3,8,10] ,[1, 8, 10]
   - BRUTE FORCE:
   - 3 for loops.
   - OPTIMIZED:
   - for every index find if right side has num > num[i] and left side has a num lesser than num[i]
   - time complexity : O(N^2);
   - **MOST OPTIMAL**
   - keep suffix max, and prefix min -> so you can compare max in O(1) for ever index,
   - time complexity: O(N);
3. Frog Jump: a frog can jump either 1 stone or 2 stones, the cost of jumping one stone (i to j) is abs(arr[i]-arr[j]), find the min cost for reaching the end.
   - make a dp arr, dp[0] = 0 (you are standing on it so cost = 0);
   - dp[1] = abs(arr[0]-arr[1]);
   - for 2 to n
   - dp[i] = min(abs(arr[i] - arr[i - 1]) + dp[i - 1], abs(arr[i] - arr[i - 2]) + dp[i - 2]);
   - return dp[n-1];
   - time: O(n), space: O(n);
4. **Frong Jump 2**: you can make a jump of k stones at once.
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
