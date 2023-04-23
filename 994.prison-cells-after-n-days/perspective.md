### Intution

#### using BFS

```
grid = [[2,1,1],[1,1,0],[0,1,1]]

count fresh = 6
rot orange = [0,0]
q[rot[0,0], ]

BFS dirs = {-1,0,1,0,-1}
if(in grid range and orange is fresh)
q.push(grid[i])
fresh --;

if fresh > 0 ==> still fresh orange
if ans == -1 not rot orange

```