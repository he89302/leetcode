## example : xxyabcyxx
> find longest common subseq

### Recursive Dynamic Programming

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

> DP
LCS: xxy & yxx
and concate all LCS --> xxyyxx shell be palidrome