class Solution {
public:
    void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited,
             int &e, int &v) {

        visited[node] = true;
        v++;
        e += adj[node].size();

        for (int neigh : adj[node]) {
            if (!visited[neigh]) {
                dfs(neigh, adj, visited, e, v);
            }
        }
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {

        vector<vector<int>> adj(n);

        for (auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool> visited(n, false);
        int result = 0;

        for (int i = 0; i < n; i++) {

            if (visited[i]) continue;

            int e = 0;
            int v = 0;

            dfs(i, adj, visited, e, v);

            if (v * (v - 1) == e)
                result++;
        }

        return result;
    }
};