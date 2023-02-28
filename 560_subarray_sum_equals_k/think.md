## Think

> subarray 必須要連續index
> 用map 去管理prefix sum - k, value = 1
> k = nums[i] + nums[i+1] + ... + nums[j] | j < nums.size()
> 所以我們可以知道 => prefix sum + nums[j] = k => nums[j] = prefix sum - k
> 所以知道其實不需要去追蹤加總的index (Brute method) 只要單純紀錄之前的prefix sum 在去判斷當下nums[j] - k 是否有命中prefix 

nums = [1,2,3,4,5], k = 9

| prefix sum | label is equal k | is map key match prefix[j] - k |
|---|---| --- |
| 1 | 1 | |
| 3 | 1 | |
| 6 | 1 | |
| 10 | 1 | true |
| 15 | 1 | true |



```
So, suppose we have an array as arr[]: [1,2,3,4,5] and k = 9

so, our answer will be '2' i.e (2 + 3 + 4 and 4 + 5)
so if we store our prefix sum array then it should looks like:
index :   0, 1, 2, 3,  4
  arr[]: [1, 2, 3, 4,  5]
prefix[]:[1, 3, 6, 10, 15]
          ↑         ↑

How, we will find our subarray (2 + 3 + 4) using prefix sum, see-

1) if we see our prefix sum at index 3 then it is 10 and also prefix sum at index 0 is 1
so, we can say that from index 0 to 3 our prefix sum increases from 1 to 10, right,

1) So on putting a question, HOW MUCH ? means how much our sum increase from index 0 to index 3
then, we simply say, we find the difference between these two sums i.e (10 - 1) is the sum that increases from index 0 to 3.

1) If (10 - 1) sum increases from index 0 to 3, then we can say that, ok, this difference, should be the sum of elements greater than index 0, and upto index 3, i.e from index 1 to index 3,right.

2) Now, if we will see then we find out (10 - 1) is nothing but our 'k' that is 9.

3) So, we find out, that a subarray may also exist if this particular condition satisified, i.e
    (prefix[i] - k) should exist in our map, 
	
	How? see,
	
	If prefix[i] - prefix[j] = k where i > j (i, j any index, in our case they are i = 3, j = 0)
	prefix[i] - k = prefix[j] na, (simple maths)
	
	i.e if we are able to find (prefix[i] - k) is exist in our map, i.e prefix[j]
	so, we can say that from index j + 1 to i, the sum of the elements is k, right na,
	hence it proves that their exist an subarray from index j + 1 to i whose sum is k.
	
Now, for subarray (4 + 5) we again find this valid see -

index :   0, 1, 2, 3,  4
  arr[]: [1, 2, 3, 4,  5]
prefix[]:[1, 3, 6, 10, 15]
                ↑       ↑
				
1) if we see our prefix sum at index 4 then it is 15 and also prefix sum at index 2 is 6
so, we can say that from index 2 to 4 our prefix sum increases from 6 to 15, right,

2) So on putting a question, HOW MUCH ? means how much our sum increase from index 2 to index 4
then, we simply say, we find the difference between these two sums i.e (15 - 6) is the sum that increases from index 2 to 4.

3) If (15 - 6) sum increases from index 2 to 4, then we can say that, ok, this difference, should be the sum of elements greater than index 2, and upto index 4, i.e from index 3 to index 4,right.

4) Now, if we will see then we find out (15 - 6) is nothing but our 'k' that is 9.

5) So, we find out, that a subarray may also exist if this particular condition satisified, i.e
    (prefix[i] - k) should exist in our map, right na,
	
	How? see,
	
	If prefix[i] - prefix[j] = k where i > j (i, j any index, in our case they are i = 4, j = 2)
	prefix[i] - k = prefix[j] na, (simple maths)
	
	i.e if we are able to find (prefix[i] - k) is exist in our map, i.e prefix[j]
	so, we can say that from index j + 1 to i, the sum of the elements is k, right na,
	hence it proves that their exist an subarray from index j + 1 to i whose sum is k.
	
	I hope u got the reason now, why we will do (prefix[i] - k) in our code.

```