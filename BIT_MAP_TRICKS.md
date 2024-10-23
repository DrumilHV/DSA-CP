- bit operations are very very fast compared to % , \* , / operations
- sometimes 1e9 bit operations can run in 1 sec.

1. check if a number is odd or even

```cpp
9  -> 1001
10 -> 1010
do
9 & 1 -> 1 ==> odd no
10 & 1 -> 0 ==> even no
bit operations speed >> % operations speed
```

2. check if a number is power of 2

```cpp
x = pow of 2 => 00010000
only one 1 is there in entire number
x-1 = 00001111
if (x & (x-1)) == 00000000
x is pow of 2
return x && !(x & (x-1));
```

- - time complexity O(1);
  - special case this dont work when x == 0,

3. Check if k th bit (k th least significent bit is set of not 1 or not)

```cpp
x = 000001000
k = 3
x & (1 << k) == 000000000 -> k th bit was not set , if >0 then k th bit was set
```

- TOGGLE K th BIT

```cpp
x = 000001000
k = 3
x ^= (1 << k)
000001000 ^ 000001000 = 000000000
000001000 ^ 000010000 = 000011000
```

- SET K th BIT
