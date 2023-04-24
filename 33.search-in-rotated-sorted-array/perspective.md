### Using binary search

```
Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4

left index = 0, right index = nums.size() = 7
nums[left_index] = 4, nums[right_index] = 2
(0+7)/2 = 3 ==> mid index
nums[3] = 7 > 4 
target = 0 < nums[lo] = 4 and nums[mid] > target
hi = mid - 1 = 2
nums[mid] >= target and nums[lo] > target so target is lower
lo = mid + 1 = 4;

else nums[mid] <= target and nums[hi] > target so target is mid right side
hi = mid - 1;

mid = mid - 1 = 2 ==> 

////// round 2.

(2+7)/2 = 4

nums[4] === target reutn 4



```