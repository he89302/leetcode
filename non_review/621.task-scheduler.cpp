/*
 * @lc app=leetcode id=621 lang=cpp
 *
 * [621] Task Scheduler
 *
 * https://leetcode.com/problems/task-scheduler/description/
 *
 * algorithms
 * Medium (55.70%)
 * Likes:    7658
 * Dislikes: 1508
 * Total Accepted:    394.1K
 * Total Submissions: 706.7K
 * Testcase Example:  '["A","A","A","B","B","B"]\n2'
 *
 * Given a characters array tasks, representing the tasks a CPU needs to do,
 * where each letter represents a different task. Tasks could be done in any
 * order. Each task is done in one unit of time. For each unit of time, the CPU
 * could complete either one task or just be idle.
 * 
 * However, there is a non-negative integer n that represents the cooldown
 * period between two same tasks (the same letter in the array), that is that
 * there must be at least n units of time between any two same tasks.
 * 
 * Return the least number of units of times that the CPU will take to finish
 * all the given tasks.
 * 
 * 
 * Example 1:
 * 
 * Input: tasks = ["A","A","A","B","B","B"], n = 2
 * Output: 8
 * Explanation: 
 * A -> B -> idle -> A -> B -> idle -> A -> B
 * There is at least 2 units of time between any two same tasks.
 * 
 * 
 * Example 2:
 * 
 * Input: tasks = ["A","A","A","B","B","B"], n = 0
 * Output: 6
 * Explanation: On this case any permutation of size 6 would work since n = 0.
 * ["A","A","A","B","B","B"]
 * ["A","B","A","B","A","B"]
 * ["B","B","B","A","A","A"]
 * ...
 * And so on.
 * 
 * n = 0 -> permutation (n+1) * maxslot(2)
 * 1 * 2
 * 
 * Example 3:
 * 
 * Input: tasks = ["A","A","A","A","A","A","B","C","D","E","F","G"], n = 2
 * Output: 16
 * Explanation: 
 * One possible solution is
 * A -> B -> C -> A -> D -> E -> A -> F -> G -> A -> idle -> idle -> A -> idle
 * -> idle -> A
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= task.length <= 10^4
 * tasks[i] is upper-case English letter.
 * The integer n is in the range [0, 100].
 * 
 * [A : 6]
 * [B : 1]
 * [C : 1]
 * [D : 1]
 * [E : 1]
 * [F : 1]
 * [G : 1]
 * 
 * size = 12
 * 
 * cpu = 6
 * n = 2
 * 
 * ans = (cpu - 1) * (n + 1) => 5 * 3 = 15
 * A B C A D E A F G A idle idle A idle idle A
 * 
 * need required space = (cpu - 1) * (n + 1) = 15
 */

// @lc code=start
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> record;
        int cpu = 0;

        for(auto e : tasks) {
            record[e]++;
            cpu = max(cpu, record[e]);
        }

        int ans = (cpu - 1) * (n + 1);
        for(auto e : record) {
            if(e.second == cpu)
                ans++;
        }

        return ans > tasks.size() ? ans : tasks.size();
    }
};
// @lc code=end

