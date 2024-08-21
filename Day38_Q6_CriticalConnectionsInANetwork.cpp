class Solution {
public:

    void dfs(int node, int parent, vector<int> &tin, vector<int> &low, vector<int> &vis, vector<int> graph[], vector<vector<int>> &ans, int &time) {
        
        tin[node]=low[node]=time++;
        vis[node] = 1;
        
        for(auto it : graph[node]) {
            if(it == parent) continue; 
            
            if(!vis[it]) {
                dfs(it, node, tin, low, vis, graph, ans, time);
                low[node] = min(low[node], low[it]);
                
                if(low[it] > tin[node]) ans.push_back({node, it});
            }
            else low[node] = min(low[node], tin[it]);      
        }
    }

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {

        vector<int> tin(n, -1), low(n, -1), vis(n, 0);
        vector<vector<int>> ans;
        vector<int> graph[n];

        int time=0;
        
        for(auto it: connections) {
            graph[it[0]].push_back(it[1]);
            graph[it[1]].push_back(it[0]);
        }
        
        dfs(0, -1, tin, low, vis, graph, ans, time);
        return ans;
    }
};