# Dynamic Programming

## Always start with dp[0] (if only 1 element in array ), dp[1] (if only 2 elements in array). **_NESSASECITY IS MOTHER OF INVESION, DONT MAKE CASES YOURSELF, GO WITH THE FLOW YOU WILL FIND OUT ALL THE REQ TEST CASES._**

1. [HOUSE ROBBER-I](https://leetcode.com/problems/house-robber/description/)
   find maximum subseq sum , such that no two elements are adjcent in the array.
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

## 2d DP

## • Whenever a move is making a problem for you , make a state for it

8. [Paint house](https://www.youtube.com/watch?v=-w67-4tnH5U). You are given a 3 houses and cost to color them with 3 colors , you can't color two adjcent houses with same color. For example, costs [0][0] is the cost of painting house e with the color red; costs [1][2] is the cost of painting house 1 with color green, and so on.. .Return the minimum cost to paint all houses.

- eg: Input: costs = [[17,2,17], [16,16,5], [14, 3,19]]

  - Output: 10
  - Explanation: Paint house 0 into blue, paint house 1 into green, paint house 2 into blue.
  - Minimum cost: 2 + 5 + 3 = 10.

- sol: make a 2d dp.

```cpp
int n = costs.size();
dp[0][0] = costs[0][0],
dp[0][1] = costs[0][1],
dp[0][2] = costs[0][2],
 for(int i =0;i<n;i++){
   dp[i][0] = costs[i][0] + min(dp[i-1][1], dp[i-1][2]);
   dp[i][1] = costs[i][1] + min(dp[i-1][0], dp[i-1][2]);
   dp[i][2] = costs[i][2] + min(dp[i-1][1], dp[i-1][0]);
}
return min({dp[n-1][0],dp[n-1][1],dp[n-1][2]})
```

9. [cVacation](https://atcoder.jp/contests/dp/tasks/dp_c) you have 3 activities , you cant do 2 same activities in on consicutive days, find the max happness in given days .

- eg:
  3 <br>
  10 40 70 <br>
  20 50 80 <br>
  30 60 90 <br>
  op: 210

- same as above

10. given a number find the min cost to convert it to 1, with follwoin condition

- the cost to reduce it by 1 is x,
- if divisible by 3 the cost is y,
- if divisible by 5 the cost is z,
- if divisible by 7 the cost is v,

- sol: (very easy)
  - make dp[N]
  - dp[1] = 0

```cpp
for(int i =0;i<=N;i++){
   int v1 = dp[N-1] + x;
   int v2 = N%3 ==0 ? dp[N/3] + y : INT_MAX;
   int v3 = N%5 ==0 ? dp[N/5] + Z : INT_MAX;
   int v2 = N%7 ==0 ? dp[N/7] + V : INT_MAX;
   dp[i] = min({v1,v2,v3,v4});
}
return dp[N];
```

11. you are given an array, when you visit an idx , you add it to the sum, you can go +2 or -1 and you can visit all idx only once. Find the min sum to go out of array .

- eg: [2,5,8], 2 ->8 -> 5 ->out

- SOL:
  - observations: you can not go back two times continously.
  - you can go forward 2 times continously.
  - move -1 is giving problem, so make a serperate state for it.
  - you can't, to index 1, or 2 from index 0 [one based indexing].
  - dp[i][2]=> forward state.
  - dp[i][1]=> backward state.
  - at end you have 3 possible ans,
    - dp[n][2] (forward state),
    - dp[n-1][2] (forward)
    - dp[n-1][1] (backward state),
  - backwards state is i-1 to i+1 to i so dp[i][backwards] = dp([i-1][backwards]+ b[i+1]) + b[i];
  - forward state is i-2 to i or backward state to i so dp[i][forward] = min(dp[i-2][forward], dp[i-2][backwards]);

```cpp
int my(int k,int r,int g){

    return min(k,max(r,g));
}


int main() {
    int n ;
    cin>>n ;
    int b[n+1] = {0};

    int i = 1 ;
    while(i<=n){
        cin>>b[i] ;
        i++;
    }

    int dp[n+1][5];

    dp[1][2] = b[1] ;
    dp[1][1] = 100000000 ;
    dp[2][2] = 100000000 ;
    dp[2][1] = dp[1][2] + b[2] + b[3] ;


    i = 3 ;
    while(i<=n-1){


        dp[i][2] = b[i] + min(dp[i-2][1],dp[i-2][2]);
        dp[i][1] = b[i] + b[i+1] + dp[i-1][2] ;

        i++;
    }
    dp[i][2] = b[n] + min(dp[i-2][2],dp[i-2][1]);
    dp[i][1] = 100000000 ;
    cout<<my(dp[n][2],dp[n-1][2],dp[n-1][1]);

```

12. you are given 2 array s B and C, you have to maximize the sum , but you can t take 3 consicuitive elemetns from the same array.

- Make 2 state for storing the elemets
- dp[i][1][1] - till i'th idx, we select first element from first array and one element from first array
- dp[i][1][2] - till i'th idx, we select first element frist array and 2'nd element from second array like

```
       i
[1,2,3,4]
[5,6,7,8]

dp[i][1][2]-> 4 + 7
dp[i][1][1]-> 4 + 8
dp[i][2][1]-> 8 + 3
```

```cpp
ll dp[100000+5][5][5];
int main() {
  //base-cases
  dp[1][1][1] = b[1] ;
  dp[1][1][2] = b[1] ;
  dp[1][2][1] = d[1] ;
  dp[1][2][2] = d[1] ;
  //dp[index][][]
  i = 2 ;
  while(i<=n){
    dp[i][1][1] = b[i] + b[i-1] + max(dp[i-2][2][2],dp[i-2][2][1]);
    dp[i][1][2] = b[i] + d[i-1] + mxi(dp[i-2][1][1],dp[i-2][1][2],dp[i-2][2][1]);
    dp[i][2][1] = d[i] + b[i-1] + mxi(dp[i-2][2][1],dp[i-2][2][2],dp[i-2][1][2]);
    dp[i][2][2] = d[i] + d[i-1] + max(dp[i-2][1][2],dp[i-2][1][1]);
    i++;
  }
  cout<<mx(dp[n][1][1],dp[n][1][2],dp[n][2][2],dp[n][2][1]);
```

13. Setphen is doing internship , he can hard task or easy task on a any day . he does hard task only if he has not done anything on prevous day. Hard task make more money.

- make 3 states easy , hard, noting .
- 1 - eays, 2- hard, 3 noting
- remember you do hard task only if you did noting pervous day => dp[i][2] = h[i] + dp[i-1][3] // for doing noting previous day.

```cpp
dp[1][1] = easy[1] ; //dp[][1]====easy
dp[1][2] = hard[1] ; //dp[][2]=====hrd
dp[1][3] = 0 ;
i = 2 ;
while(i<=n){
  dp[i][1] = easy[i] + max(dp[i-1][1],max(dp[i-1][2],dp[i-1][3]));
  dp[i][2] = hard[i] + dp[i-1][3] ; //did nothing on i-1 dy
  dp[i][3] = 0 + max(dp[i-1][1],max(dp[i-1][2],dp[i-1][3]));
  i++;
}
cout<<max(dp[n][1],max(dp[n][2],dp[n][3]));
```

# Partition DP

### General concept of solving PARTITION DP => DP[I] will tell total number of partition till i in the array

### fix the last part.

- EG: when you have an array how many ways to partition it ?
- DP[0] = 1
- size = 1, [1] => [1] 1 partition,
- size = 2, [1,2] => [1] | [2] ,[1,2], 2 partition
- size = 3, [1,2,3] => [1] | [2,3], [1,2] | [3],[1] | [2] | [3], [1,2,3] , 4 partition
- size = 4, [1,2,3,4] => we can start to generalize if we put
  - ...|... [4] => DP[3]
  - ...|... [3,4] => DP[2]
  - ...|... [2,3,4] => DP[1]
  - ...|... [1,2,3,4] => DP[0]
  - => DP[4] = DP[3] + DP[2] + DP[1] + DP[0];
  - **_dp[i] = dp[i-1] + dp[i-2] + ... + dp[0]_**

1. [Find the total number of ways to divide the array such that each part is good. Definition of good = depends on the question = sum of each part<=m; (Assuming all arrays elements>=0)](https://www.youtube.com/watch?v=o7i-IX8TKWI)

(question for next 4 sol: https://docs.google.com/document/d/1klrAqCSjHzMCGWLzmsXNHxeIc_b7OUXGOAwuYYz9tH0/edit)

- iterate through out the array
- then form j = i to 0 keep adding arr[i] to sum , if sum <=k, update dp[i] += dp[j-1] (because you keep i seperate and add dp[j-1] cus j = i);

```cpp
for (int i = 1; i <= n; i++) {
  int sum = 0;
  for (int j = i; j >= 1; j--) {
    sum += b[j];
    if (sum <= k) {
        dp[i] += dp[j - 1];
    } else {
        break;
    }
  }
}
```

2. Just tell true or false; tell true if it is possible to divide the array in a partition such that each part is good. [i…………….j] is good if and only if := b[i] = abs(i-j)

- eg: [4,2,8,1] -> bad because, there should be 4 numbers after 4 but only 3 are found.
- so make arr[0] = 3 , so 3 numbers after 3 will make it good.
- you check form i (any) to j (anything less than i), if i -> j good && dp[j-1] also good then dp[i] = true;
  [1...........j-1, j ,.....,i,..........n]
  now i to j good
  if(dp[j-1]) also good then arr [1 to i ] -> good
- now check this for all i , 1 to n
- return dp[n] if entire array is good.

```cpp
for(i=1;i<=n;i++){
  // dp[i] = return true such that it’s possible to divide the array into good parts.
  sum = 0
  for(j=i;j>=1;j--){ //last part is [j....i]
    if(b[j]==i-j){ //[j…..i] is good.
        if(dp[j-1]==true){//[1……j-1] is yummy
          dp[i]=true; //[1………i] is yummy
        }
    }
  }
}
return dp[n].
```

- **_Optimization 1_**: use a hash map to store <arr[j] + j, freq>,

  - if i exits in map then i -> j is valid.
  - then check if dp[j-1] is true or false
  - when you are at idx i, check if there exists any value in hashmap for i

- **_Optimization 2_**: use a hash map to store <arr[j] + j, dp[j-1]>,
  - when you are at idx i, check if there exists any value in hashmap for i (i = arr[j] + j (or) i-j = b[j])
  - **if i exists in hash map then j->i is valid.**
  - if so you can check, j -> i is valid and j-1 is valid or not.
- **_Optimization 3_**: start traversing from backwards.

  - dp[n+1] = true;
  - dp[n] = false (single element cant be true, cus even if [1], still you need someting like [1,2] for it to be true);
  - now start from behind n->1.
  - if(dp[i + arr[i] + 1]==true) -> i -> n == true && (dp[i + arr[i]+ _1_]) 0 -> i == true;

```cpp
  vector<bool> dp(n + 2, false); // dp array with size n+1 (using n+2 for dp[n+1] indexing)
  dp[n + 1] = true; // Base case

  for (int i = n; i >= 1; i--) {
    dp[i] = false;
    if (i + b[i] + 1 <= n + 1 && dp[i + b[i] + 1] == true) {
      dp[i] = true;
    }
  }
  if (dp[1]) {
      cout << "It is possible to divide the array into good parts." << endl;
  } else {
      cout << "It is not possible to divide the array into good parts." << endl;
  }
```

3. find the min moves to make the array harmounious. <br> Harmonious array is the one which has the exact number of elements follwoin it as on arr[i]. you can delete any number.

- eg: [1,8,3,4,7,6] => [1,8], [3,4,7,6] => one element after arr[0] (=1), 3 elements after arr[2] (=3)
- to make the array harmonious, you need to delete the min no of elements.
- for each array index you have to make arr[i] + i + 1 th index harmonious.
- or make delete this index and, try to find best possible ans dp[i+1];
- now you have to check the min no of moves required to make array harmonious.
  `dp[i] = min(1+dp[i+1],dp[i+b[i]+1]) `
  ```cpp
  vector<int> dp(n + 1);
  dp[n+1] = 0;
  dp[n] = 1;
  for(int i = n-1;i>=1;i++){
    if(i + b[i] + 1 <= n + 1){
      dp[i] = min(1+dp[i+1],dp[i+b[i]+1])
    }else{
      dp[i] = INT_MAX;
    }
  }
  ```
- but this is not the best possible ans.
- eg: [3,55,8,2,1] => according to the above logic, this will try to delete arr[arr[0] + 0 + 1] => arr[4] , but you can also delete 55 and the array can become good.
- you can delete 1 number and take dp[arr[i] + i + 1] => 0 + dp[arr[i] + i + 1] (1 offset because you are going for arr[i] + i + 1, so if you delete arr[i]+i+1 , you are not deleting anything, you just add dp[arr[i]+1] so 0+ dp[arr[i]+1])
- or you can delete 2 numbers next to arr[i] and take 2 extra from dp[arr[i] + i + 2 ]=> 1 + dp[arr[i] + i + 2] (here you delete number right next to arr[i] and to compensiate for 1 deleting you take 1 more while picking dp[arr[i] + i + 2])
- or you can delete 3 numbers next to arr[i] and take 3 extra from dp[arr[i] + i + 3 ]=> 2 + dp[arr[i] + i + 3 ] ((here you delete 2 numbers right next to arr[i] and to compensiate for 2 deleting you take 2 more while picking dp[arr[i] + i + 3]))
- and so onnn ....., so you take min of all .

```cpp
vector<int> dp(n + 2, 0);  // Array dp with 1-based indexing and size n+2 for edge cases

dp[n + 1] = 0;  // Initialize dp[n+1] = 0
dp[n] = 1;      // Initialize dp[n] = 1

for (int i = n - 1; i >= 1; i--) {
  int u = 1 + dp[i + 1];  // Case when you delete the ith element
  int l = b[i];
  int v = INT_MAX;
  int y = 0;
  for (int g = i + l + 1; g <= n + 1; g++) {
    v = min(v, y + dp[g]);
    y++;
  }

  dp[i] = min(u, v);  // dp[i] is the minimum of u and v
}
cout << "The result is: " << dp[1] << endl;
```

- the above is a O(n^2) sol , we need to make it an O(n) sol.

- [to make it O(n) sol](https://youtu.be/o7i-IX8TKWI?si=kqsLLQ3epuh7K_RF&t=5939)

```cpp
vector<int> dp(n + 11, 0);
vector<int> s(n + 11, 0);

dp[n + 1] = 0;

dp[n] = 1;
s[n] = dp[n];

for (int i = n - 1; i >= 1; i--) {
  int u = 1 + dp[i + 1];

  int l = b[i];
  int v = INT_MAX;
  if(i+l+1<=n+1){
  v = s[i + l + 1];
  }
  dp[i] = min(u, v);
  s[i] = min(dp[i], 1 + s[i + 1]);
}
cout << dp[1] << endl;
```
