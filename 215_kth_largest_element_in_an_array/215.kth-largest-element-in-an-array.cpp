/*
 * @lc app=leetcode id=215 lang=cpp
 *
 * [215] Kth Largest Element in an Array
 *
 * https://leetcode.com/problems/kth-largest-element-in-an-array/description/
 *
 * algorithms
 * Medium (65.71%)
 * Likes:    13316
 * Dislikes: 658
 * Total Accepted:    1.7M
 * Total Submissions: 2.6M
 * Testcase Example:  '[3,2,1,5,6,4]\n2'
 *
 * Given an integer array nums and an integer k, return the k^th largest
 * element in the array.
 * 
 * Note that it is the k^th largest element in the sorted order, not the k^th
 * distinct element.
 * 
 * You must solve it in O(n) time complexity.
 * 
 * 
 * Example 1:
 * Input: nums = [3,2,1,5,6,4], k = 2
 * Output: 5
 * Example 2:
 * Input: nums = [3,2,3,1,2,4,5,5,6], k = 4
 * Output: 4
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= k <= nums.length <= 10^5
 * -10^4 <= nums[i] <= 10^4
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        k = nums.size() - k;
        int lo = 0, hi = nums.size() - 1;

        while(lo < hi) {
            const int pivot = partition(nums, lo, hi);
            if(pivot < k)
                lo = pivot + 1;
            else if(pivot > k)
                hi = pivot - 1;
            else
                break;
        }

        return nums[k];
    }
private:
    int partition(vector<int> &nums, int lo, int hi) {
        int left = lo, right = hi + 1;

        while(true) {
            while(left < hi && less(nums[++left], nums[lo]));
            while(right > lo && less(nums[lo], nums[--right]));
            if(left >= right) break;
            swap(nums[left], nums[right]);
        }
        swap(nums[lo], nums[right]);
        return right;
    }

    bool less(int v, int w) {
        return v < w;
    }
};
// @lc code=end

