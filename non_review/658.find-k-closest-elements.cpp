/*
 * @lc app=leetcode id=658 lang=cpp
 *
 * [658] Find K Closest Elements
 *
 * https://leetcode.com/problems/find-k-closest-elements/description/
 *
 * algorithms
 * Medium (46.75%)
 * Likes:    6455
 * Dislikes: 525
 * Total Accepted:    401.9K
 * Total Submissions: 859.2K
 * Testcase Example:  '[1,2,3,4,5]\n4\n3'
 *
 * Given a sorted integer array arr, two integers k and x, return the k closest
 * integers to x in the array. The result should also be sorted in ascending
 * order.
 * 
 * An integer a is closer to x than an integer b if:
 * 
 * 
 * |a - x| < |b - x|, or
 * |a - x| == |b - x| and a < b
 * 
 * 
 * 
 * Example 1:
 * Input: arr = [1,2,3,4,5], k = 4, x = 3
 * Output: [1,2,3,4]
 * Example 2:
 * Input: arr = [1,2,3,4,5], k = 4, x = -1
 * Output: [1,2,3,4]
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= k <= arr.length
 * 1 <= arr.length <= 10^4
 * arr is sorted in ascending order.
 * -10^4 <= arr[i], x <= 10^4
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        // do binary search
        //Assume A[mid] ~ A[mid + k] is sliding window
        // case 1: x - A[mid] < A[mid + k] - x, need to move window go left
        // -------x----A[mid]-----------------A[mid + k]----------

        // case 2: x - A[mid] < A[mid + k] - x, need to move window go left again
        // -------A[mid]----x-----------------A[mid + k]----------

        // case 3: x - A[mid] > A[mid + k] - x, need to move window go right
        // -------A[mid]------------------x---A[mid + k]----------

        // case 4: x - A[mid] > A[mid + k] - x, need to move window go right
        // -------A[mid]---------------------A[mid + k]----x------
        int left = 0, right = arr.size() - k;

        while(left < right) {
            int mid = (left + right) / 2;
            if(x - arr[mid] > arr[mid + k] - x)
                left = mid + 1;
            else 
                right = mid;
        }
        
        return vector<int>(arr.begin() + left, arr.begin() + left + k);
    }
};
// @lc code=end

