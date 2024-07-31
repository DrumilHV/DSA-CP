1.  find first and last occurance of a given number.
    - make two binary srach fn() first Occ and last Occ
    - do std binary serch, l<=r , but in first occ , when nums[mind]==target => ans = mid, end = mid-1;
    - do std binary serch, l<=r , but in last occ , when nums[mind]==target => ans = mid, start = mid+1;
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
```

Time Complextity: O(10^k \* M)\*(log N)
