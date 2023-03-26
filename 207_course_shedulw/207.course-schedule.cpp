/*
 * @lc app=leetcode id=207 lang=cpp
 *
 * [207] Course Schedule
 *
 * https://leetcode.com/problems/course-schedule/description/
 *
 * algorithms
 * Medium (45.36%)
 * Likes:    11928
 * Dislikes: 464
 * Total Accepted:    1.1M
 * Total Submissions: 2.3M
 * Testcase Example:  '2\n[[1,0]]'
 *
 * There are a total of numCourses courses you have to take, labeled from 0 to
 * numCourses - 1. You are given an array prerequisites where prerequisites[i]
 * = [ai, bi] indicates that you must take course bi first if you want to take
 * course ai.
 * 
 * 
 * For example, the pair [0, 1], indicates that to take course 0 you have to
 * first take course 1.
 * 
 * 
 * Return true if you can finish all courses. Otherwise, return false.
 * 
 * 
 * Example 1:
 * 
 * Input: numCourses = 2, prerequisites = [[1,0]]
 * Output: true
 * Explanation: There are a total of 2 courses to take. 
 * To take course 1 you should have finished course 0. So it is possible.
 * 
 * 
 * Example 2:
 * 
 * Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
 * Output: false
 * Explanation: There are a total of 2 courses to take. 
 * To take course 1 you should have finished course 0, and to take course 0 you
 * should also have finished course 1. So it is impossible.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= numCourses <= 2000
 * 0 <= prerequisites.length <= 5000
 * prerequisites[i].length == 2
 * 0 <= ai, bi < numCourses
 * All the pairs prerequisites[i] are unique.
 * 
 * 
 */

// @lc code=start
class Solution {
    vector<vector<int>> adjList;
    vector<int> visited;
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        visited.resize(numCourses, 0);
        adjList.resize(numCourses);
        
        for(auto req : prerequisites) {
            adjList[req[1]].push_back(req[0]);
        }

        for(int i = 0; i < adjList.size(); i++) {
            for(int j = 0; j < adjList[i].size(); j++) {
                cout << "adj[" + to_string(i) + "][" + to_string(j) + "] = " + to_string(adjList[i][j]);
            }
            cout << "\n";
        }
        
        for(int currNode = 0; currNode < numCourses; currNode++) {
            if(dfs(currNode) == false) return false;
        }
        
        return true;
    }

private:
    bool dfs(int node) {
        if(visited[node] == 1) return true;
        
        visited[node] = 2;
        
        for(int next : adjList[node]) {
            if(visited[next] == 1) continue;
            if(visited[next] == 2) return false;
            if(dfs(next) == false) return false;
        }
        
        visited[node] = 1;
        return true;
    }
};
// @lc code=end

