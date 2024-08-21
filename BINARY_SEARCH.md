1.  find first and last occurance of a given number.

    - make two binary srach fn() first Occ and last Occ
    - while (Start <= end)
    - do std binary serch, l<=r , but in first occ , when nums[mind]==target => ans = mid, end = mid-1;

    ```cpp
    else if(target < nums[mid]){
    e = mid -1;

    }
    else if(target > nums[mid]){
        s = mid + 1;
    }
    ```

    - do std binary serch, l<=r , but in last occ , when nums[mind]==target => ans = mid, start = mid+1;(same as above for the last occ)
    - ans = -1 in both cases , return first and last occ .
    - time complexity log2(n) + log2(n) = 2\*O(log(n)) orr just O(log(n));
    - space complexity O(1);

2.  upper bound:

```cpp
int left = 0;
int right = arr.size() - 1;
    while (left <= right) {
        int mid = (left + right)/2 ;
        if (arr[mid] <= target) {
            left = mid + 1;
        } else {
            if(mid==0){
                return 0;
            }else{
                if(arr[mid-1]<=target){
                return mid ;
                }else{
                right = mid - 1 ;
                }
            }
        }
    }
    return left;
```

- lower bound:

```cpp
while(low<=high){
    long long mid = low + (high-low)/2;
    if(v[mid]<=x) {
        low = mid+1;
        ans = mid;
    }
    else{
        high = mid-1;
    }
}
return ans;
```

## using upper boud

```cpp
 vector<int>::iterator upper1, upper2;

    // std :: upper_bound
    upper1 = upper_bound(v.begin(), v.end(), 35);
    upper2 = upper_bound(v.begin(), v.end(), 45);

    cout << "\nupper_bound for element 35 is at position : "
         << (upper1 - v.begin());
    cout << "\nupper_bound for element 45 is at position : "
         << (upper2 - v.begin());
    int upper1 = upper_bound(arr, arr + 5, 35) - arr;
    int upper2 = upper_bound(arr, arr + 5, 45) - arr;

    cout << "\nupper_bound for element 35 is at position : "
         << (upper1);
    cout << "\nupper_bound for element 45 is at position : "
         << (upper2);
```

