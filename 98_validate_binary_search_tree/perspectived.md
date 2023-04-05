#### case 1 left fail

[5,1,7,2,3,6,9]

[5]
[1], [7]
[2,3], [6,9]

5 long_min, long_max

1, long_min, 5
2, long_min, 1 ==> root value >= right so return false

#### case 2 happy path

[2,1,3]

[2]
[1],[3]

2, long min, long max
1, long min, 2
3, 2, long max