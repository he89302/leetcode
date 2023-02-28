### think

> 使用backtracking；確定右括弧數量必大於左括弧；中止條件 = 剩餘的左右括弧數量為0
> 將partial res 加入result 

#### node = 1
<img src='https://g.gravizo.com/svg?
 digraph G {
   "1_(" -> "1_)" ;
 }
'/>

#### node = 2
<img src='https://g.gravizo.com/svg?
    digraph G {
        "1_(" -> "2_(" -> "1_)" -> "2_)" ;
        "1_(" -> "1_)" -> "2_(" -> "2_)" ;
    }
'/>

