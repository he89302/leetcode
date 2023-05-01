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

### using Uion find / Disjoint Subset Union

```
[[1,2],[1,3],[2,3]]
parent = [0,1,2,3]
Union(1,2)

1
|
2

Union(1,3)

1  1
|  |
2  3

Union(2,3)

if(find(2) == find(3)) return false

```

#### Union and Find with Path Compression
> 減少tree height
parent[x] = find(parent[x])

#### Union by size / rank
> 為了Union 兩個壓縮的子集
> 採取 union by size 技巧，將子節點比較少的 root 加入比較大的子集