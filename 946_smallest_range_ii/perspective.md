```
pushed : [1,2,3,4,5]
popped : [4,5,3,2,1]

stack push pushed 進去為 5, 4, 3, 2, 1
其中4,3,2,1 當下 就可以popedd 4
所以當push pushed[i] 進去後 檢查當下poped[j] == stack.top
如果成立 j++ stack.pop
終止條件 ： stack.empty && j == poped.size()