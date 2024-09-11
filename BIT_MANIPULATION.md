# BIT MANIPULATION

1. you are given an array , you need to make all of its subarray and do bitwise or on them and if the bitwise or is a part of the array then the array is compromised. find the no of array that are compromised. [link](https://docs.google.com/document/d/1byeONYse5njSQDFRCTVmXWEESky_m5FBjJjm99NjIzc/edit)

- sol : brute force.

```cpp
map<int, int> mp;
for(int i =0;i<n;i++){
    for(int j = i;j < n;j++){
        int or  = or | arr[j] ;
        if(mp.find(or)!=mp.end()){
            count++;
            break;
        }
        mp[or]++;
    }
}
```

### this is vaid only for no which are like 11110 ,or 110 , 10, 111111111110 , where all are 1 and last no is 0 in binary .

- easy version : all elemts are differnt.
- eg : [2, 6, 5, 7, 3, 8]
- fix one number (ie 7 ) and find all the subarrays who has this no: ( ie 7).
- the or this no is will be this number only if we or it with any no less than 7 ( ie , 0,1,2,3,4,5,6, ).
- any no grater than this no will or to the grater no (ie 8 | 7 = 8 , 9 | 7 = 9 ).
- now find all the arrar right of 7 which has no less than 7 .
- and also left limit.
- x is left len, y is right len => x\*y + x+y + 1

- find x and y for all no such that it has max or of this no in O(1) and do count += (x+1)(y+1) or x\*y+x+y+1

```
- eg: no in binray -> 1 1 1 1 0 1 1 1 1
                      0 1 2 3 4 5 6 7 8
                      weak point at index 0

```

- make 32 hash map of weak point such that hashmap[4] has recent where 4 th idx was 1 or make an arary of size 32
- make right lim and left lim, such that arr[i] = first time 0 is found on index i,

```cpp

typedef long long int ll;
int jth_bit(ll n, int j) {
    return (n >> j) & 1;
}
int main() {
    ll up[25]={0};
    ll n;ll c = 0 ;
    cin>>n;
    ll b[n+1]={0};ll mp[25];ll left_limit[n+1] = {0};ll right_limit[n+1]={0};unordered_map <ll,ll> g;
    for(ll i=1;i<=n;i++){
        cin>>b[i];right_limit[i] = n + 1 ;
    }
    for(ll i=0;i<=20;i++){
        mp[i] = n + 1 ;
    }
    ll i = n ;
    while(i>=1){
        ll y = n + 1 ;
        for(int j=0;j<=20;j++){
            ll d = jth_bit(b[i],j);
            if(d==0){
                y = min(y,mp[j]);
            }
            if(d==1){
                mp[j] = i ;
            }

            right_limit[i] = (y);
            if(g[b[i]]!=0){
                right_limit[i] = min(right_limit[i],g[b[i]]);
            }
        }
        g[b[i]] = i;i--;
    }
    i = 1 ;
    while(i<=n){
        ll y = 0 ;
        for(int j=0;j<=20;j++){
            ll d = jth_bit(b[i],j);
            if(d==0){
                y = max(y,up[j]);
            }
            if(d==1){
                up[j] = i ;
            }
            left_limit[i] = y;
        }
        i++;
    }
    for(ll i=1;i<=n;i++){
        ll x = left_limit[i];
        ll y = right_limit[i];cout<<i<<" "<<x<<" "<<y<<" ";
        ll x1 = abs(i-x)-1; ll y1 = abs(y-i)-1;
        c = c + x1 + y1 + x1*y1 + 1 ; cout<<x1<<" "<<y1<<"\n";
    }
    cout<<c;
    return 0;
}
```
