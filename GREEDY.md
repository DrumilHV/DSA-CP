1. you are given an int arry, you are givn a number k , you have to find k numbers from the array such that diff b/w all of them is max .

- **Brute Force**
- sol: sort the numbers (O(N\*logN))
- now start with diff = 0, check if there are k numbers such that diff b/w atlease k no is >= 0
- now do for diff = 1 and check if atlease k no have diff >=1
- keep doing till you find a diff such that are no k numbers with diff >= k,
- Time complexity O(N\*limit + NlogN) => (N\*limit)
- **Optimal**
- do binary search on the diff, start with diff = 0, to arr[n-1]- arr[0](because you already sorted the arra).
- Time complexity => O(N\*log(limit)+N\*logN)

2. [Vowels Game in a String](https://leetcode.com/problems/vowels-game-in-a-string/description/)

- alice starts first ,and removes odd no of vovels, bob plays second and removes even no of string, return if alice can win this game if both play optimally.
- sol: count the no of vovels , if vovels >=1 alice will always win.

3. You are given 2 sting of numbers "128272" , "5893092" , you can only swap same index of both string 3 rd pos of 1st string with 3rd pos of 2nd string, swap as many char as you can then return min diff b/w strings.

- Observation: NEVER SWAP ALL STRINGS, IT WILL BECOME THE SAME AGAIN.

2. You are given an array of integers nums of size 3. Return the maximum possible number whose binary representation can be formed by concatenating the binary representation of all elements in nums in some order.

- Note that the binary representation of any number does not contain leading zeros.

```
Example 1:
Input: nums = [1,2,3]
Output: 30
Explanation:
Concatenate the numbers in the order [3, 1, 2] to get the result "11110", which is the binary representation of 30.
```

- Sol :

Step-by-Step Explanation:

Initialize an empty string bits:

This string will hold the concatenated binary representations.
Iterate over each integer val in nums:

Convert val to a 32-bit binary representation:

```cpp
bitset<32> bit(val);
```

This creates a fixed-size binary representation of val.
Remove leading zeros from the binary representation:

Use a flag flag to indicate when the first '1' is encountered:

```cpp
bool flag = false;
```

Iterate from the most significant bit to the least significant bit:

```cpp
for(int i = 31; i >= 0; i--)
```

Update flag and append bits to bits:

```cpp
if(bit[i]) flag = true;
if(flag) bits += to_string(bit[i]);
```

Once the first '1' is found (flag becomes true), all subsequent bits (including zeros) are appended to bits.

```cpp
void Operation(vector<int>nums, int &ans)
{
    string bits;
    for(auto val:nums)
    {
        bitset<32>bit(val);
        bool flag = false;
        for(int i = 31; i >= 0; i--)
        {
            if(bit[i]) flag = true;
            if(flag) bits += to_string(bit[i]);
        }
    }
    ans = max(ans, stoi(bits, NULL, 2));
}
int maxGoodNumber(vector<int>& nums)
{
    int ans = 0;
    Operation(nums, ans);
    Operation({nums[0], nums[2], nums[1]}, ans);
    Operation({nums[1], nums[0], nums[2]}, ans);
    Operation({nums[1], nums[2], nums[0]}, ans);
    Operation({nums[2], nums[1], nums[0]}, ans);
    Operation({nums[2], nums[0], nums[1]}, ans);
    return ans;
}
```

OR to solve this classical problem of given strings , you need to concat it in such a way that it has max output. like question 2.

- sol:

```cpp
string binary(int n) {
    string res = "";
    while (n) {
        res += '0' + n % 2;
        n /= 2;
    }
    reverse(res.begin(), res.end());
    return res;
}

int decimal(string s) {
    int res = 0;
    for (int i = 0; i < s.length(); i++) {
        res = res * 2 + (s[i] - '0');
    }
    return res;
}

int maxGoodNumber(vector<int>& nums) {
    string a = binary(nums[0]), b = binary(nums[1]), c = binary(nums[2]);
    return max({
        decimal(a + b + c),
        decimal(a + c + b),
        decimal(b + a + c),
        decimal(b + c + a),
        decimal(c + a + b),
        decimal(c + b + a)
    });
    // or decimal(max({(a+b+c), ...})) both work;
}
```

2. Given a list of non-negative integers nums, arrange them such that they form the largest number and return it.

- Since the result may be very large, so you need to return a string instead of an integer.

```cpp
bool compareCustom(string a, string b){
    return (a+b> b+a)? true : false;
}
string largestNumber(vector<int>& nums) {
    vector <string> stringNums;
    for(int i=0;i<nums.size();i++){
        stringNums.push_back(to_string(nums[i]));
    }
    string result = "";
    sort(stringNums.begin(), stringNums.end(), compareCustom);
    for(int i=0;i<stringNums.size();i++){
        result += stringNums[i];
    }
    return result[0]=='0'?"0":result;
}
```
