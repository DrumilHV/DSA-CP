### Q1. [3324. Find the Sequence of Strings Appeared on the Screen](https://leetcode.com/problems/find-the-sequence-of-strings-appeared-on-the-screen/)

You are given a string target.

Alice is going to type target on her computer using a special keyboard that has only two keys:

Key 1 appends the character "a" to the string on the screen.
Key 2 changes the last character of the string on the screen to its next character in the English alphabet. For example, "c" changes to "d" and "z" changes to "a".
Note that initially there is an empty string "" on the screen, so she can only press key 1.

Return a list of all strings that appear on the screen as Alice types target, in the order they appear, using the minimum key presses.

Example 1:

Input: target = "abc"

Output: ["a","aa","ab","aba","abb","abc"]

Explanation:

The sequence of key presses done by Alice are:

Press key 1, and the string on the screen becomes "a".
Press key 1, and the string on the screen becomes "aa".
Press key 2, and the string on the screen becomes "ab".
Press key 1, and the string on the screen becomes "aba".
Press key 2, and the string on the screen becomes "abb".
Press key 2, and the string on the screen becomes "abc".
Example 2:

Input: target = "he"

Output: ["a","b","c","d","e","f","g","h","ha","hb","hc","hd","he"]

Constraints:

1 <= target.length <= 400
target consists only of lowercase English letters.

Note: Please do not copy the description during the contest to maintain the integrity of your submissions.

```cpp
vector<string> stringSequence(string target) {
    unordered_map<char, char> k2;
    for (char i = 'a'; i < 'z'; i++) {
        k2[i] = (char)(i + 1);
        // cout<<k2[i]<<" ";
    }
    k2['z'] = 'a';
    vector<string> ans;
    string st = "";
    // ans.push_back(st);
    int i = 0;
    while (i < target.size()) {
        st.push_back('a');
        ans.push_back(st);
        while (st[st.size() - 1] != target[i]) {
            st[st.size() - 1] = k2[st[st.size() - 1]];
            ans.push_back(st);
            // pr(ans);
        }
        i++;
    }
    return ans;
    }
```

### Q2 [3325. Count Substrings With K-Frequency Characters I](https://leetcode.com/problems/count-substrings-with-k-frequency-characters-i/)

Given a string s and an integer k, return the total number of
substrings of s where at least one character appears at least k times.

Example 1:

Input: s = "abacb", k = 2

Output: 4

Explanation:

The valid substrings are:

"aba" (character 'a' appears 2 times).
"abac" (character 'a' appears 2 times).
"abacb" (character 'a' appears 2 times).
"bacb" (character 'b' appears 2 times).
Example 2:

Input: s = "abcde", k = 1

Output: 15

Explanation:

All substrings are valid because every character appears at least once.

Constraints:

1 <= s.length <= 3000
1 <= k <= s.length
s consists only of lowercase English letters.

// Fol small constraints

```cpp
int numberOfSubstrings(string s, int k) {
    int ans = 0;
    int n = s.size();
    for (int i = 0; i < n; i++) {
        vector<int> chars(26, 0);
        for (int j = i; j < n; j++) {
            //finding a number from i....j -> trying all combos from i...n
            //in inner for loop.
            bool found = false;
            chars[s[j] - 'a']++;
            for (int l = 0; l < 26; l++) {
                if (chars[l] >= k) {
                    found = true;
                    break;
                }
            }
            //when suitable j is found it means all stirng from i...j,
            //and i to j to n are valid so add ans+=n-j.
            if (found) {
                ans += n - j;
                break;
            }
        }
    }
    return ans;
}
```

Time complexity : O(N*N*26)
// for large constraints

```cpp
int numberOfSubstrings(string s, int k) {
    int n=s.size();
    int cnt=0;
    int hash[26]={0};

    int l=0, r=0;

    while(r<n){
        hash[s[r]-'a']++;

        while(hash[s[r]-'a']>=k){
            cnt+=(n-r);

            hash[s[l]-'a']--;
            l++;
        }
        r++;
    }
    return cnt;
}
```

- Time complexity : O(N)

### Q3 [3326. Minimum Division Operations to Make Array Non Decreasing](https://leetcode.com/problems/minimum-division-operations-to-make-array-non-decreasing/description/)

You are given an integer array nums.
Any positive divisor of a natural number x that is strictly less than x is called a proper divisor of x.
For example, 2 is a proper divisor of 4, while 6 is not a proper divisor of 6.
You are allowed to perform an operation any number of times on nums, where in each operation you
select any one element from nums and divide it by its greatest proper divisor.

Return the minimum number of operations required to make the array non-decreasing.

If it is not possible to make the array non-decreasing using any number of operations, return -1.
Example 1:
Input: nums = [25,7]
Output: 1
Explanaton:
Using a single operation, 25 gets divided by 5 and nums becomes [5, 7].
Example 2:
Input: nums = [7,7,6]
Output: -1
Example 3:
Input: nums = [1,1,1,1]
Output: 0
Constraints:
1 <= nums.length <= 105
1 <= nums[i] <= 106

