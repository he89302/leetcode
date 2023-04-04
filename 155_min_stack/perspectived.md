#### record stack & min Val

> using two stack, one store normal stack other store min val
> so 
e.g. [-2, 0, -3]

stack minStack
if stack is empty push empty and determine min value
else 
    determine min vlaue and val
    and then push in stack and min stack

如果是pop() 的話兩個stack 都要處理
top() 的話就回傳stack top
getMin() 的話就回傳 minStack top()

缺點 ： 需要額外的space 來維護min value
但是應該不需要利用stack 去紀錄min value

#### using node stru to handle node min value and vale

去建立出node stru 一邊紀錄node value and min value
這樣最後一個node min value 就為top() node 記錄的min value

依樣push 進去時先決定min(value, stack.top()->minVal)
如果stack 為空 即直接new node(val, val) 加入stack 中

#### using node struc to maintain next node
> 在node struc 裡面添加next 就好
看是完整使用data struc 來解決
但是這邊我覺得是偏向min value 所以std::stack 可以做的事情就教不用額外做

