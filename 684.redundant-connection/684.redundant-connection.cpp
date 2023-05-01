/*
 * @lc app=leetcode id=684 lang=cpp
 *
 * [684] Redundant Connection
 *
 * https://leetcode.com/problems/redundant-connection/description/
 *
 * algorithms
 * Medium (62.19%)
 * Likes:    5186
 * Dislikes: 352
 * Total Accepted:    270.8K
 * Total Submissions: 434.9K
 * Testcase Example:  '[[1,2],[1,3],[2,3]]'
 *
 * In this problem, a tree is an undirected graph that is connected and has no
 * cycles.
 * 
 * You are given a graph that started as a tree with n nodes labeled from 1 to
 * n, with one additional edge added. The added edge has two different vertices
 * chosen from 1 to n, and was not an edge that already existed. The graph is
 * represented as an array edges of length n where edges[i] = [ai, bi]
 * indicates that there is an edge between nodes ai and bi in the graph.
 * 
 * Return an edge that can be removed so that the resulting graph is a tree of
 * n nodes. If there are multiple answers, return the answer that occurs last
 * in the input.
 * 
 * 
 * Example 1:
 * 
 * Input: edges = [[1,2],[1,3],[2,3]]
 * Output: [2,3]
 * 
 * 
 * Example 2:
 * 
 * Input: edges = [[1,2],[2,3],[3,4],[1,4],[1,5]]
 * Output: [1,4]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * n == edges.length
 * 3 <= n <= 1000
 * edges[i].length == 2
 * 1 <= ai < bi <= edges.length
 * ai != bi
 * There are no repeated edges.
 * The given graph is connected.
 * 
 * 
 */

// @lc code=start
// check whether cycle in edges
// using fast & slow algorithm

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<bool> visited(edges.size() + 1);
        vector<vector<int>> graph(edges.size() + 1);

        for(auto edge : edges) {
            graph[edge[1]].push_back(edge[0]);
            graph[edge[0]].push_back(edge[1]);
            fill(std::begin(visited), std::end(visited), false);
            if(!graph[edge[0]].empty() and !graph[edge[1]].empty() and dfs(graph, visited, edge[0])) return edge;
        }

        return {};
    }

    bool dfs(vector<vector<int>>& graph, vector<bool> &visited, int cur, int par = -1) {
        cout << "curr : " << cur << " par : " << par << endl;
        
        if(visited[cur]) return true;
        visited[cur] = true;
        // cout << "\n";
        // for(int i = 0; i < visited.size(); i++) 
        //     cout << to_string(visited[i]);
        // cout << "\n";

        for(auto child : graph[cur]) {
            for(int i = 0; i < graph[cur].size(); i++)
                cout << graph[cur][i];
            cout << "\n";
            if(par != child and dfs(graph, visited, child, cur)) return true;
        }
        return false;
    }
};
// @lc code=end

