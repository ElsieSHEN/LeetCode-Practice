// 官方答案
class Solution {
public:
    vector<vector<int>> ans;
    vector<int> stk;

    void dfs(vector<vector<int>>& graph, int x, int n) {
        if (x == n) {
            ans.push_back(stk);
            return;
        }
        for (auto& y : graph[x]) {
            stk.push_back(y);
            dfs(graph, y, n);
            stk.pop_back();
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        stk.push_back(0);
        dfs(graph, 0, graph.size()-1);
        return ans;
    }
};


//labuladong版本
class Solution {
public:
    vector<vector<int>> ans;

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int> path;
        traverse(graph, 0, path);
        return ans;
    }

    void traverse(vector<vector<int>>& graph, int s, vector<int> path) {
        path.push_back(s);
        int n = graph.size();
        if (s == n - 1) {
            ans.push_back(path);
            path.pop_back();
            return;
        }

        for (auto& v : graph[s]) {
            traverse(graph, v, path);
        }

        path.pop_back();
    }
};

// graph[i] 存储i的所有邻居节点