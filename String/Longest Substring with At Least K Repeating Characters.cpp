/*
Find the length of the longest substring T of a given string (consists of lowercase letters only) such that every character in T appears no less than k times.

Example 1:

Input:
s = "aaabb", k = 3

Output:
3

The longest substring is "aaa", as 'a' is repeated 3 times.
Example 2:

Input:
s = "ababbc", k = 2

Output:
5

The longest substring is "ababb", as 'a' is repeated 2 times and 'b' is repeated 3 times.
*/
class Solution
{
  public:
    int longestSubstring(string s, int k)
    {
        return helper(s, 0, s.size(), k);
    }

    int helper(string &s, int start, int end, int k)
    {
        if (end - start < k)
            return 0;
        int count[26];
        fill(&count[0], &count[25], 0);
        for (int i = start; i < end; i++)
        {
            count[s[i] - 'a']++;
        }
        for (int j = start; j < end; j++)
        {
            if (count[s[j] - 'a'] < k)
            {
                int left = helper(s, start, j, k);
                int right = helper(s, j + 1, end, k);
                return max(left, right);
            }
        }
        return end - start;
    }
};