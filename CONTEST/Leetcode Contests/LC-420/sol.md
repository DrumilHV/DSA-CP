### Q1.

/\*
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
\*/

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

### Q2

/\*
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
\*/

// Fol small constraints

````cpp
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
Time complexity : O(N)

````
