class Solution {
public:
    bool dfs(int node, vector<vector<int>>& adj, vector<int>& vis,
             vector<int>& pathVis, stack<int>& st) {
        vis[node] = 1;
        pathVis[node] = 1;
        for (int neigh : adj[node]) {
            if (!vis[neigh]) {
                if (dfs(neigh, adj, vis, pathVis, st))
                    return true;
            }
            else if (pathVis[neigh]) {
                return true;
            }
        }
        pathVis[node] = 0;
        st.push(node);
        return false;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        // prereq -> course
        for (auto &p : prerequisites) {
            int course = p[0];
            int prereq = p[1];
            adj[prereq].push_back(course);
        }
        vector<int> vis(numCourses, 0);
        vector<int> pathVis(numCourses, 0);
        stack<int> st;
        for (int i = 0; i < numCourses; i++) {
            if (!vis[i]) {
                if (dfs(i, adj, vis, pathVis, st))
                    return {};
            }
        }
        vector<int> ans;
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};