// labuladong DFS 超时
class Solution {
public:
    vector<bool> onPath;
    vector<bool> visited;
    bool hasCycle = false;

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph = buildGraph(numCourses, prerequisites);
        onPath.resize(numCourses);
        visited.resize(numCourses);
        for (int i=0; i<numCourses; i++) {
            traverse(graph, i);
        }
        return !hasCycle;
    }

    void traverse(vector<vector<int>> graph, int s) {
        if (onPath[s]) hasCycle = true;
        if (visited[s] || hasCycle) return;
        visited[s] = true;
        onPath[s] = true;
        for (auto &t : graph[s]) {
            traverse(graph, t);
        }
        onPath[s] = false;
    }

    vector<vector<int>> buildGraph(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        for (int i=0; i<numCourses; i++) {
            graph[i] = vector<int>();
        }
        for (auto &edge : prerequisites) {
            int from = edge[1];
            int to = edge[0];
            graph[from].push_back(to);
        }
        return graph;
    }
};