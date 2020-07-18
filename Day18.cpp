/* QUESTION: There are a total of n courses you have to take, labeled from 0 to n-1.

Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]

Given the total number of courses and a list of prerequisite pairs, return the ordering of courses you should take to finish all courses.

There may be multiple correct orders, you just need to return one of them. If it is impossible to finish all courses, return an empty array.

Example 1:

Input: 2, [[1,0]] 
Output: [0,1]
Explanation: There are a total of 2 courses to take. To take course 1 you should have finished   
             course 0. So the correct course order is [0,1] .
Example 2:

Input: 4, [[1,0],[2,0],[3,1],[3,2]]
Output: [0,1,2,3] or [0,2,1,3]
Explanation: There are a total of 4 courses to take. To take course 3 you should have finished both     
             courses 1 and 2. Both courses 1 and 2 should be taken after you finished course 0. 
             So one correct course order is [0,1,2,3]. Another correct ordering is [0,2,1,3] .
*/

class Solution {
public:
    //TopoLogical Sort using BFS
    //if the size of ans is not n(no. od vertices) then ans must contain cycles
    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(n,vector<int>());
        queue<int> q;
        vector<int> in_degree(n,0);
        vector<int> ans;
        //Making graph, edge is unidirictional(p[1] --> p[0]) 
        for(auto p: prerequisites) {
            graph[p[1]].push_back(p[0]);
            ++in_degree[p[0]];
        }
        //Push all the elements in the queue which has 0 in_degree
        for(int i=0;i<n;++i) {
            if(in_degree[i]==0) {
                q.push(i);
            }
        }
        //if we remove the parent of a node then its in_degree will decreases by 1 unit
        while(!q.empty()) {
            int cur=q.front();
            q.pop();
            ans.push_back(cur);
            for(int child: graph[cur]) {
                --in_degree[child];
                if(in_degree[child]==0) {
                    q.push(child);
                }
            }
        }
        return ans.size() == n ? ans : vector<int>();
    }
};