```cpp
int minOperations(vector<int>& nums) {
    int n = nums.size();
    int ans = 0;
    for (int i = n - 2; i >= 0; i--) {
        if (nums[i] > nums[i + 1]) {
            for (int j = 2; j * j <= nums[i]; j++) {
                if (nums[i] % j == 0) {
                    nums[i] = j;
                    ans++;
                    break;
                }
            }
            if (nums[i] > nums[i + 1])
                return -1;
        }
    }
    return ans;
}
```

- time complexity: O(N\*sqrt(N))

- Better complexity

```cpp
const int N = 1e6;
vector<int> gpd(N + 1);
bool init = false;
void initialize() {
    init = true;
    for (int i = 1; i <= N; i++) {
        for (int j = 2 * i; j <= N; j += i) {
            gpd[j] = i;
        }
    }
}
class Solution {
public:
    int minOperations(vector<int>& a) {
        if (!init) {
            initialize();
        }

        int n = a.size(), ops = 0;
        for (int i = n - 2; i >= 0; i--) {
            while (a[i] > a[i + 1]) {
                if (gpd[a[i]] == 1) {
                    return -1;
                }
                a[i] /= gpd[a[i]];
                ops++;
            }
        }
        return ops;
    }
};
```

### can be optimized to O(N) using modified steve of erethorsis

- time complexity: O(N\*log(N))

You are given a tree rooted at node 0, consisting of n nodes numbered from 0 to n - 1. The tree is represented by an array parent of size n, where parent[i] is the parent of node i. Since node 0 is the root, parent[0] == -1.

You are also given a string s of length n, where s[i] is the character assigned to node i.

Consider an empty string dfsStr, and define a recursive function dfs(int x) that takes a node x as a parameter and performs the following steps in order:

Iterate over each child y of x in increasing order of their numbers, and call dfs(y).
Add the character s[x] to the end of the string dfsStr.
Note that dfsStr is shared across all recursive calls of dfs.

You need to find a boolean array answer of size n, where for each index i from 0 to n - 1, you do the following:

Empty the string dfsStr and call dfs(i).
If the resulting string dfsStr is a
palindrome
, then set answer[i] to true. Otherwise, set answer[i] to false.
Return the array answer.

Example 1:

Input: parent = [-1,0,0,1,1,2], s = "aababa"

Output: [true,true,false,true,true,true]

Explanation:

Calling dfs(0) results in the string dfsStr = "abaaba", which is a palindrome.
Calling dfs(1) results in the string dfsStr = "aba", which is a palindrome.
Calling dfs(2) results in the string dfsStr = "ab", which is not a palindrome.
Calling dfs(3) results in the string dfsStr = "a", which is a palindrome.
Calling dfs(4) results in the string dfsStr = "b", which is a palindrome.
Calling dfs(5) results in the string dfsStr = "a", which is a palindrome.
Example 2:

Input: parent = [-1,0,0,0,0], s = "aabcb"

Output: [true,true,true,true,true]

Explanation:

Every call on dfs(x) results in a palindrome string.

Constraints:

n == parent.length == s.length
1 <= n <= 105
0 <= parent[i] <= n - 1 for all i >= 1.
parent[0] == -1
parent represents a valid tree.
s consists only of lowercase English letters.

- REQURE MANACHER'S ALGO

```cpp
vector<int> manacher(string s) {
  string t = "#";
  for (auto c : s) {
    t += c;
    t += '#';
  }
  int n = t.size();
  vector<int> r(n);
  for (int i = 0, j = 0; i < n; i++) {
    if (2 * j - i >= 0 && j + r[j] > i) r[i] = min(r[2 * j - i], j + r[j] - i);
    while (i - r[i] >= 0 && i + r[i] < n && t[i - r[i]] == t[i + r[i]])
      r[i] += 1;
    if (i + r[i] > j + r[j]) j = i;
    r[i]--;
  }
  return vector<int>(begin(r) + 1, end(r) - 1);
}

bool isPalindrome(int l, int r, vector<int> &v_manacher) {
  return v_manacher[l + r] >= r - l + 1;
}


void dfs(int u, vector<vector<int>> &adj, string &str, string &s, vector<int> &tin, vector<int> &tout) {
    tin[u] = str.size();
    for (int v : adj[u]) {
        dfs(v, adj, str, s, tin, tout);
    }
    tout[u] = str.size();
    str += s[u];
}

vector<bool> findAnswer(vector<int>& parent, string s) {
    int n = s.size();
    string str = "";
    vector<vector<int>> adj(n);
    for (int i = 1; i < n; i++) {
        adj[parent[i]].push_back(i);
    }
    vector<int> tin(n, -1), tout(n, -1);
    dfs(0, adj, str, s, tin, tout);

    vector<int> v_manacher = manacher(str);
    vector<bool> ans(n);

    for (int i = 0; i < n; i++) {
        ans[i] = isPalindrome(tin[i], tout[i], v_manacher);
    }

    return ans;
}
```
