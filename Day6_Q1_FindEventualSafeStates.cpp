class Solution {
public:

    bool detectCycle(int node, vector<vector<int>>& graph, vector<int>& vis, vector<int>& pathVis, vector<int>& check){
        vis[node] = 1;
        pathVis[node] = 1;

        for(auto it: graph[node]){
            if(!vis[it]){
                if(detectCycle(it, graph, vis, pathVis, check)) return true;
            }
            else if(pathVis[it]) return true; 
        }

        pathVis[node] = 0;
        check[node] = 1;
        return false;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> vis(n, 0), pathVis(n, 0), check(n,0), ans;

        for(int i=0; i<n; i++){
            if(!vis[i]){
                detectCycle(i, graph, vis, pathVis, check);
            }
        }

        for(int i=0; i<n; i++){
            if(check[i]) ans.push_back(i);
        }

        return ans;
    }
};