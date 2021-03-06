/*
207. Course Schedule

There are a total of n courses you have to take, labeled from 0 to n - 1.
Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]
Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?
For example:
2, [[1,0]]
There are a total of 2 courses to take. To take course 1 you should have finished course 0. So it is possible.
2, [[1,0],[0,1]]
There are a total of 2 courses to take. To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. So it is impossible.
click to show more hints.
Hints:
This problem is equivalent to finding if a cycle exists in a directed graph. If a cycle exists, no topological ordering exists and therefore it will be impossible to take all courses.
There are several ways to represent a graph. For example, the input prerequisites is a graph represented by a list of edges. Is this graph representation appropriate?
Topological Sort via DFS - A great video tutorial (21 minutes) on Coursera explaining the basic concepts of Topological Sort.
Topological sort could also be done via BFS.
*/

class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        int n = prerequisites.size();
        vector<int> inDegree(numCourses, 0);
        for(int i = 0; i < n; i++) {
            inDegree[prerequisites[i].first]++;
        }
        
        queue<int> q;
        for(int i = 0; i < numCourses; i++) {
            if(inDegree[i] == 0) {
                q.push(i);
            }
        }
        
        vector<int> res;
        while(!q.empty()) {
            int c = q.front();
            q.pop();
            res.push_back(c);
            for(int i = 0; i < n; i++) {
                if(prerequisites[i].second == c) {
                    inDegree[prerequisites[i].first]--;
                    if(inDegree[prerequisites[i].first] == 0) {
                        q.push(prerequisites[i].first);
                    }
                }
            }
        }
        
        return (res.size() == numCourses);
    }
};
