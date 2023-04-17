## example : xxyabcyxx
> find longest common subseq

## Recursive Dynamic Programming

![](%E6%88%AA%E5%9C%96%202023-04-15%20%E4%B8%8B%E5%8D%887.30.27.png)

用left, right 去表達s 的start, end of last character 的subsequence <br>
```
s[0] = x, s[8] = x --> +2
s[1] = x, s[7] = x --> +2
s[2] = y, s[6] = y --> +2
s[3] = a, s[5] = c --> lps(s[3+1], s[5]), lps(s[3], s[5-1])
//////////
lps(s[3+1], s[5])
-> lps(s[3+1], s[5]) // b, c
-> lps(s[4+1], s[5]), lps(s[4], s[5-1]) // b return 1
//////////
lps(s[3], s[5-1])
// 到最後也是回傳到 left_side == right_side return 1
///////// 所以
s[4] = b, s[4] = b --> +1
total = 7

```

### Summary

    IF s[left_side] == s[right_side], perform answer = lps(left_side + 1, right_side - 1) + 2;
    ELSE perform answer = max(LPS(i, j - 1), LPS(i + 1, j);

### Algorithm

1. Create an integer variable n and initialize it to the size of s.
2. Create a 2D-array called memo having n rows and n columns where memo[i][j] contains the length of the longest palindromic subsequence of the substring formed from index i to j in s.
3. Return lps(s, 0, n - 1, memo) where lps is a recursive method with four parameters: s, the starting index of the substring under consideration as i, the ending index of the substring as j and memo. We perform the following in this method:

 * If memo[i][j] != 0, it indicates that we have already solved this subproblem, so we return memo[i][j].
 
 * If i > j, the string is empty. We return 0.

 * If i == j, it is a substring having one character. As a result, we return 1.

 * If the first and the last characters are the same, i.e., s[i] == s[j], we include these two characters in the palindromic subsequence and add it to the longest palindromic subsequence formed using the substring from index i + 1 to j - 1 (inclusive). We perform memo[i][j] = lps(s, i + 1, j - 1, memo) + 2.

 * Otherwise, if the first and the last characters do not match, we recursively search for the longest palindromic subsequence in both the substrings formed after ignoring the first and last characters. We pick the maximum of these two. We perform memo[i][j] = max(lps(s, i + 1, j, memo), lps(s, i, j - 1, memo)).
Return memo[i][j].


### Complexity Analysis
define n = s.length

最差的情況是沒有比對成功
Time O(n^2)
_____

## Iterative Dynamic Programming

### Intuition
> We used memoization in the preceding approach to store the answers to subproblems in order to solve a larger problem. We can also use a bottom-up approach to solve such problems without using recursion. We build answers to subproblems iteratively first, then use them to build answers to larger problems.
>
use mem store dp result
n = 9
i = 9, j = 10
i = 

### Example : 
```
n = 5
i = 4
i = 3, j = 4
i = 2, j = 3,4
i = 1, j = 2,3,4
i = 0, j = 1,2,3,4

    | b | b | b | a | b |
| b |
| b |
| b |
| a |       | 1 | 2 | 1 |
| b |           | 1 | 1 |

```

```
    | x | x | y | a | b | c | y | x | x |
| x |
| x |
| y |
| a |
| b |
| c |
| y |
| x |
| x |

```