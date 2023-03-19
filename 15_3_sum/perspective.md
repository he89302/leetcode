### using A + B + C = 0
#### although using two point shall make sure sort array
>  1. set A = -nums[i] and using two point to solved so shall decide left point and right point <br>

> 2. and can left = i+1 as B and right = size of nums - 1 as C
<br> so can determine nums[left] + nums[right] equal A <br>
if not comapre left++ or right-- <br>
if equal so collect in res <br>


> 3. decide next meet cell in nums 
until left > right <br>

> 4. Avoid nums element repeat so using while<br> to check next nums cell is still meet (left < right) AND  (not repeat last element) <br> (just last element because already sorted!!)
then can return res

