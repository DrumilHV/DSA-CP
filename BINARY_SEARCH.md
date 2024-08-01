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
