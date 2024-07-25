1.  find first and last occurance of a given number.
    - make two binary srach fn() first Occ and last Occ
    - do std binary serch, l<=r , but in first occ , when nums[mind]==target => and = mid, end = mid-1;
    - do std binary serch, l<=r , but in last occ , when nums[mind]==target => and = mid, start = mid+1;
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
