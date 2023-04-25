### next permutation

#### using backtracking visited all possible order

vector<vecotr<int>> res;

```
IF possible order size === nums.size()
push condition 
ELSE
for loop nums and el of nums not in current list
current list push el
recursive backTracking(res, current list, nums)
current list pop_back
```
<< current list >>
|-----|-------|
1     2       3
|--|  |--|    |----|
2  3  1  3    1    2
|  |  |  |    |    |
3  2  3  1    2    1
