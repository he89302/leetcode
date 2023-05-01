### using DFS
確認有沒有cycle

```
graph[E[0]].push_back(E[1]), graph[E[1]].push_back(E[0]);

edge = {[1,2], [1,3], [2,3]}

visited = [false,false,false,false]

iterator 1:
graph = [[0,0,0,0,0],
         [0,0,2,0,0],
         [0,1,0,0,0],
         [0,0,0,0,0]]
E = [1,2]
dfs(E[0]) => dfs(1)

[1->2] visited [false, true, true, true]

iterator 2:
graph = [[0,0,0,0,0],
         [0,0,2,3,0],
         [0,1,0,0,0],
         [0,1,0,0,0]]
E = [1,3]
dfs(E[0])

[1->1->3] visited [false, true, true, true]

iterator 3:
graph = [[0,0,0,0,],
         [0,0,2,3,],
         [0,1,3,0,],
         [0,1,0,2,]]
E = [2,3]

dfs(E(0))

cur : 2 par = -1 graph[2] = [1,3]
 > choose 1
cur : 1 par = 2 graph[1] = [2,3]
 > choose 3 because parent shell not equal current node
cur : 3 par = 1 graph[3] = [1,2]
 > choose 2 because parent shell not equal current node
cur : 2 par = 3 and visited[2] == true so return cycleu is found!!

---

curr : 1 par : -1
curr : 2 par : 1

curr : 1 par : -1
curr : 2 par : 1
curr : 3 par : 1

curr : 2 par : -1
curr : 1 par : 2
curr : 3 par : 1
curr : 2 par : 3
```