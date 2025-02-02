int lcsUtil(string &s1, string &s2, int ind1, int ind2,
            vector<vector<int>> &dp) {
  // Base case: If either string reaches the end, return 0
  if (ind1 < 0 || ind2 < 0)
    return 0;

  // If the result for this pair of indices is already calculated, return it
  if (dp[ind1][ind2] != -1)
    return dp[ind1][ind2];

  // If the characters at the current indices match, increment the LCS length
  if (s1[ind1] == s2[ind2])
    return dp[ind1][ind2] = 1 + lcsUtil(s1, s2, ind1 - 1, ind2 - 1, dp);
  else
    // If the characters don't match, consider two options: moving either left
    // or up in the strings
    return dp[ind1][ind2] = max(lcsUtil(s1, s2, ind1, ind2 - 1, dp),
                                lcsUtil(s1, s2, ind1 - 1, ind2, dp));
}