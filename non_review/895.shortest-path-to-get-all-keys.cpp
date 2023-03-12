/*
 * @lc app=leetcode id=931 lang=cpp
 *
 * [895] Maximum Frequency Stack
 *
 * https://leetcode.com/problems/maximum-frequency-stack/description/
 *
 * algorithms
 * Hard (66.76%)
 * Likes:    4190
 * Dislikes: 64
 * Total Accepted:    147.6K
 * Total Submissions: 221.4K
 * Testcase Example:  '["FreqStack","push","push","push","push","push","push","pop","pop","pop","pop"]\n' +
  '[[],[5],[7],[5],[7],[4],[5],[],[],[],[]]'
 *
 * Design a stack-like data structure to push elements to the stack and pop the
 * most frequent element from the stack.
 * 
 * Implement the FreqStack class:
 * 
 * 
 * FreqStack() constructs an empty frequency stack.
 * void push(int val) pushes an integer val onto the top of the stack.
 * int pop() removes and returns the most frequent element in the
 * stack.
 * 
 * If there is a tie for the most frequent element, the element closest to the
 * stack's top is removed and returned.
 * 
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * Input
 * ["FreqStack", "push", "push", "push", "push", "push", "push", "pop", "pop",
 * "pop", "pop"]
 * [[], [5], [7], [5], [7], [4], [5], [], [], [], []]
 * Output
 * [null, null, null, null, null, null, null, 5, 7, 5, 4]
 * 
 * Explanation
 * FreqStack freqStack = new FreqStack();
 * freqStack.push(5); // The stack is [5]
 * freqStack.push(7); // The stack is [5,7]
 * freqStack.push(5); // The stack is [5,7,5]
 * freqStack.push(7); // The stack is [5,7,5,7]
 * freqStack.push(4); // The stack is [5,7,5,7,4]
 * freqStack.push(5); // The stack is [5,7,5,7,4,5]
 * freqStack.pop();   // return 5, as 5 is the most frequent. The stack becomes
 * [5,7,5,7,4].
 * freqStack.pop();   // return 7, as 5 and 7 is the most frequent, but 7 is
 * closest to the top. The stack becomes [5,7,5,4].
 * freqStack.pop();   // return 5, as 5 is the most frequent. The stack becomes
 * [5,7,4].
 * freqStack.pop();   // return 4, as 4, 5 and 7 is the most frequent, but 4 is
 * closest to the top. The stack becomes [5,7].
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 0 <= val <= 10^9
 * At most 2 * 10^4 calls will be made to push and pop.
 * It is guaranteed that there will be at least one element in the stack before
 * calling pop.
 * 
 * 
 */
/*
 * THINK : using map of stack and map to record val and freq
 * push most freq and element in value
 * [5], [7], [5], [7], [4], [5]
 * [{1, [5]}] and maxFreq = 1
 * ---------------------------
 * [{1, [5, 7]}] and maxFreq = 1
 * ---------------------------
 * [{1, [5, 7]}]
 * [{2, [5]}] and maxFreq = 2
 * ---------------------------
 * [{1, [5, 7]}]
 * [{2, [5, 7]}] and maxFreq = 2
 * ---------------------------
 * so final is:
 * [{1, [5, 7, 4]}]
 * [{2, [5, 7]}]
 * [{3, [5]}]
 * ---------------------------
 * pop is check freq map count most large and close last stack
 * 
*/
// @lc code=start

class FreqStack {
    unordered_map<int, stack<int>> freqSt;
    unordered_map<int, int> freq;
    int maxFreq = 0;
public:
    FreqStack() {
        
    }
    
    void push(int val) {
        maxFreq = max(maxFreq, ++freq[val]);
        freqSt[freq[val]].push(val);
    }
    
    int pop() {
        int closeFreqtop = freqSt[maxFreq].top();
        freqSt[maxFreq].pop();
        int updateFreq = freq[closeFreqtop] - 1;
        if (!freqSt[updateFreq].size()) maxFreq--;
        return closeFreqtop;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */
// @lc code=end

