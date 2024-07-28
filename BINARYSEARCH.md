1. [koko eating banana](https://www.geeksforgeeks.org/problems/koko-eating-bananas/1?page=1&company=Uber&sortBy=submissions)

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
