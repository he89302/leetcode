### using sorting and array

```
// sort intervals
// 將interval 先按大小排序
// 比較的時候 先記錄left index = 0
// 如果沒有滿足overlay 的情況 就將interval push 進res 中 並且left index++
// Overlay 的情況 ： res[res index][1] >= interva[0]
// 決定res 當下的interval[1] = max(interval[1], intervals[left index][1])

intervals = [[1,3],[2,6],[8,10],[15,18]]

res = [[1,3]]
left index = 0
---
interval = [2,6]
res[leftindex][1] = 3 >= interval | [2,6] 所以interval[0] = 2 ===> res.back()[1] = max(res[left index][1], interval[1])
res = [[1,6]]

後續都沒有滿足overlay 的條件
所以res = [[1,6],[8,10],[15,18]]
```

