nums = [3,7,1,6]

# Intuition
> 根據規則：
> decrease nums[i] by 1 <br>
> increase nums[i - 1] by 1 <br>
> 所以 <br>
> nums[0] + nums[1] == nums[0] + 1 + nums[1] - 1

所以 nums[0] < nums[1] 將可以不斷重複operation 直到nums[0] > nums[1] <br>

最終nums 將會變成decrescent order

# Explation

 計算prefix sum and their average
 The average shall be lower bound of result
 and it's reachable lower bound by process in intuition, so this average is result.

 # Complexity

 time: O(n)
 space: O(1)