/*
 * @lc app=leetcode id=647 lang=c
 *
 * [647] Palindromic Substrings
 */
// @lc code=start
int countSubstrings(char *s)
{

    int res = 0;
    

    // go trough every position in s
    for (int i = 0; s[i] != '\0'; i++)
    {
        // odd lengt palindromes
        int r = i;
        int l = i; // left and right position

        // loop for as long as r and al ar inbound and r anl are the same
        while (l >= 0 && s[r] != '\0' && s[r] == s[l])
        {
            res++;
            l--;
            r++;
        }

        // even lengt palindromes
        int l1 = i;
        int r1 = i + 1;

        // loop for as long as r and al ar inbound and r anl are the same
        while (l1 >= 0 && s[r1] != "\0" && s[r1] == s[l1])
        {
            res++;
            l1--;
            r1++;
        }
    }
    return res;
}
// @lc code=end