3. [koko eating banana](https://www.geeksforgeeks.org/problems/koko-eating-bananas/1?page=1&company=Uber&sortBy=submissions)

```cpp
bool check(int N, vector<int>& piles, int H, int mid){
    int count = 0;

    for(int i =0;i<N;i++){
        count+= ceil((double)piles[i]/(double)mid);
        }
    return count<=H;
}
int Solve(int N, vector<int>& piles, int H) {
    int end = 0;
    for(int i =0;i<N;i++){
        end = max(piles[i],end);
    }
    int start = 0;
    int mid = start + (end-start)/2;
    int ans = 0;
    while(start<=end){
        mid = start + (end-start)/2;
        if(check(N, piles, H, mid)){
            ans = mid;
            end = mid-1;
        }else{
            start = mid+1;
        }
    }
    return ans;
}
```

4. [Search in rotated sorted array](https://leetcode.com/problems/search-in-rotated-sorted-array/submissions/1125920246/)

```cpp
int start = 0;
int end = n-1;
while(start <= end){
    if(nums[mid]==target){
        return mid;
    }
    if(nums[mid] >= nums[start]){
        if(target >= nums[start] && target < nums[mid]){
            end = mid - 1;
        }else{
            start = mid + 1;
        }
    }else{
        if(target > nums[mid] && target <= nums[end]){
            start = mid + 1;
        }else{
            end = mid  -1;
        }
    }
    mid = start + (end-start)/2;
}
return -1;
```

5. [find single element in sorted array](https://leetcode.com/problems/single-element-in-a-sorted-array/description/)

- eg: [1,1,2,2,3,3,4,4,7,8, 8, 9, 9,10]
  - -->0,1,2,3,4,5,6,7,8,9,10,11,12,13 (index)
- look at index before single number comes
- idx 0 -> 7 (before single element) same number occuring even-odd respectively
- if mid -> odd check if(arr[mid]==arr[mid-1])
- if mid -> even check if(arr[mid]==arr[mid+1])
- if any of the two is true then you need to search right.
- else you need to search left.
- dont go mid-1 ,as mid itself can be the ans;

```cpp
int l=0,r=nums.size()-1;
while(l<r){
    int mid=(l+r)/2;
    if((mid%2 && nums[mid]==nums[mid-1])
    || (mid%2==0 && nums[mid]==nums[mid+1])){
        l=mid+1;
    }
    else r=mid;
}
//or
if((mid%2 && nums[mid]==nums[mid-1])|| (mid%2==0 && nums[mid]==nums[mid+1])) === if(arr[mid]==arr[mid^1]) //xor
//when mid->odd
mid = 7 //odd
0 1 1 1 //7 ------------> xor
0 0 0 1 //1 ----------|
-----------
0 1 1 0 //6
//when mid->even
mid = 8 //even
1 0 0 0 //7 ------------> xor
0 0 0 1 //1 ----------|
-----------
1 0 0 1 //9
```

5. find the N th root of a number.

```cpp
bool lessThanEqualTo(double a, int n, int m){ //Binary Exponetiation Time-Complexity : O(Log N)
    double res = 1;
    while(n>0){
        if(n%2==1){
            res *= a;
            n--;
        }else{
            n/=2;
            a *= a;
        }
    }
    return a<=m;
}
double findNthRoot(int n, int m){ //time Complexity : O(10^k * M)
    double l = 0, r = m;
    while(r-l > (1e-8)){
        double mid = (r+l)/2;
        if(lessThanEqualTo(mid,n,m )){
            l = mid;
        }else{
            r = mid;
        }
    }
    return l;
}
// Time Complextity: O(10^k * M)*(log N)

// or
int NthRoot(int n, int m) {
    //Use Binary search on the answer space:
    int low = 1, high = m;
    while (low <= high) {
        int mid = (low + high) / 2;
        int midN = func(mid, n, m);
        if (midN == 1) {
            return mid;
        }
        else if (midN == 0) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}
// O(logN),

```

- square Root till I'th decimal

```cpp
int start = 0, end = number;
    int mid;
    float ans;
    while (start <= end) {
        mid = (start + end) / 2;
        if (mid * mid == number) {
            ans = mid;
            break;
        }
        if (mid * mid < number) {
            start = mid + 1;
            ans = mid;
        }
        else {
            end = mid - 1;
        }
    }
    float increment = 0.1;
    for (int i = 0; i < precision; i++) {
        while (ans * ans <= number) {
            ans += increment;
        }
        ans = ans - increment;
        increment = increment / 10;
    }
    return ans;
```

6. [Median in a row-wise sorted Matrix](https://www.geeksforgeeks.org/problems/median-in-a-row-wise-sorted-matrix1527/1)

```
  [[1, 3, 5],
  [2, 6, 9],
  [3, 6, 9]]
  when in array form
  [1, 2, 3, 3, 5, 6, 6, 9, 9]
   0, 1, 2, 3, 4, 5, 6, 7, 8
   median  = 5 , idx = 4
```

- you check how many numbers are less than current mid
- if no of elements < total elements /2 then move back.
- if no of elements > total elements /2 then move forward.
- use upper boud in each row to find the number of elements less than mid in each row.

```cpp
int start = 0, end = (int)1e9;
int mid = start + (end-start)/2;
int median = 0;
int total =R*C;
int lessThanEqual = 0;
while(start<=end){
    mid = start + (end-start)/2;
    lessThanEqual = 0;
    for(int i =0;i<R;i++){
        int ub = upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
        lessThanEqual+=ub;
    }
    if(lessThanEqual > total/2){
        median = mid;
        end = mid-1;
    }else{
        start = mid+1;
    }
}
return median;
```

- time complexity: O(log(1e9) \* Rows \* log(col))
- log(1e9) search space
- Row\* log(Col) -> we find upper boud for each row for mid

7. [upper bound letters](https://leetcode.com/problems/find-smallest-letter-greater-than-target/);

```cpp
int start = 0;
int end   = letters.size()-1;
int mid   = start + (end-start)/2;
if(target>=letters[end]) return letters[0];
while(start<=end){
    mid   = start + (end-start)/2;
    if(letters[mid] <= target){
        start = mid+1;
    }else{
        end = mid - 1;
    }
}
return letters[start];
```

8. [Search Insert Position](https://leetcode.com/problems/search-insert-position/description/)

```cpp
int low=0;
int high=nums.size();
int mid;
if(target>nums[high-1]){
    return high;
}
while(low<=high){
        mid=(low+high)/2;
    if(nums[mid]==target){
        return mid;
    }

    if(target<nums[mid]){
    high=mid-1;
    }else{
    low=mid+1;
    }
}
    return  low;
```

9. [find in matrix](https://leetcode.com/problems/search-a-2d-matrix/submissions/1340474663/)

- https://drive.google.com/file/d/1fGRiD8iqkMK5fImiidjSQBhbpcLuYD8L/view

```cpp
int start = 0;
int row = matrix.size();
int col = matrix[0].size();
int end = row*col-1;
int currRow = 0;
int currCol = 0;
int mid = start + (end-start)/2;
while(start<= end){
    mid = start + (end-start)/2;
    currRow = mid / col;
    currCol = mid % col;
    if(matrix[currRow][currCol]==target){
        return true;
    }
    if(target< matrix[currRow][currCol]){
        end = mid-1;
    }else{
        start = mid + 1;
    }
}
return false;
```

10. [House robber - IV](https://leetcode.com/problems/house-robber-iv/)

```cpp
int start = 0, end= 1e9,ans= 1e9, mid = start + (end-start)/2;
int n = nums.size();

int count = 0;
while(start<=end){
    count = 0;
    mid = start + (end-start)/2;
    for(int i = 0;i<n;i++){
        if(nums[i]<=mid){
            count++;
            i++;
        }
    }
    if(count>=k){
        ans = min(ans, mid);
        end = mid -1;
    }else{
        start = mid +1;
    }
}
return ans;
```

11. AGRESSIVE COWS

```cpp
bool isPossible(vector<int>&stalls,int  m,int n,long long mid ){
    int cows = 1;
    int lastPos = stalls[0];
    for(int i=0;i<n;i++){
        if(stalls[i]-lastPos >= mid){
            cows++;
            if(cows == m ){
                return true;
            }
            lastPos = stalls[i];
        }
    }
    return false;
}
int max(long long int a , long long int b){
    return a > b ? a:b;
}
int solve(int n, int k, vector<int> &stalls) {
    sort(stalls.begin(),stalls.end());
    long long int start =0;
    long long int maxi=0;
    for(int i=0;i<n;i++){
        // sum+=stalls[i];
        maxi = max(maxi, stalls[i]);
    }
    long long int end = maxi;
    long long int ans = -1;
    long long int mid = start + (end-start)/2;
    // cout<<maxi<<" ";
    while (start<=end){
        // cout<<mid<<" ";
        if(isPossible(stalls, k,n, mid )){
            start = mid +1;
            ans = mid;
        }else{
            end = mid -1;
        }
        mid = start + (end-start)/2;
    }
    return ans;
    }
```

12. [Minimize the Maximum Difference of Pairs](https://leetcode.com/problems/minimize-the-maximum-difference-of-pairs/description/) Given an array, return the max diff b/w p pairs of numbers with least diff

- eg: Example 1:
  Input: nums = [10,1,2,7,1,3], p = 2
  Output: 1
  Explanation: The first pair is formed from the indices 1 and 4, and the second pair is formed from the indices 2 and 5.
  The maximum difference is max(|nums[1] - nums[4]|, |nums[2] - nums[5]|) = max(0, 1) = 1. Therefore, we return 1.
- sol:
  - sort() array.
  - start = 0, end = nums[n-1]-nums[0];
  - find mid, and then iterate orver the enitre array to check if there > p pairs of nums such that diff b/w them is more than mid.
  - make sure that pairs will be nums[i]-nums[i-1], and its better to have a flag, if you consider an i now , later you shold not cosider it.

```cpp
int check(vector<int>& nums, int p, int mid){
    int in = 0;
    int count = 0;
    int n = nums.size();
    for(int i =1;i<n;i++){
        if(in){
            in = 0;
            continue;
        }
        if(nums[i]-nums[i-1]<=mid){
            in = 1;
            count++;
        }
    }
    return count>= p;
    }
int minimizeMax(vector<int>& nums, int p) {
    sort(nums.begin(), nums.end());
    int start = 0;
    int n = nums.size();
    int end = nums[n-1]-nums[0];
    int mid = start + (end-start)/2;
    int ans = 0;
    while(start<=end){
        mid = start + (end-start)/2;
        if(check(nums, p, mid)){
            ans = mid;
            end = mid-1;
        }else{
            start = mid+1;
        }
    }
    return ans;
    }
```

13. given an array stocks where stocks[i] represent i th industry. the task is to distribut the stocks such a way that each portfoio has exactly k distinct type of stock where k is given . each stock is only included only once in each portfolio. Find the the max numbers of portfolio that can be created.

```cpp
boolean check(long g,long[]b,int k){
    long total=g*k;
    for(int i=1;i<b.length;i++)
    {
        if(b[i]>=g)
        {
            total=total-g;
        }
        else
        {
            total=total-b[i];
        }
    }
    if(total<=0) return true;
    return false;
}
void main (String[] args) {
    int n, k;
    cin>>n>>k;
    long sum=0;
    int i=1;
    long b[n+1];
    while(i<=n){
        cin>>b[i];
        i=i+1;
    }
    long lo=1;
    long hi=(long)1e9;
    long ans=0;
    while(lo<=hi){
        long mid=(lo+hi)/2;
        if(check(mid,b,k)==true)
        {
            ans=mid;
            lo=mid+1;
        }
        else hi=mid-1;
    }
	}
```
