/*
 * @lc app=leetcode id=310 lang=cpp
 *
 * [310] Minimum Height Trees
 *
 * https://leetcode.com/problems/minimum-height-trees/description/
 *
 * algorithms
 * Medium (38.52%)
 * Likes:    6201
 * Dislikes: 266
 * Total Accepted:    230.6K
 * Total Submissions: 598.5K
 * Testcase Example:  '4\n[[1,0],[1,2],[1,3]]'
 *
 * A tree is an undirected graph in which any two vertices are connected by
 * exactly one path. In other words, any connected graph without simple cycles
 * is a tree.
 * 
 * Given a tree of n nodes labelled from 0 to n - 1, and an array of n - 1
 * edges where edges[i] = [ai, bi] indicates that there is an undirected edge
 * between the two nodes ai and bi in the tree, you can choose any node of the
 * tree as the root. When you select a node x as the root, the result tree has
 * height h. Among all possible rooted trees, those with minimum height (i.e.
 * min(h))  are called minimum height trees (MHTs).
 * 
 * Return a list of all MHTs' root labels. You can return the answer in any
 * order.
 * 
 * The height of a rooted tree is the number of edges on the longest downward
 * path between the root and a leaf.
 * 
 * 
 * Example 1:
 * 
 * Input: n = 4, edges = [[1,0],[1,2],[1,3]]
 * Output: [1]
 * Explanation: As shown, the height of the tree is 1 when the root is the node
 * with label 1 which is the only MHT.
 * 
 * 
 * Example 2:
 * 
 * Input: n = 6, edges = [[3,0],[3,1],[3,2],[3,4],[5,4]]
 * Output: [3,4]
 * 
 * ### Step
 * 1.Create adjcent list(neighbors)
 * 2.Count in-degree of all vertices.
 * 3.Pick any vertex 'v' which has in-degree of 0.
 * 4.Print 'v'. Remove the vertex 'v' and all edges coming out of it. Decrement in-degrees of all neighbors of vertex 'v' by 1.
 * 5.Repeat steps 3 and 4 till u either have just 1 or 2 nodes available.
 * 
 * Constraints:
 * 
 * 
 * 1 <= n <= 2 * 10^4
 * edges.length == n - 1
 * 0 <= ai, bi < n
 * ai != bi
 * All the pairs (ai, bi) are distinct.
 * The given input is guaranteed to be a tree and there will be no repeated
 * edges.
 * 
 * 
 */

// @lc code=start
/*
 * Think : tupu 也就是BFS
 * 先將edges 做好整理 => 目的為整理出leaf : degree = 1 的node
 * 如此一來就可以從leaf 一路搜索到中間root node => root node 有機會為1 or 2
 * 因為有case 是會最後把兩個node 一併刪除
 * 
 * 
*/
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 0)
        {
            return {};
        } else if(n == 1) return {0};
        
        vector<vector<int>> adjList(n);
        vector<int> degree(n);
        queue<int> leaves;
        vector<int> res;

        for (auto edge : edges) {
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
            degree[edge[0]]++;
            degree[edge[1]]++;
        }

        for(int i = 0; i < n; i++) {
            if(degree[i] == 1)
                leaves.push(i);
        }

        while(!leaves.empty()) {
            res.clear();
            int size = leaves.size();
            for(int i = 0; i < size; i++) {
                int current = leaves.front(); leaves.pop();
                res.push_back(current);
                for(auto neighbor : adjList[current]) {
                    degree[neighbor]--;
                    if(degree[neighbor] == 1)
                        leaves.push(neighbor);
                }
            }
        }

        return res;
    }
};
// @lc code=end

